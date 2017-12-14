#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "utils.h"

#define DEFAULT_RUNS 10

int main(int argc, char *argv[])
{
	char filename[30];
	int runs, num_coins; // k, custo = 0, best_custo = 0;
	//int *sol, *best;
	float value;
	float *filedata;
	//int *cashregister;
	float mbf = 0.0;

	runs = DEFAULT_RUNS;
	menu(filename);

	if(runs <= 0)
		return 0;
	
	init_rand();

    // Preenche vector de moedas
	filedata = read_file(filename, &num_coins, &value);

    mostra_grafo(filedata, &num_coins, &value);
    exit(1);
/*
	sol = malloc(sizeof(int)*vert);
	best = malloc(sizeof(int)*vert);
	if(sol == NULL || best == NULL)
	{
		printf("Erro na alocacao de memoria");
		exit(1);
	}
	for(k=0; k<runs; k++)
	{
		// Gerar solucao inicial
		gera_sol_inicial(sol, vert);
		escreve_sol(sol, vert);
		// Trepa colinas
		// custo = trepa_colinas(sol, grafo, vert, num_iter);
		// Aula 8
		//custo = trepa_colinas_prob(sol, grafo, vert, num_iter);
		// custo = trepa_colinas_prob_v2(sol, grafo, vert, num_iter);
		custo = recristalizacao_simualada(sol, grafo, vert, num_iter);
		// Escreve resultados da repeticao k
		printf("\nRepeticao %d:", k);
		escreve_sol(sol, vert);
		printf("Custo final: %2d\n", custo);
		mbf += custo;
		if(k==0 || best_custo > custo)
		{
			best_custo = custo;
			substitui(best, sol, vert);
		}
    }
	// Escreve eresultados globais
	printf("\n\nMBF: %f\n", mbf/k);
	printf("\nMelhor solucao encontrada");
	escreve_sol(best, vert);
	printf("Custo final: %2d\n", best_custo);
	free(grafo);
    free(sol);
	free(best);
*/
    return 0;
}
