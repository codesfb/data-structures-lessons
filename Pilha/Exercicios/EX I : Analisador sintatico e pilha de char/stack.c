#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAX_SIZE 5
//Array implementation 
struct stack{
    char item[MAX_SIZE];
    int top;
};

Stack *createStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(!s) return NULL;
    s->top =-1;
    return s;
};

int isFull(Stack *s){
    return s->top==MAX_SIZE-1;
}

int isEmpty(Stack *s){
    return s->top==-1;
}

int push(Stack *s, char value){
    if(!s || isFull(s) ) return ERROR;
    s->item[ ++s->top] = value;
    return SUCCESS;

}

int pop(Stack *s, char *value){
    if(!s || isEmpty(s)) return ERROR;
    return (*value =   s->item[ s->top],s->top--,SUCCESS);

}

int top(Stack *s, char *value) {
    return (isEmpty(s)) ? ERROR : (*value = s->item[s->top], SUCCESS);
}




int showStack(Stack *s){
    if(!s || isEmpty(s)) return ERROR;
    for(int i =s->top; i >=0;i--){
        printf("[%d]\n", s->item[i]);
        
	}
    return SUCCESS;
}

void freee(Stack *s){
        free(s);
}


