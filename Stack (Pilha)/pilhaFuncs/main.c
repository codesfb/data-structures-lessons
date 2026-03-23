#include <stdio.h>
#include <string.h>
// #define ERROR 0
// #define SUCCSSES 1
#include "pilha.h"
void limparTela(){
	
	printf("Precione ENTER para continuar...\n");
	getchar();
	getchar();
	}



void empilhar(Pilha *p, char valor){
	int result = push(p, valor);
  if(result == ERROR){
    printf("Erro ao empilhar\n" );
  }else {

    printf("%c  Empilhado com sucesso \n", valor);
  }
}; 

void desempilhar(Pilha *p, char *valor){
   int result = pop(p, valor);
  if(result == ERROR){
    printf("Erro ao desempilhar\n" );
  }else {

    printf("%c Desempilhado com sucesso  \n", *valor);
  }
}; 

// void limparTela()
// {
// #ifdef _WIN32
//     system("cls");
// #else
//     system("clear"); 
// #endif    
// }

int main()
{
	
 Pilha *pilha = criarPilha();
  if(pilha==NULL){
	printf("Não foi possivel alocar");
	return 1;  
	}
  int opcao;
  do{
    printf("Menu:\n");
    printf("1. Empilhar\n");
    printf("2. Desempilhar\n");
    printf("3. Mostrar Pilha\n");
    printf("4. Mostrar Topo\n");
    printf("5. Destruir Pilha\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
    
    scanf("%d", &opcao);
    
    switch(opcao) {
      case 1: {
        char valor;
        printf("Digite um caractere para empilhar: ");
        scanf(" %c", &valor);
        empilhar(pilha, valor);
        break;
      }
      case 2: {
        char valor;
        desempilhar(pilha, &valor);
        break;
      }
      case 3:
       mostrarPilha(pilha);
        break;
      case 4:
        char valor;
        peek(pilha, &valor);
        printf("Topo: %c\n", valor);
        break;
      case 5:
        destroy(pilha);
        printf("Pilha liberada e recriada");
        pilha=criarPilha();
        break;
      case 6:
        printf("Saindo...\n");
        destroy(pilha);
        break;
      default:
        printf("Opção inválida!\n");
    }
    
    limparTela();
    
  } while(opcao != 6);
	

  
}
