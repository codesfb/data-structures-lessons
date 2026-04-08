#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



void menu(){
	printf("\n1 - Push generic book");
	printf("\n7 - Push a new book");
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


Book *setBookInfo(){
    char title[100], autor[100],editora[100];
    int year;
    printf("Write to push to the stack:\n");
    printf("Title: ");
    scanf("%s",title);
    printf("autor: ");
    scanf("%s",autor);
    printf("editora: ");
    scanf("%s",editora);  
    printf("year: ");
    scanf("%d",&year);        
    Book *exBook = createBook(title,autor,editora,year);
    return exBook;

}


int main(){
    Stack *pilha = createStack();
    int op, v;
    Book *b;
    do{
		displayStack(pilha,"Current Stack");
		menu();		
        scanf("%d", &op);


        switch(op){
            case 1:
                b = createBook("Sobre a  tranquilidade da vida","Seneca","Abril",2010);
                push(pilha, b)? printf("Added successfuly"):printf("Error: Stack is full");
                break;
            case 7:
                b = setBookInfo(); 
                push(pilha, b)? printf("Added successfuly"):printf("Error: Stack is full");
                break;
            case 2: 
                
                printf("Pop value from the stack:");            
                pop(pilha,b)? printf("Book %s Poped successfuly",getTitle(b)):printf("Error");
                break;
            case 3: 
            
                          
                if(top(pilha,b) == ERROR)printf("Pilha vazia ");
                else printf("Top is:%s", getTitle(b));
                break;
            case 4:
                free(pilha);
                printf("Now the satck is empty\n");
                pilha = createStack();
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
