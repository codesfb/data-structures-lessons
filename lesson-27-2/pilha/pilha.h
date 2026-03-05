
#define ERROR 1
#define SUCCESS 0
#define MAXTAM 5
typedef struct pilha Pilha;
Pilha *criarPilha();
int push(Pilha *p,int n);
int pop(Pilha *p, int *valor);
int peek(Pilha *p, int *valor);
void destroy(Pilha *p);
void mostrarPilha(Pilha *p);
int pilhaCheia(Pilha *p);
int pilhaVazia(Pilha *p);
