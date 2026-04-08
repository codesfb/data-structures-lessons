#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculo.h"
#define CAP 2

struct veiculo
{
    char marca[40];
    char ano[30];
    char placa[30];
};
struct lista
{
    Veiculo **itemsVeiculos;
    int quantidade;
    int capacidade;
};



int listaCheia(Lista *lista) {
    return lista->quantidade == lista->capacidade;
}

int listaVazia(Lista *lista) {
    return lista->quantidade == 0;
}


Lista *criarLista()
{
    Lista *veiculos = (Lista *)malloc(sizeof(Lista));
    if (!veiculos)
        return NULL;
    veiculos->capacidade = CAP;
    veiculos->itemsVeiculos = (Veiculo**)malloc(veiculos->capacidade * sizeof(Veiculo*));
    if (!veiculos->itemsVeiculos)
    {
        free(veiculos);
        return NULL;
    };
    veiculos->quantidade = 0;

    return veiculos;
};
Veiculo *criarVeiculo(char *marca, char *ano, char *placa)
{
    Veiculo *v = (Veiculo *)malloc(sizeof(Veiculo));
    if (!v)
        return NULL;
    strcpy(v->marca, marca);
    strcpy(v->ano, ano);
    strcpy(v->placa, placa);

    return v;
};

int redimencionar(Lista *l){
    Veiculo **novo = realloc(l->itemsVeiculos, (l->capacidade*=2)* sizeof(Veiculo*));
    if(!novo) return ERROR;
    l->itemsVeiculos= novo;
    return SUCCESS;
}



void inserirVeiculo(Lista *l, Veiculo *v, int pos)
{
    if (!l || !v)
        return; 
    if (pos < 0 || pos > l->quantidade) return;

    if(listaCheia(l))
     if(redimencionar(l)== ERROR) return;

    for(int i = l->quantidade; i >pos ;i--)
        l->itemsVeiculos[i]= l->itemsVeiculos[i-1];

    l->itemsVeiculos[pos] = v;
    l->quantidade++;
};

void removerVeiculo(Lista *l, int pos){
    if (!l)
        return; 
    if (pos < 0 || pos > l->quantidade) return;

    for(int i = pos; i <l->quantidade-1 ;i++)
        l->itemsVeiculos[i]= l->itemsVeiculos[i+1];

     l->quantidade--;
};


int buscarPlaca(Lista *lista, char *placaProcurado, int *pos) {
    if (listaVazia(lista))
        return ERROR;

    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp (lista->itemsVeiculos[i]->placa, placaProcurado)==0) {
            *pos = i;
            return SUCCESS;
        }
    }

    return ERROR;
}


void removerPlaca(Lista *l, char *placa){
    int pos;
    if(buscarPlaca(l,placa,&pos)== ERROR) return;

    removerVeiculo(l,pos);

};

void mostrarVeiculos(Lista *l){
    if(l->quantidade == 0 ){
        printf("\nLista de veiculos vazia");
        return;
    }
    printf("\n====================TODOS OS VEICULOS================");
    for(int i =0;i < l->quantidade;i++){
        printf("\nVeiculo:%d\nMarca:%s\nAno:%s\nPlaca:%s",i,l->itemsVeiculos[i]->marca,
        l->itemsVeiculos[i]->ano, l->itemsVeiculos[i]->placa);
        printf("\n_________________");

    }
};


void liberarLista(Lista *lista) {
    for(int i = 0; i < lista->quantidade;i++)
        free(lista->itemsVeiculos[i]);

    free(lista->itemsVeiculos);
    free(lista);
}