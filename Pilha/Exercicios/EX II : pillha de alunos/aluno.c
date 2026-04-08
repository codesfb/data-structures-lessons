#include <stdlib.h>
#include <string.h>

#include "aluno.h"

struct aluno{
    char *prontuario;
    char *nome;

};

Aluno *criarAluno(char *nome, char *prontuario){
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));
    if(!aluno) return NULL;
    
    aluno->nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    aluno->prontuario = (char*)malloc((strlen(prontuario) + 1) * sizeof(char));

    if(!aluno->nome || !aluno->prontuario) {
        if(aluno->nome) free(aluno->nome);
        if(aluno->prontuario) free(aluno->prontuario);
        free(aluno);
        return NULL;
    }

    strcpy(aluno->nome, nome); 
    strcpy(aluno->prontuario, prontuario); 

    return aluno;

};
char *obterProntuario(Aluno *a){
    return a->prontuario;
};
char *obterNome(Aluno *a){
    return a->nome;
}; 
void liberarAluno(Aluno *a){
    if(a) {
        free(a->nome);
        free(a->prontuario);
        free(a);
    }
};