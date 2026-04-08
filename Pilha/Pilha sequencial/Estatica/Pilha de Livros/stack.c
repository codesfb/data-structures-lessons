#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 5
//Static implementation 
struct stack{
    Book *item[MAX_SIZE];
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

int push(Stack *s, Book *b){
    if(!s || isFull(s) ) return ERROR;
    s->item[ ++s->top] = b;
    return SUCCESS;

}

int pop(Stack *s, Book *removedBook){
    if(!s || isEmpty(s)) return ERROR;
    return (removedBook =   s->item[ s->top],s->top--,SUCCESS);

}

int top(Stack *s, Book *b) {
    return (isEmpty(s)) ? ERROR : (b = s->item[s->top], SUCCESS);
}




int showStack(Stack *s){
    if(!s || isEmpty(s)) return ERROR;
    
    for(int i =s->top; i >=0;i--){
        printf("\nTitle:%s\nAutor:%s\nEditora:%s\nYear:%d\n______________________________________\n"
        ,getTitle(s->item[i]),getAutor(s->item[i]), getEditora(s->item[i]), getYear(s->item[i]));        
	}
    
    return SUCCESS;
}

void freee(Stack *s){
        free(s);
}


