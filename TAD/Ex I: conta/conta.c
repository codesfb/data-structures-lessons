#include <stdio.h>
#include <stdlib.h>
#include "conta.h"



struct conta
{
    int num;
    float saldo;    
};




Conta *criaConta(int num,  float valor){
    Conta *conta = (Conta*)malloc(sizeof(Conta)); 
    if(!conta) return NULL;
    conta->num = num;
    conta->saldo = valor;
    return conta;

};


int depositar(Conta *conta, float valor){
    if(!conta) return ERROR;
    if(valor <= 0) return ERROR;
    return (conta->saldo+= valor,SUCCESS);
};


int sacar(Conta *conta, float valor){
    if(!conta) return ERROR;
    if(valor <= 0) return ERROR;
    if (conta->saldo < valor) return ERROR;
    return (conta->saldo-=valor,SUCCESS); 

};
int transferir(Conta *conta, Conta *conta2, float valor){
    if(!conta) return ERROR;
    if(valor <= 0) return ERROR;
    if (conta->saldo < valor) return ERROR;
    conta->saldo-= valor;
    conta2->saldo+= valor;
    return SUCCESS;

};
int obterNum(Conta *conta){
    return conta->num;
};
float obterSaldo(Conta *conta){
    return conta->saldo;
};

void liberarConta(Conta *conta){
    free(conta);
}