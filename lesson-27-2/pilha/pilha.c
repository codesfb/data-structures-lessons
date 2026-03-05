
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"



struct pilha
{
  int item[MAXTAM];
  int topo;
};

Pilha *criarPilha()
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  if (p != NULL)
  {
    p->topo = -1;
  }
  return p;
};

int pilhaCheia(Pilha *p)
{
  return p->topo == MAXTAM - 1;
}

int pilhaVazia(Pilha *p)
{
  return p->topo == -1;
}

int push(Pilha *p, int n)
{
  if (pilhaCheia(p))
  {
    return ERROR;
  }
  else
  {

    p->topo++;
    p->item[p->topo] = n;
    return n;
  }
};

int pop(Pilha *p, int *valor)
{
  if (pilhaVazia(p))
  {
    return ERROR;
  }
  else
  {

    *valor = p->item[p->topo];
    p->topo--;
    return SUCCESS;
  }
};

int peek(Pilha *p, int *valor)
{
  if (pilhaVazia(p))
  {
    return ERROR;
  }
  else
  {
    *valor = p->item[p->topo];
    return SUCCESS;
  }
}

void destroy(Pilha *p)
{
  free(p);
};

void mostrarPilha(Pilha *p)
{
  if (pilhaVazia(p))
  {
    printf("Pilha vazia\n");
  }
  else
  {
    printf("Pilha: [");
    for (int i = p->topo; i >= 0; i--)
    {
      printf("%d ", p->item[i]);
    }
    printf("]\n");
  }
}
