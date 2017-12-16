#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmo.h"
#include "funcoes.h"
#include "utils.h"

#define PROB 0.01
#define TMAX 100
#define TMIN 5

// Trepa colinas first-choice
// Parametros: solucao, matriz de adjacencias, numero de vertices e numero de iteracoes
// Devolve o custo da melhor solucao encontrada
int trepa_colinas(int sol[], int *moedas, int n, int num_iter)
{
    int *nova_sol, custo, custo_viz, i;

	nova_sol = malloc(sizeof(int)*n);
    if(nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
	// Avalia solucao inicial
    custo = calcula_fit(sol, moedas, n);
    for(i=0; i<num_iter; i++)
    {
		// Gera vizinho
		gera_vizinho(sol, nova_sol, n);
		// Aula 8
		//gera_vizinho2(sol, nova_sol, vert);
		// Avalia vizinho
		custo_viz = calcula_fit(nova_sol, moedas, n);
		// Aceita vizinho se o custo diminuir (problema de minimizacao)
        //if(custo_viz < custo)
        if(custo_viz <= custo)
        {
			substitui(sol, nova_sol, n);
			custo = custo_viz;
        }
    }
    free(nova_sol);
    return custo;
}
// aula 8
int trepa_colinas_prob(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i;

	nova_sol = malloc(sizeof(int)*vert);
    if(nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);
    for(i=0; i<num_iter; i++)
    {
		// Gera vizinho
		//gera_vizinho(sol, nova_sol, vert);
		// Aula 8
		gera_vizinho2(sol, nova_sol, vert);
		// Avalia vizinho
		custo_viz = calcula_fit(nova_sol, mat, vert);
		// Aceita vizinho se o custo diminuir (problema de minimizacao)
        //if(custo_viz < custo)
        if(custo_viz <= custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
        }
        else
        {
            if (rand_01() < PROB)
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
    }
    free(nova_sol);
    return custo;
}

int trepa_colinas_prob_v2(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i, best_custo, *best_sol;

	nova_sol = malloc(sizeof(int)*vert);
    best_sol = malloc(sizeof(int)*vert);
    if(nova_sol == NULL || best_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);

    // aula 8
    best_custo = custo;
    substitui(best_sol, sol, vert);

    for(i=0; i<num_iter; i++)
    {
		// Gera vizinho
		gera_vizinho(sol, nova_sol, vert);
		// Avalia vizinho
		custo_viz = calcula_fit(nova_sol, mat, vert);
		// Aceita vizinho se o custo diminuir (problema de minimizacao)
        //if(custo_viz < custo)
        if(custo_viz < best_custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
        }
        else
        {
            if (rand_01() < PROB)
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
    }
    substitui(sol, best_sol, vert);
    free(nova_sol);
    return custo;
}


int recristalizacao_simualada(int sol[], int *mat, int vert, int num_iter)
{
    int *nova_sol, custo, custo_viz, i, best_custo, *best_sol;
    float t = TMAX, decrementoT;

    // Calculo de decremento de T para ir de TMAX e TMIN em num iterações
    decrementoT = (float)(TMAX - TMIN) / num_iter; //verifcar se o cast está correcto?

    // Aloca espaço em mem para guardar e nova solução e a melhor
	nova_sol = malloc(sizeof(int)*vert);
    best_sol = malloc(sizeof(int)*vert);
    if(nova_sol == NULL || best_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
	// Avalia solucao inicial
    custo = calcula_fit(sol, mat, vert);

    best_custo = custo;
    substitui(best_sol, sol, vert);

    for(i=0; i<num_iter; i++)
    {
		// Gera vizinho
		gera_vizinho(sol, nova_sol, vert);
		// Avalia vizinho
		custo_viz = calcula_fit(nova_sol, mat, vert);
		// Aceita vizinho se o custo diminuir (problema de minimizacao)
        //if(custo_viz < custo)
        if(custo_viz < best_custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
        }
        if( custo_viz <= custo)
        {
			substitui(sol, nova_sol, vert);
			custo = custo_viz;
        }
        else
        {
            if (rand_01() < exp((custo-custo_viz)/t) )
            {
                substitui(sol, nova_sol, vert);
                custo = custo_viz;
            }
        }
        t = t - decrementoT;
    }
    substitui(sol, best_sol, vert);
    free(nova_sol);
    return custo;
}
