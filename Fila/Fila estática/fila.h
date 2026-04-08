#define ERROR 0
#define SUCCESS 1
#define MAXSIZE 5
typedef struct queue Queue;

Queue *createQueue();
int enqueue(Queue *q, int value);
int dequeue(Queue *q, int *value);
int getFront(Queue *q);
void freeQueue(Queue *q);
void showQueue(Queue *f);

