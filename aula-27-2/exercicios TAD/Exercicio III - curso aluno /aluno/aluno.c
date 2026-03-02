#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aluno.h"

struct aluno {
    int prontuario; char *nome; Curso *curso;
};

Aluno *criarAluno(int prontuario, char *nome, Curso *curso){
    
    Aluno *novoAluno = (Aluno*)malloc(sizeof(Aluno));

    if(!novoAluno){
        return NULL;

    }else{
        novoAluno->prontuario=prontuario;
        strcpy(novoAluno->nome, nome);
        novoAluno->curso=curso;

    }
    return novoAluno;
};

int obterProntuario(Aluno *a){
    if(a != NULL ){
        return a->prontuario; 

    }


};
void obterNomeAluno(Aluno *a, char *nome){
     if(a != NULL && nome != NULL){
        strcpy(nome, a->prontuario); 

    }


};
Curso *obterCurso(Aluno *a){
    if (!a) return NULL;
    return a->curso; 
}


void liberarAluno(Aluno *a){
    free(a);

};