#include <stdio.h>
#include <stdlib.h>
#include "Fracao.h"
#include "Fracao.c"



int main(){
	//cria as frações 
	Fracao *f1 = criarFracao(3,4);
	Fracao *f2 = criarFracao(1,2);

	//soma as frações 
	Fracao *soma = somarFracao(f1, f2);

	//imprime
	printf("Fração 1: %d / %d \n", obterNumerador(f1), obterDenominador(f1));
	printf("Fração 2: %d / %d \n", obterNumerador(f2), obterDenominador(f2));
	printf("Fração Soma : %d / %d \n", obterNumerador(soma), obterDenominador(soma));
	
	printf("Decimal : %.2f \n", converterParaDecimal(soma));
	
	
	//libera memoria;
	liberarFracao(f1);
	liberarFracao(f2);
	liberarFracao(soma);
	
	
	//mudança no vscode para conseguir compilar tasks.json .vscode args ${workspacerFolder}/* .c 
	return 0;
}
