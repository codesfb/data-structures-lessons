#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "curso.h"



struct curso {
    char *sigla;
    char *nome;
 };


Curso *criarCurso(char *sigla, char *nome){
    Curso *c = (Curso*)malloc(sizeof(Curso));
    if(!c) return NULL;
    else {
        strcpy(c->sigla,sigla);
        strcpy(c->nome,nome);
       
    }
    return c;

};



void obterSigla(Curso *c, char *sigla){
    if(c!=NULL && sigla!=NULL){
         strcpy(sigla, c->sigla);
    }

};
void obterNomeCurso(Curso *c, char *nome){
        if(c!=NULL && nome!=NULL){
         strcpy(nome, c->nome);
    }

};
void liberarCurso(Curso *c){
    free(c);
};

