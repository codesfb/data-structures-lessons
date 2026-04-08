#include <stdio.h>
#include <stdlib.h>
#include ".././listaencadeada.h"




int main(){
    Lista *lista = criarListaEncadeada();
    inserirInicio(lista,3);
    inserirInicio(lista,2);
    inserirInicio(lista,1);

    if(buscar(lista, 3)){
        printf("\nItem encontrado na lista");
    }else{
        printf("\nItem não encontrado");
    }

    if(buscar(lista, 5)){
        printf("\nItem encontrado na lista");
    }else{
        printf("\nItem não encontrado");
    }

    if(buscar(lista, 1)){
        printf("\nItem encontrado na lista");
    }else{
        printf("\nItem não encontrado");
    }


    if(buscar(lista, 7)){
        printf("\nItem encontrado na lista");
    }else{
        printf("\nItem não encontrado");
    }

    
    

}