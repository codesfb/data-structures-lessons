#include <stdio.h>
#include <stdlib.h>
#include "../../Dinamica/lista.h" //use a lista dinamica ja implementada

int main(){
    Lista *lista = criarLista();

    int n=-1, counter=-1;
    while(n!=0){
        printf("\nDigite um valor e 0 para parar:");
        scanf("%d", &n);
        inserir(lista, n, ++counter); 
    }

    int valorProc, pos;
    printf("Agora um elemento para buscar");
    scanf("%d", &valorProc);
    if(buscar(lista, valorProc, &pos))
        printf("O valor procurado esta na posição :%d", pos+1);
    else printf("Valor não encontrado");
    
}