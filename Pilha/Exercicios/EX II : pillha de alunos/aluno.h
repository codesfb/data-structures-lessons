#define SUCCESS 1
#define ERROR 0

typedef struct aluno Aluno;

Aluno *criarAluno(char *nome, char *prontuario);
char *obterProntuario(Aluno *a);
char *obterNome(Aluno *a); 
void liberarAluno(Aluno *a);