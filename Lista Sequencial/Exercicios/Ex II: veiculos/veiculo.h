//feito recriando a estrutura de lista sequencial dinamica 
#define ERROR 0
#define SUCCESS 1

typedef struct veiculo Veiculo;
typedef struct lista Lista;

Lista *criarLista();
Veiculo *criarVeiculo(char *m, char *a, char *p);
void inserirVeiculo(Lista *l, Veiculo *v, int pos);
void removerVeiculo(Lista *l, int pos);
void removerPlaca(Lista *l, char *placa);
void mostrarVeiculos(Lista *l);

