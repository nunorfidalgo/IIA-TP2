#include <stdio.h>
#include <stdlib.h>
#include "algoritmo.h"
#include "funcoes.h"
#include "utils.h"

#define DEFAULT_RUNS 5

int main(int argc, char *argv[]){
	char nomeficheiro[30];
	int runs, num_moedas, k, custo = 0, best_custo = 0; // vert = TOTAL_MOEDAS;
	int *sol, *best;
	float valor;
	float *dadosficheiro;
	int *caixa;
	float mbf = 0.0;

	while (1) {
		runs = DEFAULT_RUNS;
		menu(nomeficheiro);

		if (runs <= 0)
			return 0;

		init_rand();

		// Preenche vector de moedas
		dadosficheiro = ler_ficheiro(nomeficheiro, &num_moedas, &valor);
		mostra_ficheiro(dadosficheiro, &num_moedas, &valor);

		caixa = conta_moedas(dadosficheiro, &num_moedas);
		mostra_moedas(caixa, TOTAL_MOEDAS);

		sol = malloc(sizeof(int)*TOTAL_MOEDAS);
		best = malloc(sizeof(int)*TOTAL_MOEDAS);
		if (sol == NULL || best == NULL)
		{
			printf("Erro na alocacao de memoria");
			exit(1);
		}
		for (k = 0; k < runs; k++)
		{
			// Gerar solucao inicial
			gera_sol_inicial(sol, TOTAL_MOEDAS);
			mostra_sol_inicial(sol, TOTAL_MOEDAS);
			escreve_sol(sol, TOTAL_MOEDAS);
			// Trepa colinas
			custo = trepa_colinas(sol, caixa, TOTAL_MOEDAS, runs);
			// Aula 8
			//custo = trepa_colinas_prob(sol, grafo, vert, num_iter);
			// custo = trepa_colinas_prob_v2(sol, grafo, vert, num_iter);
			//custo = recristalizacao_simualada(sol, grafo, vert, num_iter);
			// Escreve resultados da repeticao k
			printf("\nRepeticao %d:", k);
			escreve_sol(sol, TOTAL_MOEDAS);
			printf("Custo final: %2d\n", custo);
			mbf += custo;
			if (k == 0 || best_custo > custo)
			{
				best_custo = custo;
				substitui(best, sol, TOTAL_MOEDAS);
			}
		}
		// Escreve eresultados globais
		printf("\nMBF: %0.3f\n", mbf / k);
		printf("\nMelhor solucao encontrada");
		escreve_sol(best, TOTAL_MOEDAS);
		printf("Custo final: %2d\n", best_custo);
		free(caixa);
		free(sol);
		free(best);
		printf("\n");
	}
	return 0;
}
