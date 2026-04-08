#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#define ERROR 0
#define SUCCESS 1


typedef struct stack Stack;

Stack *createStack(int capacity);
int push(Stack *s, Aluno *a);
int pop(Stack *s, Aluno **AlunoRemovido);
int top(Stack *s, Aluno **topValue);
int showStack(Stack *s);
void liberarPilha(Stack *s);
