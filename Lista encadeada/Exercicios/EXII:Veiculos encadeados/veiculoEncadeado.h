#define SUCCESS 1
#define ERROR 0

typedef struct lista Lista;
typedef struct veiculo Veiculo;





Lista* criarListaEncadeada();

Veiculo *criarVeiculo(char *marca, char * placa, char *ano);
int inserirInicio(Lista *lista, Veiculo *v);
int inserirFinal(Lista *lista, Veiculo *v);
int inserirApos(Lista *lista, Veiculo *v, char *placaProcurada);
int remover(Lista *lista,char *placaProcurada);
void mostrar(Lista *lista);
void liberarLista(Lista *lista);
//int buscar(Lista *l, int itemProcurado);