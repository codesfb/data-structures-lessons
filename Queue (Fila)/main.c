#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(){
    Queue *q = createQueue();
    if(!q) {
        printf("Não foi possivel criar");
        return 1;
    }
    
    enqueue(q,10);
    enqueue(q,10);
    enqueue(q,10);
    enqueue(q,10);
    enqueue(q,10);
 

    int valor;
    dequeue(q,&valor);
    displayQueue(q);



}