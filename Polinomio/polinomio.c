#include <stdio.h>
#include <stdlib.h>

#include "polinomio.h"

struct Monomio {
    double coeficiente;
    int expoente;
    struct Monomio *prox;
};

struct Lista {
    Monomio *inicio;
};

Lista* criarLista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l) l->inicio = NULL;
    return l;
}

void adicionarTermo(Lista *l, double coef, int exp) {
    Monomio *novo = (Monomio*) malloc(sizeof(Monomio));
    novo->coeficiente = coef;
    novo->expoente = exp;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        Monomio *aux = l->inicio;
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
}

//função auxiliar 
double elevar(double base, int exp) {
    double resultado = 1.0;
    
    
    if (exp < 0) {
        base = 1.0 / base;
        exp = -exp;
    }

    for (int i = 0; i < exp; i++) {
        resultado *= base;
    }
    return resultado;
}


double avaliarPolinomio(Lista *l, double x) {
    double soma = 0;
    Monomio *atual = l->inicio;
    while (atual != NULL) {
        soma += atual->coeficiente * elevar(x, atual->expoente);
        atual = atual->prox;
    }
    return soma;
}

void liberarLista(Lista *l) {
    Monomio *atual = l->inicio;
    while (atual != NULL) {
        Monomio *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(l);
}


