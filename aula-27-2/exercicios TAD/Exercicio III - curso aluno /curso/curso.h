// Propriedades: sigla, nome
// Operações: criarCurso, obterSigla, obterNome, liberarCurso



#define ERROR 1
#define SUCCESS 0
typedef struct curso Curso;


Curso *criarCurso(char *sigla, char *nome);
void obterSigla(Curso *c, char *sigla);
void obterNomeCurso(Curso *c, char *nome);
void liberarCurso(Curso *c);

