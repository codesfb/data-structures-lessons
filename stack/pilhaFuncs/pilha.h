
#define ERROR 1
#define SUCCESS 0
#define MAXTAM 5
typedef struct pilha Pilha;
Pilha *criarPilha();
int push(Pilha *p, char valor);
int pop(Pilha *p, char *valor);
int peek(Pilha *p, char *valor);
void destroy(Pilha *p);
void mostrarPilha(Pilha *p);
int pilhaCheia(Pilha *p);
int pilhaVazia(Pilha *p);
