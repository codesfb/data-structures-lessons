#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main(){
    Stack *pilha = createStack();
    int op, v;
    do{
        printf("\n=================Stack==================\n");
        (showStack(pilha)==SUCCESS)? printf("Stack\n") : printf("Empty\n");

        printf("\n1 - Push");
        printf("\n2 - POP");
        printf("\n3 - Show top");
        printf("\n4 - Freee");
        printf("\n5 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &op);


        switch(op){
            case 1:
                printf("Value to push to the stack:");
                scanf("%d", &v);
                push(pilha, &v)? printf("Added successfuly"):printf("Error");
                break;
            case 2: 
                printf("Pop value from the stack:");            
                pop(pilha, &v)? printf("%d Poped successfuly",v):printf("Error");
                break;
            case 3: 
                int v;
                top(pilha,&v);            
                printf("Top is %d", v);
                break;
            case 4:
                free(pilha);
                printf("Now the satck is empty\n");
                pilha = createStack();
                break;
            case 5: 
                printf("Leaving\n");
                break;
            default:
            printf("\nInvalid");
            break;
              

        }

    }while(op!=5);


}