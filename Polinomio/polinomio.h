#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct Monomio Monomio; // Encapsulamento (Opaque Pointer)
typedef struct Lista Lista;

// Funções da Interface
Lista* criarLista();
void adicionarTermo(Lista *l, double coef, int exp);
double avaliarPolinomio(Lista *l, double x);
void liberarLista(Lista *l);

#endif