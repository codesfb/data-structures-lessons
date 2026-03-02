#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "conta.h"


// typedef struct conta Conta;
// Conta* criarConta(int numero, float saldo);
// void depositar(Conta* conta, float valor);
// void sacar(Conta* conta, float valor);          
// void trnsferir(Conta* contaOrigem, Conta* contaDestino, float valor);
// int obterNumero(Conta* conta);
// float obterSaldo(Conta* conta);

struct conta{
  int num;
  double saldo;

};

Conta* criarConta(int numero, double saldo){
  Conta *conta = (Conta*)malloc(sizeof(Conta));
  if(!conta){
    return NULL;
  }else {
    conta->num= numero;
    conta->saldo=saldo;

  }
  return conta;

}

int depositar(Conta* conta, double valor){
  if(valor > 0){
  conta->saldo +=valor;
    return SUCCESS;
}else{

   return ERROR;
}
};

int sacar(Conta* conta, double valor){
  if(valor > 0 && valor <= conta->saldo){
  conta->saldo -=valor;
    return SUCCESS;
}else{

   return ERROR;
}


}; 

void transferir(Conta* contaOrigem, Conta* contaDestino, double valor) {
    if (sacar(contaOrigem, valor) == SUCCESS) {
        if (depositar(contaDestino, valor) == SUCCESS) {
            printf("%.2f Transferido com sucesso!\n", valor);
        } else {
  
            depositar(contaOrigem, valor); 
            printf("Erro no depósito. Valor de %.2f estornado para a origem.\n", valor);
        }

    } else {
        printf("Transferência negada: Saldo insuficiente na conta de origem.\n");
    }
}

int obterNum(Conta *conta)
{
    if (conta!=NULL)
        return conta->num;
}

double obterSaldo(Conta * conta)
{
    if (conta!=NULL)
        return conta->saldo;
}

void liberarConta(Conta *conta)
{
    free(conta);
}