#define ERROR -1
#define SUCCESS 0
typedef struct queue Queue;
Queue *createQueue();
int enqueue(Queue *q, int value);
int dequeue(Queue *q, int *value);
int getFirst(Queue *q , int *value);
void freeQueue(Queue *f);
void displayQueue(Queue *f);