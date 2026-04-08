#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define SUCCESS 1


typedef struct stack Stack;

Stack *createStack();
int push(Stack *s, int *value);
int pop(Stack *s, int *value);
int top(Stack *s, int *value);
int showStack(Stack *s);






