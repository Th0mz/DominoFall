#ifndef _LISTA_LIGADA_
#define _LISTA_LIGADA_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *proximo;
    int elemento;
} node;


typedef struct linkedList {

    node *inicio;
} LinkedList;

/* Declaracao de funcoes */

void initList(LinkedList *lista);
void push(LinkedList *lista, int elemento);
void print(LinkedList lista);

void destroy(LinkedList *lista);

#endif