#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define MAXSIZE 5

struct queue{
    int array[MAXSIZE];
    int begin, end, acc;
};

Queue *createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(!q){
        return NULL;
    }else{
        q->begin=0;
        q->end = -1;
        q-> acc=0;

    } 
    return q;
}


int isFull(Queue *q){
    return q->acc==MAXSIZE;
}



int isEmpty(Queue *q){
    return q->acc==0;
}



int enqueue(Queue *q, int value){
    if(isFull(q)) return ERROR;
    else {
        q->end= (q->end+1) % MAXSIZE;
        q->array[q->end] = value;
        q->acc++;
        return SUCCESS;
    }

};



int dequeue(Queue *q, int *value){
    if(isEmpty(q)) return ERROR;
    else {
        *value = q->array[q->begin];
        q->begin = (q->begin+1) % MAXSIZE;
        q->acc--;
        return SUCCESS;


    }

};
int getFirst(Queue *q , int *value){
    if(isEmpty(q)) return ERROR;
    *value = q->array[q->begin];
    return SUCCESS;

};
void freeQueue(Queue *q){
    free(q);

};

void displayQueue(Queue *q){
    if(isEmpty(q)) printf("TA VAZIA MEU\n");

    else {
        int i = q->begin;
        for(int cont =0; cont <= q->acc; cont++){
            printf("%d \n", q->array[i]);
            i = (i+1) %MAXSIZE;
        }


    }  

};