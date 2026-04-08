#include <stdio.h>
#include <stdlib.h>
#define ERROR 0
#define SUCCESS 1


typedef struct stack Stack;

Stack *createStack();
int push(Stack *s, char value);
int pop(Stack *s, char *value);
int top(Stack *s, char *value);
int showStack(Stack *s);
int isEmpty(Stack *s);






