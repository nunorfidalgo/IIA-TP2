void gera_sol_inicial(int *sol, float moedas[], int n_moedas, float valor_atingir);
void mostra_sol_inicial(int *sol, int v);

int calcula_fit(int *sol, int n_moedas);

void gera_vizinho(int sol[], int nova_sol[], int n_moedas);
void mostra_vizinho(int *sol, int n_moedas);

void escreve_sol(int *sol, int n_moedas);

void substitui(int best[], int sol[], int n_moedas);