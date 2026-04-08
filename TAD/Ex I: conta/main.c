#include <stdio.h>
#include <stdlib.h>
#include "conta.h"


void menu(){
    printf("\n 1-Depositar");
    printf("\n 2- sacar");
    printf("\n 3-Transferir");
    printf("\n 4-Obter Saldo");
    printf("\n 5-Excluir conta");
    printf("\n 6-Sair");
    
    printf("\nEscolha uma opção:");
    
}

int main(){
    Conta * conta1 = criaConta(1, 1000.0);
    Conta * conta2 = criaConta(2, 1000.0);

    int op;
    float valor;
    do{
        menu();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("\nQual valor deseja depositar:");
            scanf("%f", &valor);
            if(depositar(conta1, valor)){
                printf("\nDepesitado com sucesso");
                printf("\nVoce depositou :%.2f", valor);
                printf("\nSaldo :%.2f", obterSaldo(conta1));



            }
            else{ printf("\nErro ao depositar");}
            break;
        case 2:
            printf("\nQual valor deseja sacar:");
            scanf("%f", &valor);
            if(sacar(conta1,valor) ) printf("%f sacado com sucesso o saldo agora é: %f ",valor, obterSaldo(conta1));
            else printf("Erro ao osacar");
            break;
        case 3:
            printf("\nQual valor deseja Transferir:");
            scanf("%f", &valor);
            if(transferir(conta1,conta2, valor) ) {
                
                printf("%f enviado  com sucesso",valor);
                printf("\nSaldo da conta 1: %f", obterSaldo(conta1));
                printf("\nSaldo da conta 2: %f",obterSaldo(conta2));    

            }else printf("Erro ao enviar");
            break;
        case 4:
            printf("\nSaldo da conta 1: %f", obterSaldo(conta1));
            break;
        case 5:
            liberarConta(conta1);
            liberarConta(conta2);
            break;
        case 6:
            printf("Saindo...");
            break;
        default:
            printf("\nValor invalido");
            break;
        }



    }while(op!=6);



}
