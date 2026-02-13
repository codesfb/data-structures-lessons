#include <stdlib.h>
#include "Fracao.h"

struct fracao {
    int numerador, denominador;
};

Fracao *criarFracao(int numerador, int denominador) {
    Fracao *f = (Fracao*)malloc(sizeof(Fracao)); 
    if (f != NULL) {
        f->numerador = numerador;
        f->denominador = denominador;
    }
    return f;
}

Fracao *somarFracao(Fracao *f1, Fracao *f2) {
    //  (a*d + b*c) / (b*d)
    int num = (f1->numerador * f2->denominador) + (f2->numerador * f1->denominador);
    int den = f1->denominador * f2->denominador;
    
    return criarFracao(num, den); 
}

float converterParaDecimal(Fracao *f) {
    if (f->denominador == 0) return 0;
    return (float)f->numerador / f->denominador;
}

int obterNumerador(Fracao *f) {
    return f->numerador;
}

int obterDenominador(Fracao *f) {
    return f->denominador;
}

void liberarFracao(Fracao *f) {
    free(f);
}