#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./pilhaFuncs/pilha.h"

/*
Uma das tarefas do analisador sintático do compilador é verificar se
o código possui estruturas balanceadas, como begin-end, {}, () etc.
Faça um programa em C que simule este comportamento. Para
tanto, seu programa deverá abrir e ler um pequeno arquivo que
contenha um código qualquer em C e verificar se este código possui
chaves balanceadas. 
*/
void verificarChaves(char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Pilha *p = criarPilha();
    char c;
    int erro = 0;

    // Lê caractere por caractere até o fim do arquivo (EOF)
    while ((c = fgetc(arq)) != EOF) {
        if (c == '{') {
            push(p, '{');
        } 
        else if (c == '}') {
            if (pilhaVazia(p)) {
                erro = 1; // Tentou fechar sem ter aberto
                break;
            } else {
                pop(p, &c);
            }
        };

        if (c == '(') {
            push(p, '(');
        } 
        else if (c == ')') {
            if (pilhaVazia(p)) {
                erro = 1; // Tentou fechar sem ter aberto
                break;
            } else {
                pop(p, &c);
            }
        };

        
    }

    // Verificação final
    if (erro || !pilhaVazia(p)) {
        printf("Código INVÁLIDO: Chaves desbalanceadas!\n");
    } else {
        printf("Código VÁLIDO: Chaves balanceadas corretamente.\n");
    }

    fclose(arq);
}


int main(){
	
	verificarChaves("codigoExemplo.c");
	
	return 0;
}


