#ifndef _GRAPH_
#define _GRAPH_

#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct graph {
    /* Graph representation with adjency list */

    int vertices, edges;
    LinkedList *outGoingEdges;
    LinkedList *inGoingEdges;
} Graph;

/* Function Declaration */
void initGraph(Graph *graph, int vertices, int edges);
int getNumberSources(Graph graph);
int* getSources(Graph graph, int numberOfSources);
LinkedList getAdj(Graph graph, int vertice);

void destroyGraph(Graph *graph);

#endif