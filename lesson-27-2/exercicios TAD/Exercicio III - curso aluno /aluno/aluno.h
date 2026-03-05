// Em seguida, implemente o TAD Aluno
// Propriedades: prontuário, nome e Curso
// Operações: criarAluno, obterProntuario, obterNome, obterCurso,
// liberarAluno
#define ERROR 1
#define SUCCESS 0
#include "../curso/curso.h"
typedef struct aluno Aluno;

Aluno *criarAluno(int prontuario, char *nome, Curso *curso);

int obterProntuario(Aluno *a);
void obterNomeAluno(Aluno *a, char *nome);
Curso *obterCurso(Aluno *a);
void liberarAluno(Aluno *a);
