#include <stdio.h>
#include <stdlib.h>
#include "veiculoEncadeado.h"

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
    Lista *lista = criarListaEncadeada();
    Veiculo *v;


    if (lista == NULL)
    {
        printf("Não foi possível alocar memória");
        exit(1);
    }
    char marca[40];
    char ano[30];
    char placa[30];
    char placaExistente[30];
    int opcao, valor, itemProcurado, resultado;
    do {
        limparTela();
        printf("\n1 - Inserir no início");
        printf("\n2 - Inserir no final");
        printf("\n3 - Inserir após um elemento");
        printf("\n4 - Remover");
        printf("\n5 - Mostrar lista");
        printf("\n6 - Liberar lista");
        printf("\n7 - Sair");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o veiculo(marca, ano, placa) a ser inserido no início: ");

            scanf("%s",marca);
            scanf("%s",ano);
            scanf("%s",placa);
            v=criarVeiculo(marca,placa,ano);
            resultado = inserirInicio(lista, v);
            if (resultado == ERROR)
                printf("\nErro ao inserir");
            else
                printf("\n%s inserido com sucesso no início", marca);
            break;
        
        case 2:
            printf("\nDigite o veiculo(marca, ano, placa) a ser inserido no final: ");

            scanf("%s",marca);
            scanf("%s",ano);
            scanf("%s",placa);
            v=criarVeiculo(marca,placa,ano);
            resultado = inserirFinal(lista, v);
            if (resultado == ERROR)
                printf("\nErro ao inserir");
            else
                printf("\n%s inserido com sucesso no final", marca);
            break;
        
        case 3:
            printf("\nDigite o veiculo(marca, ano, placa) a ser inserido: ");

            scanf("%s",marca);
            scanf("%s",ano);
            scanf("%s",placa);
            v=criarVeiculo(marca,placa,ano);

            printf("\nDigite uma placa existente na lista: ");
            scanf("%s",placaExistente);
            resultado = inserirApos(lista, v, placaExistente);
            if (resultado == ERROR)
                printf("\nErro ao inserir. Elemento não encontrado.");
            else
                printf("\n%s inserido com sucesso após %s", marca, placaExistente);
            break;
        
        case 4:
            printf("\nDigite o valor a ser removido: ");
           
            scanf("%s",placaExistente);
            resultado = remover(lista, placaExistente);
            if (resultado == ERROR)
                printf("\nErro ao remover. Elemento não encontrado.");
            else
                printf("\n%s removido com sucesso", placaExistente);
            break;
        
        case 5:
            mostrar(lista);
            break;
        
        case 6:
            liberarLista(lista);
            printf("\nLista liberada e recriada");
            lista = criarListaEncadeada();
            break;
        
        case 7:
            printf("\nSaindo...");
            liberarLista(lista);
            break;
        
        default:
            printf("\nOpção inválida");
            break;
        }
        getchar();
        getchar();
    } while (opcao != 7);

    return 0;
}