#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif    
}

int main()
{
  Arvore *arvore = criar_arvore();

  if (arvore==NULL){
    printf("Não foi possível alocar memória");
    exit(1);
  }
     

  int op;
  int valor;
  do
  {
    limparTela();
    printf("\n1 - Inserir");
    printf("\n2 - Remover");
    printf("\n3 - Em Ordem");
    printf("\n4 - Pre Ordem");
    printf("\n5 - Pos Ordem");
    printf("\n6 - Maior");
    printf("\n7 - Menor");
    printf("\n8 - (Testes)Prencher arvore com valores padrão");
    printf("\n9 - Encontrar valor e retornar esquerda ou direita");
    printf("\n10 - Liberar Árvore");
    printf("\n0 - Sair");
    printf("\n\nEscolha sua opção: ");
    scanf("%d", &op);
    switch (op)
    {
    case 1:

      printf("\nDigite o valor a ser inserido: ");
      scanf("%d", &valor);
      inserir(arvore, valor);
      break;

    case 2:
      printf("\nDigite o valor a ser removido: ");
      scanf("%d", &valor);
      remover(arvore, valor);
      break;

    case 3:
      percurso_em_ordem(arvore);
      break;

    case 4:
      percurso_pre_ordem(arvore);
      break;

    case 5:
      percurso_pos_ordem(arvore);
      break;
    case 6:
      printf("\nMaior valor da arvore:");
      int biggest = maior(arvore);
      printf("%d", biggest);
      break;
    case 7:
      printf("\nMenor valor da arvore ");
      int minor = menor(arvore);
      printf("%d", minor);
      break;

    case 8:

      int valores_padrao[7]={3,5,9,7,8,10,11};

      for(int i=0;i<7;i++){
        inserir(arvore, valores_padrao[i]);
      }
      printf("\nValores padrão inseridos com sucesso"); 
      break;
    case 9:
      printf("\nDigite o valor a ser encontrado: ");
      scanf("%d", &valor);
      encontrar(arvore,valor);
      break;
    case 10:
      destruir_arvore(arvore);
      break;
    case 0:
    printf("\nSaindo...");
    destruir_arvore(arvore);
    break;

    default:
    printf("\nOpção inválida");
 
    }
    
    // Limpa completamente qualquer sujeira do buffer (incluindo o '\n' do Enter)
    while (getchar() != '\n');
    
    printf("\n\nPressione Enter para continuar...");
    getchar(); // Pausa a tela esperando o usuário dar Enter
  } while (op != 0);
  
  return 0;
}