#define ALL_COINS 8

float* read_file(char *filename, int *num_coins, float *coin_value);
void show_file(float *data, int *num_coins, float *coin_value);
int* count_coins(float *data, int *num_coins);
void show_coins(int *cash, int num_coins);

void menu(char* filename);

void gera_sol_inicial(int *sol, int v);
void escreve_sol(int *sol, int vert);
void substitui(int a[], int b[], int n);
void init_rand();
int random_l_h(int min, int max);
float rand_01();

