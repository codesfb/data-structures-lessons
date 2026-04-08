#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



void menu(){
	printf("\n1 - Push");
	printf("\n2 - POP");
	printf("\n3 - Show top");
	printf("\n4 - Freee");
	printf("\n5 - Show complete stack");
	printf("\n6 - Sair");
	printf("\nEscolha uma opção: ");
	}

void displayStack(Stack *pilha,char *s){
	 printf("\n=================%s==================\n",s);
     (showStack(pilha)==SUCCESS)? printf("\nStack\n") : printf("Empty\n");
	}

int main(){
    Stack *pilha = createStack(2);
    int op, v;
    do{
		displayStack(pilha,"Current Stack");
		menu();		
        scanf("%d", &op);


        switch(op){
            case 1:
            
                printf("Value to push to the stack:");
                scanf("%d", &v);
                push(pilha, v)? printf("Added successfuly"):printf("Error: Stack is full");
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
                pilha = createStack(1);
                break;
			case 5:

				displayStack(pilha,"Complete Stack");
                break;
            case 6: 
                printf("Leaving\n");
                break;
            default:
            printf("\nInvalid");
            break;
              

        }

    }while(op!=6);


}
