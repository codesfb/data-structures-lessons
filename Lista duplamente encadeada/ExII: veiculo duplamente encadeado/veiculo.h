#define ERROR 0
#define SUCCESS 1

typedef struct veiculo Veiculo;


Veiculo *criarVeiculo(const char *marca, const char *placa, int ano);
char *getNome(Veiculo *v);
char *getPlaca(Veiculo *v);
char *getAno(Veiculo *v);
void freeVeiculo(Veiculo *v);