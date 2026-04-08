#include "book.h"
#define ERROR 0
#define SUCCESS 1


typedef struct stack Stack;

Stack *createStack();
int push(Stack *s, Book *b);
int pop(Stack *s, Book *b);
int top(Stack *s, Book *b);
int showStack(Stack *s);






