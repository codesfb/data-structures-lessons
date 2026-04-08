#include <stdio.h>
#include <stdlib.h>
#include "pilhaDealunos.h"



void menu(){
	printf("\n1 - Push aluno");
	printf("\n2 - POP aluno");
	printf("\n3 - Show top aluno");
	printf("\n4 - Freee ");
	printf("\n5 - Show complete stack of alunos");
	printf("\n6 - Sair");
	printf("\nChoose one op: ");
	}

void displayStack(Stack *pilha,char *s){
	 printf("\n=================%s==================\n",s);
     (showStack(pilha)==SUCCESS)? printf("\nStack\n") : printf("Empty\n");
	}

int main(){
    Stack *pilha = createStack(2);
    // Aluno *a1 = criarAluno("Fabio", "898798");
    // Aluno *a2 = criarAluno("a2", "898798");
    // Aluno *a3 = criarAluno("a3", "898798");
    // Aluno *a4 = criarAluno("a4", "898798");


    Aluno *aluno;
    int op, v;
    char nome[40], prontuario[40];
    do{
		displayStack(pilha,"Current Stack");
		menu();		
        scanf("%d", &op);

        
        switch(op){
            case 1:
            
                printf("Aluno to push to the stack:");
                printf("\nNome:");
                scanf("%s", nome);
                printf("\nPronturario:");
                scanf("%s", prontuario);
                aluno = criarAluno(nome, prontuario);
                push(pilha, aluno)? printf("Added successfuly"):printf("Error: Stack is full");
                break;
            case 2: 
                printf("Pop value from the stack:");            
                pop(pilha, &aluno)? printf("%s Poped successfuly",obterNome(aluno)):printf("Error");
                break;
            case 3: 
                if(top(pilha, &aluno)) printf("Top is %s", obterNome(aluno));
                else printf("Error: Stack is empty");
                break;
            case 4:
                liberarPilha(pilha);
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
