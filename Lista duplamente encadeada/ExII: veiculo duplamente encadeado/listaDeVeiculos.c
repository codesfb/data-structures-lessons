#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDeVeiculos.h"

typedef struct no
{
    Veiculo *info;
    No *ant;
    No *prox;

} No;

struct lista
{
    No *inicio;
    No *fim;
};

Lista *criarListaDuplamenteEncadeada()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (!lista)
        return NULL;
    lista->inicio = NULL;
    lista->fim = NULL;

    return lista;
};

int listaVazia(Lista *l)
{
    return l->inicio == NULL;
}

int inserirInicio(Lista *lista, Veiculo *veiculo)
{
    No *no = (No *)malloc(sizeof(No));
    if (!no)
        return ERROR;

    no->info = veiculo;
    no->ant = NULL;
    no->prox = NULL;

    if (listaVazia(lista))
    {
        lista->fim = no;
    }
    else
    {
        no->prox = lista->inicio;
        lista->inicio->ant = no;
    }

    lista->inicio = no;

    return SUCCESS;
};
int inserirFinal(Lista *lista, Veiculo *veiculo)
{
    No *no = (No *)malloc(sizeof(No));
    if (!no)
        return ERROR;

    no->info = veiculo;
    no->prox = NULL;
    no->ant = NULL;

    if (listaVazia(lista))
    {
        lista->inicio = no;
    }
    else
    {
        no->ant = lista->fim;
        lista->fim->prox = no;
    }
    lista->fim = no;

    return SUCCESS;
};
int inserirApos(Lista *lista, Veiculo *veiculo, char *placaExistente){
    No *aux = lista->inicio;
    if (!aux)
        return ERROR;
    while(aux != NULL && strcmp(getPlaca(veiculo), placaExistente)!= 0){
        aux= aux->prox;

    }
    if(aux == NULL) return ERROR;

    No *no = (No *)malloc(sizeof(No));
    if (!no)
        return ERROR;

    no->info=veiculo;
    no->prox = aux->prox;
    no->ant= aux;

    if (aux->prox!=NULL)
        aux->prox->ant = no;
    else
        lista->fim = no;

    aux->prox=no;

    return SUCCESS;
};
int remover (Lista *lista, char *placaRemover)
{
    if (listaVazia(lista))
        return ERROR;

    No *aux = lista->inicio;
    while (aux!=NULL &&  strcmp(getPlaca(aux->info), placaRemover) !=0)
        aux = aux->prox;
    
    if (aux == NULL) //percorreu toda lista e não encontrou
        return ERROR;

    if (aux->ant!=NULL) //se itemExistente é primeiro elemento
        aux->ant->prox = aux->prox;
    else
        lista->inicio = aux->prox;
    
    if (aux->prox!=NULL)
        aux->prox->ant = aux->ant;
    else
        lista->fim = aux->ant;
    
    free(aux->info);
    free(aux);
    return SUCCESS;
}
void mostrar(Lista *lista)
{
    if (listaVazia(lista))
        printf("Lista vazia!\n");
    else
    {
        No *aux = lista->inicio;
        while (aux!=NULL)
        {
            printf("\nPlaca: %s", getPlaca(aux->info));
            printf("\nMarca: %s", getMarca(aux->info));
            printf("\nAno: %d", getAno(aux->info));
            aux = aux->prox;
        }
        printf("\n");
    }
}

void liberarLista(Lista *lista){
    if (lista==NULL)
      return;

    No *aux = lista->inicio;
    while(aux!=NULL){
        No *proximo = aux->prox;
        free(aux->info);
        free(aux);
        aux=proximo;
    }
    free(lista);
}