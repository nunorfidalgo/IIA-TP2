float* read_file(char *filename, int *num_coins, float *coin_value);
void mostra_grafo(float *data, int *num_coins, float *coin_value);

void menu(char* filename);

void gera_sol_inicial(int *sol, int v);
void escreve_sol(int *sol, int vert);
void substitui(int a[], int b[], int n);
void init_rand();
int random_l_h(int min, int max);
float rand_01();
