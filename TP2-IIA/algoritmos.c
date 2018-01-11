#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "algoritmos.h"
#include "funcoes.h"
#include "utils.h"

int trepa_colinas(int sol[], float *moedas, int n_moedas, int num_iter)
{
	int i, *nova_sol, custo, custo_viz;
	nova_sol = malloc(sizeof(int)*n_moedas);
	/*for (i = 0; i > n_moedas; i++) {
		nova_sol[i] = 0;*/
    if(nova_sol == NULL)
    {
        printf("Erro na alocacao de memoria");
        exit(1);
    }
    custo = calcula_fit(sol, n_moedas);
    for(i=0; i<num_iter; i++)
    {
		gera_vizinho(sol, nova_sol, n_moedas);
		//mostra_vizinho(nova_sol, n_moedas);
		custo_viz = calcula_fit(nova_sol, n_moedas);
        if(custo_viz < custo) // mudar em < e <=
        {
			custo = custo_viz;
			substitui(sol, nova_sol, n_moedas);
        }
    }
    free(nova_sol);
    return custo;
}
