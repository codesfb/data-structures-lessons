

#include <stdio.h>
#include <stdlib.h>
#include "../Fila dinamica/fila.h"

int main(){
    Fila *par = criarFila();
    Fila *impar = criarFila();
    int input = -1;
    int qtd = 0;
    while(input != 0){
        printf("\nEscreva um valor numerico qualquer e 0 para parar: ");
        scanf("%d", &input);
        
        if (input != 0) {
            if(input % 2 == 0) {
                enfileirar(par, input);
            } else {
                enfileirar(impar, input);
            }
        }
        qtd++;
    }

    printf("\n--- FILA DE PARES ---\n");
    mostrarFila(par);
    
    printf("\n--- FILA DE IMPARES ---\n");
    mostrarFila(impar);

    int v;
    for(int i =0; i <qtd;i++){
        desenfileirar(par,&v);
      
        desenfileirar(impar,&v);
        printf("\n%d desinfilerado ", v);
    }



    liberarFila(par);
    liberarFila(impar);
    
    return 0;
}
