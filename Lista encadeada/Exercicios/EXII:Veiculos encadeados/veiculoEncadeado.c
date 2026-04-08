#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculoEncadeado.h"

typedef struct no
{
    Veiculo *item;
    struct no *prox;
} No;

struct lista
{
    No *inicio;
    No *fim;
};


struct veiculo{
    char marca[40];
    char ano[30];
    char placa[30];
};

Lista *criarListaEncadeada()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}


Veiculo *criarVeiculo(char *marca, char * placa, char *ano){
    Veiculo *v = (Veiculo*)malloc(sizeof(Veiculo));
    if (!v)
        return NULL;
    strcpy(v->marca, marca);
    strcpy(v->ano, ano);
    strcpy(v->placa, placa);

    return v;

} 

int listaVazia(Lista *lista)
{
    return lista->inicio == NULL;
}

int inserirInicio(Lista *lista, Veiculo *v)
{
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->item = v;
    no->prox = lista->inicio;
    lista->inicio = no;
    if (listaVazia(lista)) // se lista estiver vazia, insiro primeiro nó
        lista->fim = no;

    return SUCCESS;
}

int inserirFinal(Lista *lista, Veiculo *v)
{
    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;

    no->item = v;
    no->prox = NULL;

    if (listaVazia(lista)) // se lista estiver vazia, insiro primeiro nó
        lista->inicio = no;
    else
        lista->fim->prox = no;

    lista->fim = no;

    return SUCCESS;
}

int inserirApos(Lista *lista, Veiculo *v, char *itemProcurado)
{
    

    No *aux = lista->inicio;
    
    

  

    while (aux != NULL && strcmp(aux->item->placa, itemProcurado)!=0)
    {

        printf("\nFuncionou aqui %s %s",aux->item->placa, itemProcurado);
        
        aux = aux->prox;
    }

    if (aux == NULL) // percorreu toda a lista e não encontrou o item desejado
        return ERROR;

    No *no = (No *)malloc(sizeof(No));
    if (no == NULL)
        return ERROR;
    no->item = v;
    no->prox = aux->prox;
    aux->prox = no;

    if (aux == lista->fim) // item procurado era o último da lista
        lista->fim = no;   // precisa atualizar 'fim'

    return SUCCESS;
}



int remover(Lista *lista, char *placa)
{
    if (listaVazia(lista))
        return ERROR;

    No *aux1 = lista->inicio;
    No *aux2 = NULL;

    while (aux1 != NULL && strcmp(aux1->item->placa, placa)!=0)
    {
        aux2 = aux1;
        aux1 = aux1->prox;
    }
    if (aux1 == NULL) // percorreu toda a lista e não encontrou o item
        return ERROR;

    if (aux1 == lista->inicio)
    { // item está no início da lista
        lista->inicio = lista->inicio->prox;
        if (lista->inicio == NULL) // item removido era o único
            lista->fim = NULL;
    }
    else if (aux1 == lista->fim)
    { // item está no final da lista
        aux2->prox = NULL;
        lista->fim = aux2;
    }
    else
        aux2->prox = aux1->prox; // item está no meio da lista

    free(aux1);
    return SUCCESS;
}

void mostrar(Lista *lista)
{
    if (listaVazia(lista))
        printf("Lista vazia");
    else
    {
        No *aux = lista->inicio;
        int i =1;
        while (aux != NULL)
        {
            printf("\nVeiculo:%d\nMarca:%s\nAno:%s\nPlaca:%s",i, aux->item->marca,aux->item->ano, aux->item->placa);
            printf("\n_____________________________");
            aux = aux->prox;
            i++;
        }
    }
}

void liberarLista(Lista *lista)
{
    if (lista == NULL)
        return;

    No *aux = lista->inicio;
    while (aux != NULL)
    {
        No *proximo = aux->prox;
        free(aux);
        aux = proximo;
    }
    free(lista);
}