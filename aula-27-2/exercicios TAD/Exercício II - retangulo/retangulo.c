#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

 struct retangulo {
    int altura;
    int largura;

 };
Retangulo *CriarRetangulo(int a, int l){
    Retangulo *r =(Retangulo*)malloc(sizeof(Retangulo));
    if(!r){
    return NULL;}
    else{
        r->altura = a;
        r->largura=l;  
        }
    return r;
}
int calcularArea(Retangulo *r){
    return r->altura * r->largura;
    
};
int calcularPerimetro(Retangulo *r){
    return 2*(r->altura+r->largura);
};
void liberarRetangulo(Retangulo *r){
    free(r);
}