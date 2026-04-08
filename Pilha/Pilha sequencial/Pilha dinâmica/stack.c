#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define MAX_SIZE 5
//Dynamic  implementation 
struct stack{
    int *item;
    int top;
    int capacity;
};

Stack *createStack(int capacity){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if(s) {
        s->item = (int *)malloc(capacity*sizeof(int));
        if(!s->item) return ERROR;

    }
    s->top =-1;
    s->capacity=capacity;
    return s;
};

int isFull(Stack *s){
    return s->top < s->capacity-1;
}

int isEmpty(Stack *s){
    return s->top==-1;
}


int increaseCapacity(Stack *s){
    if(!s) return  ERROR;
    int newcapacity = s->capacity*2;
    int *newArray = realloc(s->item, newcapacity*sizeof(int));
    if(newArray==NULL) return ERROR;

    s->item = newArray;
    s->capacity = newcapacity;
}

int push(Stack *s, int value){
    if(!s) return ERROR;
      if(isFull(s)){
        if (increaseCapacity(s)==ERROR) return ERROR;
    } 

    s->item[ ++s->top] = value;
    return SUCCESS;

}

int pop(Stack *s, int *value){
    if(!s || isEmpty(s)) return ERROR;
    return (*value =   s->item[ s->top],s->top--,SUCCESS);

}

int top(Stack *s, int *value) {
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
    free(s->item);
    free(s);
        
}


