#include <stdio.h>
#include <stdlib.h>
#include "algoritmos.h"
#include "funcoes.h"
#include "utils.h"

#define DEFAULT_RUNS 2500 // 2500
#define ITERATIONS 5000 // 5000

int main(int argc, char *argv[]){
	char nomeficheiro[30];
	int n_moedas, k, best_ite, custo = 0, best_custo = 0, *sol, *best; 
	float *moedas, valor_atingir, mbf = 0.0;

	while (1) {
		menu(nomeficheiro);
		init_rand();

		// Preenche vector de moedas
		moedas = ler_ficheiro(nomeficheiro, &n_moedas, &valor_atingir);
		mostra_ficheiro(moedas, &n_moedas, &valor_atingir);

		sol = malloc(sizeof(int)*n_moedas);
		best = malloc(sizeof(int)*n_moedas);
		if (sol == NULL || best == NULL)
		{
			printf("Erro na alocacao de memoria");
			exit(1);
		}
		for (k = 0; k < DEFAULT_RUNS; k++)
		{
			//printf("\nRepeticao %d: ", k);
			// Gerar solucao inicial
			gera_sol_inicial(sol, moedas, n_moedas, valor_atingir);
			//mostra_sol_inicial(sol, n_moedas);
			// Trepa colinas
			custo = trepa_colinas(sol, moedas, n_moedas, ITERATIONS);
						
			//printf("\nCusto final: %d", custo);
			mbf += custo;
			if (k == 0 || best_custo >= custo) // perguntar ao prof se aqui também tem que se > e ou >=???????????????????????
			{
				best_ite = k;
				best_custo = custo;
				substitui(best, sol, n_moedas);
			}
			//printf("\n");
		}
		// Escreve eresultados globais
		printf("\n");
		printf("\nMBF: %0.3f\n", mbf / k);
		printf("\nMelhor solucao encontrada foi na repeticao: %d", best_ite);
		escreve_sol(best, n_moedas);
		printf("\nCusto final: %d\n", best_custo);
		free(sol);
		free(best);
		printf("\n");
	}
	return 0;
}
