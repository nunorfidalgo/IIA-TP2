#define TOTAL_MOEDAS 8

void init_rand();
int random_l_h(int min, int max);
float rand_01();

float* ler_ficheiro(char *nomeficheiro, int *num_moedas, float *valor_moeda);
void mostra_ficheiro(float *dados, int *num_moedas, float *valor_moeda);
int* conta_moedas(float *dados, int *num_moedas);
void mostra_moedas(int *dinheiro, int num_moedas);
void menu(char* nomeficheiro);