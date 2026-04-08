#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int isAVallidCode(char *arquivo){
    FILE *fp;
    fp = fopen(arquivo,"r");
    /* Arquivo ASCII, para leitura */
    if(!fp)
    {
        printf( "Erro na abertura do arquivo");
        exit(0);
    }

    Stack *cs = createStack();
    char c;
    while((c = getc(fp) ) != EOF) {
       if(c == '{'){
            push(cs,'{');

       }else if(c == '}'){
            if(isEmpty(cs)) return ERROR;
            else pop(cs, &c);
       }

        if(c == '('){
            push(cs,'(');

       }else if(c == ')'){
            if(isEmpty(cs)) return ERROR;
            else pop(cs, &c);
       }
    }

    if(!isEmpty(cs)) return ERROR;

    fclose(fp);
    return SUCCESS;

}

int main(){
    if(isAVallidCode("arquivo.txt")){
        printf("Código VÁLIDO: Chaves balanceadas corretamente.\n");
    }else{
        printf("Código INVÁLIDO: Chaves desbalanceadas!\n");
       
    }       
}
