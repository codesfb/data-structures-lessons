#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define SUCCESS 1


typedef struct stack Stack;

Stack *createStack(int capacity);
int push(Stack *s, int value);
int pop(Stack *s, int *removedValue);
int top(Stack *s, int *topValue);
int showStack(Stack *s);






