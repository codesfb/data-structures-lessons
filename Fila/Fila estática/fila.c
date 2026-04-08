#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct queue{
    int item[MAXSIZE];
    int begin, end, acc;
};

int isFull(Queue *q){
   return q->acc == MAXSIZE;

}

int isEmpty(Queue *q){
   return q->acc=0;

}

Queue *createQueue(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if(!queue) return NULL;
    queue->begin=0;
    queue->end=-1;
    queue->acc=0;
    return queue;

};

int enqueue(Queue *q, int value){
    if(!q) return ERROR;
    if(isFull(q)) return ERROR;

    q->end = (q->end + 1) % MAXSIZE;
    q->item[q->end] = value;
    q->acc++;

    return SUCCESS;

};
int dequeue(Queue *q, int *value){
    if(!q) return ERROR;
    if(isEmpty(q)) return ERROR;
    *value= q->item[ q->begin];
    q->begin = (q->begin + 1) % MAXSIZE;
    q->acc--;
    return SUCCESS;
};
int getFront(Queue *q){
    return q->item[q->begin];

};

void freeQueue(Queue *q){
    free(q);
};

void showQueue(Queue *f)
{
    if (filaVazia(f))
        printf("Fila vazia");
    else
    {
        int i = f->begin;
        for (int cont = 0; cont < f->acc; cont++)
        {
            printf("Item: %d\n", f->item[i]);
            i = (i + 1) % MAXSIZE;
        }
    }
}