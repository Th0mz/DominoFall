#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int value;
} node;


typedef struct linkedList {

    node *head;
} LinkedList;

/* Function Declaration */

void initList(LinkedList *list);
int pop(LinkedList *list);
void push(LinkedList *list, int value);
int isEmpty(LinkedList list);
void print(LinkedList list);

void destroyList(LinkedList *list);

#endif