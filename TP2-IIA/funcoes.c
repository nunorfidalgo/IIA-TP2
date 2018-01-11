#include <stdio.h>
#include "funcoes.h"
#include "utils.h"

void gera_sol_inicial(int *sol, float moedas[], int n_moedas, float valor_atingir) {
	// usar o 'valor' de forma a gerar uma solução mais parecida com a original
	// de dividirmos o valor pela moedas maior e o resto for diff de 0, podemos calcular as moedas restantes com o resto
		//sol[i] = random_1_h(1, (int)t/Vmodeda[i]; -> aplicar ao gera_vizinhos
	//reparacao

	int i;
	for (i = 0; i<n_moedas; i++)
		//sol[i] = random_l_h(1, (int)n_moedas/moedas[i]);
		//sol[i] = (int)n_moedas / moedas[i];
		//sol[i] = random_l_h(1, 9);
		sol[i] = (int)(valor_atingir/moedas[i]);
}

void mostra_sol_inicial(int *sol, int n_moedas) {
	int i;
	printf("\nSolucao inicial: ");
	for (i = 0; i<n_moedas; i++)
		printf("%d ", sol[i]);
}

int calcula_fit(int * sol, int n_moedas) {
	int i, total = 0;
	for (i = 0; i < n_moedas; i++)
		total += sol[i];
	//printf("-> Custo fit: %d", total);
	return total;
}

void gera_vizinho(int sol[], int nova_sol[], int n_moedas) { // mudar de forma a ficar mais parecido com o problema, sem ter tantos randoms
	int i, p1, p2;
	for (i = 0; i<n_moedas; i++)
		nova_sol[i] = sol[i];

	// ter em atenção os valores negativos!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (i = 0; i < n_moedas; i++) {
		if (rand_01() < 0.2) {
			nova_sol[i] += 1;
		}
		else {
			nova_sol[i] -= 1;
		}
	}
}

void mostra_vizinho(int *sol, int n_moedas) {
	int i;
	printf("\nSolucao vizinha: ");
	for (i = 0; i<n_moedas; i++)
		printf("%d ", sol[i]);
}

void escreve_sol(int *sol, int n_moedas) {
	int i;
	printf("\nSolucao: ");
	for (i = 0; i<n_moedas; i++)
		printf("%d ", sol[i]);
	//printf("\n");
}

void substitui(int best[], int sol[], int n_moedas) {
	int i;
	for (i = 0; i<n_moedas; i++)
		best[i] = sol[i];
}