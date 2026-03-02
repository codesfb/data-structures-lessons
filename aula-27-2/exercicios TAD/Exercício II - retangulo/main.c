#include <stdio.h>
#include "retangulo.h"
int main(){
    Retangulo  *Pequeno = CriarRetangulo(5,3);
    Retangulo  *Medio = CriarRetangulo(10,4);
    Retangulo  *Grande = CriarRetangulo(20,15);
    Retangulo  *Quadrado = CriarRetangulo(6,6);
    
    printf("A area do retangulo pequeno é %dcm²\n",calcularArea(Pequeno));
    printf("A area do retangulo Medio é %dcm²\n",calcularArea(Medio));
    printf("A area do retangulo grande é %dcm²\n",calcularArea(Grande));
    printf("A area do retangulo Qadrado é %dcm²\n",calcularArea(Quadrado));
    printf("");
    printf("O Perimetro do retangulo pequeno é %dcm²\n",calcularPerimetro(Pequeno));
    printf("O Perimetro do retangulo Medio é %dcm²\n",calcularPerimetro(Medio));
    printf("O Perimetro do retangulo grande é %dcm²\n",calcularPerimetro(Grande));
    printf("O Perimetro do retangulo Qadrado é %dcm²\n",calcularPerimetro(Quadrado));



    liberarRetangulo(Pequeno);    
    liberarRetangulo(Medio);    
    liberarRetangulo(Grande);    
    liberarRetangulo(Quadrado);    
    return 0;
}