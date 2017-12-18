#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funcoes.h"
#include "utils.h"

// Inicializa o gerador de numeros aleatorios
void init_rand() {
	srand((unsigned)time(NULL));
}

// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max) {
	return min + rand() % (max - min + 1);
}

// Devolve um valor real aleatorio do intervalo [0, 1]
float rand_01() {
	return ((float)rand()) / RAND_MAX;
}

float* ler_ficheiro(char *nomeficheiro, int *num_moedas, float *valor_moeda){
	FILE *file;
	float *dados;
	int i;
	file=fopen(nomeficheiro, "r");
	if(!file)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}
	fscanf(file, " %d", num_moedas);
	fscanf(file, " %f", valor_moeda);
	dados = malloc(sizeof(float)*(*num_moedas));
	if(!dados)
	{
	    printf("Erro na alocacao de memoria\n");
	    exit(1);
	}
	for (i = 0; i < *num_moedas; i++)
		fscanf(file, " %f", &dados[i]);
	fclose(file);
	return dados;
}

void mostra_ficheiro(float *dados, int *num_moedas, float *valor_moeda){
	int i;
	printf("\nDados ficheiro:");
	printf("\n\tNumero de moedas: %d", *num_moedas);
	printf("\n\tValor a atingir: %.2f", *valor_moeda);
	printf("\n\tMoedas: ");
	for(i=0; i<*num_moedas; i++){
		printf("%.2f ", dados[i]);
    }
    printf("\n");
}

int* conta_moedas(float *dados, int *num_moedas){
int i;
	int *conta_moedas;
	conta_moedas = malloc(sizeof(float) * TOTAL_MOEDAS);
	if (!conta_moedas)
	{
		printf("Erro na alocacao de memoria\n");
		exit(1);
	}
	for (i = 0; i < TOTAL_MOEDAS; i++)
		conta_moedas[i] = 0;
	for (i = 0; i < *num_moedas; i++) {
		if (dados[i] == 0.01f) conta_moedas[0]++;
		if (dados[i] == 0.02f) conta_moedas[1]++;
		if (dados[i] == 0.05f) conta_moedas[2]++;
		if (dados[i] == 0.1f) conta_moedas[3]++;
		if (dados[i] == 0.2f) conta_moedas[4]++;
		if (dados[i] == 0.5f) conta_moedas[5]++;
		if (dados[i] == 1.0f) conta_moedas[6]++;
		if (dados[i] == 2.0f) conta_moedas[7]++;
	}
	return conta_moedas;
}

void mostra_moedas(int *dinheiro, int num_moedas){
	int i;
	printf("\nMoedas contadas: ");
	for (i = 0; i<num_moedas; i++) {
		printf("%d ", dinheiro[i]);
	}
	printf("\n");
}

void menu(char* nomeficheiro){
	int op;
	do{
		printf("Menu:\nEscolha o conjunto de moedas para testar: ");
		printf("\n1 - moedas1.txt");
		printf("\n2 - moedas2.txt");
		printf("\n3 - moedas3.txt");
		printf("\n9 - moedas_teste.txt");
		printf("\n0 - sair");
		printf("\nop: ");
		scanf("%d", &op);
	}while (op < 0 || op > 9);
	switch (op){
	case 1:
		strcpy(nomeficheiro, "moedas1.txt");
		break;
	case 2:
		strcpy(nomeficheiro, "moedas2.txt");
		break;
	case 3:
		strcpy(nomeficheiro, "moedas3.txt");
		break;
	case 9:
		strcpy(nomeficheiro, "moedas_teste.txt");
		break;
	case 0:
		exit(1);
		break;
	}
}