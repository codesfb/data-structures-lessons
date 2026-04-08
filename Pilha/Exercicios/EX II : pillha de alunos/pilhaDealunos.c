#include <stdio.h>
#include <stdlib.h>
#include "pilhaDealunos.h"


#define MAX_SIZE 5
//Dynamic  implementation 
struct stack{
    Aluno **item;
    int top;
    int capacity;
};

Stack *createStack(int capacity){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s) {
        s->item = (Aluno **)malloc(capacity*sizeof(Aluno *));
        if(!s->item) {
            free(s);
            return NULL;
        }
    }
    s->top =-1;
    s->capacity=capacity;
    return s;
};

int isFull(Stack *s){
    return s->top == s->capacity-1;
}

int isEmpty(Stack *s){
    return s->top==-1;
}


int increaseCapacity(Stack *s){
    if(!s) return  ERROR;
    int newcapacity = s->capacity*2;
    Aluno **newArray = realloc(s->item, newcapacity*sizeof(Aluno *));
    if(newArray==NULL) return ERROR;

    s->item = newArray;
    s->capacity = newcapacity;
    return SUCCESS;
}

int push(Stack *s, Aluno *a){
    if(!s) return ERROR;
      if(isFull(s)){
        if (increaseCapacity(s)==ERROR) return ERROR;
    } 

    s->item[ ++s->top] = a;
    return SUCCESS;

}

int pop(Stack *s, Aluno **AlunoRemovido){
    if(!s || isEmpty(s)) return ERROR;
    *AlunoRemovido = s->item[ s->top];
    s->top--;
    return SUCCESS;

}

int top(Stack *s, Aluno **a) {
    return (isEmpty(s)) ? ERROR : (*a = s->item[s->top], SUCCESS);
}




int showStack(Stack *s){
    if(!s || isEmpty(s)) return ERROR;
    for(int i =s->top; i >=0;i--){
        printf("[%s] [%s]\n", obterNome(s->item[i]), obterProntuario(s->item[i]));
        
	}
    return SUCCESS;
}

void liberarPilha(Stack *s){
    if(!s) return;
    free(s->item);
    free(s);
        
}
