#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de iteracoes (ptr)
// Devolve a matriz de adjacencias
float* read_file(char *filename, int *num_coins, float *coin_value)
{
	FILE *file;
	float *data;
	int i;
	file=fopen(filename, "r");
	if(!file)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	// Numero de moedas
	fscanf(file, " %d", num_coins);
	// valor a alcançar
	fscanf(file, " %f", coin_value);
	// Alocacao dinamica do vector
	data = malloc(sizeof(float)*(*num_coins));
	if(!data)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	
	for (i = 0; i < *num_coins; i++)
		fscanf(file, " %f", &data[i]);
	fclose(file);
	return data;
}

// Imprime a matrix lida do ficheiro.
void mostra_grafo(float *filedata, int *num_coins, float *coin_value)
{
	int i;

	// Numero de moedas
	printf("\n%d ", *num_coins);
	// valor a alcançar
	printf("%.2f\n", *coin_value);

	// mostra moedas
	for(i=0; i<*num_coins; i++){
		printf("%.2f ", *filedata++);
    }
    printf("\n");
}

void menu(char* filename){
	int op;
	do {
		printf("Escolha o grafo: ");
		printf("\n1 - grafo_teste.txt");
		printf("\n2 - grafo2.txt");
		//printf("\n3 - grafo?.txt");
		printf("\n0 - sair");
		printf("\nop: ");
		scanf("%d", &op);
	} while (op <= 0 || op >= 2);
	switch (op) {
	case 0:
		exit(1);
		break;
	case 1:
		strcpy(filename, "grafo_teste.txt");
		break;
	case 2:
		strcpy(filename, "grafo2.txt");
		break;
	}
}
// Gera a solucao inicial
// Parametros: solucao, numero de vertices
void gera_sol_inicial(int *sol, int v)
{
	int i, x;

	for(i=0; i<v; i++)
        sol[i]=0;
	for(i=0; i<v/2; i++)
    {
        do
			x = random_l_h(0, v-1);
        while(sol[x] != 0);
        sol[x]=1;
    }
}

// Escreve solucao
// Parametros: solucao e numero de vertices
void escreve_sol(int *sol, int vert)
{
	int i;

	printf("\nConjunto A: ");
	for(i=0; i<vert; i++)
		if(sol[i]==0)
			printf("%d  ", i);
	printf("\nConjunto B: ");
	for(i=0; i<vert; i++)
		if(sol[i]==1)
			printf("%d  ", i);
	printf("\n");
}

// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
}

// Inicializa o gerador de numeros aleatorios
void init_rand()
{
	srand((unsigned)time(NULL));
}

// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max-min+1);
}

// Devolve um valor real aleatorio do intervalo [0, 1]
float rand_01()
{
	return ((float)rand())/RAND_MAX;
}
