#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"

struct veiculo{
    char marca[100];
    char placa[50];
    int ano;

};

Veiculo *criarVeiculo(const char *marca, const char *placa, int ano){
    Veiculo *v= (Veiculo *)malloc(sizeof(Veiculo));
    if(!v) return NULL;
    strcpy(v->marca,marca);
    strcpy(v->placa,marca);
    v->ano=ano;
    return v;
};
char *getMarca(Veiculo *v){
    return v->marca;
};
char *getPlaca(Veiculo *v){
    return v->placa;
};
char *getAno(Veiculo *v){
    return v->ano;
};
void freeVeiculo(Veiculo *v){
    if(!v) return;
    free(v);
};