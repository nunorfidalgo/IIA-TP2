#include <stdio.h>
#include "funcoes.h"
#include "utils.h"

// Gera a solucao inicial
// Parametros: solucao, numero de moedas
void gera_sol_inicial(int *sol, int m) {
	int i, x;
	for (i = 0; i<m; i++)
		sol[i] = 0;
	for (i = 0; i<m/2; i++) {
		do
			x = random_l_h(0, m - 1);
		while (sol[x] != 0);
		//sol[x]=1;
		sol[x] = random_l_h(1, m - 1);
	}
	printf("\n");
}

void mostra_sol_inicial(int *sol, int m) {
	int i;
	printf("\tSolucao inicial: ");
	for (i = 0; i<m; i++)
		printf("%d ", sol[i]);
}

// Escreve solucao
// Parametros: solucao e numero de moedas
void escreve_sol(int *sol, int m) {
	int i;
	printf("\n\tConjunto Solucao: ");
	for (i = 0; i<m; i++)
		if (sol[i] != 0)
			printf("%d ", i);
	/*printf("\nConjunto B: ");
	for (i = 0; i<vert; i++)
		if (sol[i] == 1)
			printf("%d  ", i);*/
	printf("\n");
}

// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n) {
	int i;
	for (i = 0; i<n; i++)
		a[i] = b[i];
}

// Calcula a qualidade de uma solução
// Recebe:  A solução, a, a matriz de adjacências, mat, e o número de vértices, vert
// Devolve: O custo que é o número de ligações que existem na solução
int cal_fit(int a[], int *mat, int vert){
	int total=0;
	int i, j;

	for(i=0; i<vert; i++)
		if(a[i]==0)
		{
			for(j=0; j<vert;j++)
				if(a[j]==1 && *(mat+i*vert+j)==1)
				    total++;
		}
	return total;
}

int calcula_fit(int sol[], int *caixa, int n){
	int total = 0;
	int i, j;

	for (i = 0; i<n; i++)
		if (sol[i] != 0)
		{
			for (j = 0; j<n; j++)
				if (sol[j] != 0 && *(caixa + j) != 0)
					total++;
		}
	return total;
}

// Gera um vizinho
// Parametros: solucao actual, vizinho, numero de vertices
//swap two vertices
void gera_viz(int a[], int b[], int n) {
	int i, p1, p2;

	for (i = 0; i<n; i++)
		b[i] = a[i];
	// Encontra posicao com valor 0
	do
		p1 = random_l_h(0, n - 1);
	while (b[p1] != 0);
	// Encontra posicao com valor 0
	do
		p2 = random_l_h(0, n - 1);
	while (b[p2] != 1);
	// Troca
	b[p1] = 1;
	b[p2] = 0;
}

void gera_vizinho(int a[], int b[], int n) {
	int i, p1, p2;
	for (i = 0; i<n; i++)
		b[i] = a[i];
	// Encontra posicao com valor 0
	do {
		p1 = random_l_h(0, n - 1);
		//printf("trap...");
	} while (b[p1] != 0);
	// Encontra posicao com valor 0
	do {
		p2 = random_l_h(0, n - 1);
	} while (b[p2] < 1 || b[p2] > 9);
	// Troca
	b[p1] = random_l_h(0, n - 1);
	b[p2] = 0;
}

// aula 8
/*
// Ficha 7 - 4.3
void gera_vizinho2(int a[], int b[], int n) {
int i, p1, p2, p3, p4;

for (i = 0; i < n; i++)
b[i] = a[i];
// Encontra posicao com valor 0
do
p1 = random_l_h(0, n - 1);
while (b[p1] != 0);
// Encontra posicao com valor 0
do
p2 = random_l_h(0, n - 1);
while (b[p2] != 1);
// Troca
b[p1] = 1;
b[p2] = 0;

do
p3 = random_l_h(0, n - 1);
while (b[p3] != 0 || p3 == p2);

do
p4 = random_l_h(0, n - 1);
while (b[p4] != 1 || p4 == p1);

b[p3] = 1;
b[p4] = 0;
}
*/
void gera_vizinho2(int a[], int b[], int n)
{
	int i, p1, p2, p3, p4;

	for (i = 0; i<n; i++)
		b[i] = a[i];
	// Encontra posicao com valor 0
	do
		p1 = random_l_h(0, n - 1);
	while (b[p1] != 0);
	// Encontra posicao com valor 0
	do
		p2 = random_l_h(0, n - 1);
	while (b[p2] != 1);
	// Troca
	b[p1] = 1;
	b[p2] = 0;

	do
		p3 = random_l_h(0, n - 1);
	while (b[p3] != 0 || p3 == p2);
	do
		p4 = random_l_h(0, n - 1);
	while (b[p4] != 1 || p4 == p1);
	// Troca
	b[p3] = 1;
	b[p4] = 0;
}
