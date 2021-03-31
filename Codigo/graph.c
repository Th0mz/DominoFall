#include "graph.h"

void initGraph(Graph *graph, int vertices, int edges) {
    /* Initialization of the graph properties */
    int i;

    graph->vertices = vertices;
    graph->edges = edges;

    graph->outGoingEdges = (LinkedList *) malloc(sizeof(LinkedList) * vertices);
    graph->inGoingEdges = (LinkedList *) malloc(sizeof(LinkedList) * vertices);

    for (i = 0; i < vertices; i++) {
        initList(&(graph->outGoingEdges[i]));
        initList(&(graph->inGoingEdges[i]));
    }
}

int getNumberSources(Graph graph) {
    /* Gets the total number of sources in the graph */
    int i;
    int numberOfSources = 0;

    for (i = 0; i < graph.vertices; i++) {
        if (graph.inGoingEdges[i].head == NULL) {
            numberOfSources++;
        }
            
    }
    
    return numberOfSources;
}

int* getSources(Graph graph, int numberOfSources) {
    int i;
    int sourceIndex = 0;
    int *sources = (int*) malloc(sizeof(int) * numberOfSources);

    for (i = 0; sourceIndex < numberOfSources; i++) {
        if (graph.inGoingEdges[i].head == NULL) {
            sources[sourceIndex] = i;
            sourceIndex++;
        }
    }

    return sources;
}

LinkedList getAdj(Graph graph, int vertice) {
    return graph.outGoingEdges[vertice];
}


void destroyGraph(Graph *graph) {
    /* Frees the memory associated with the graph */
    int i;
    
    for (i = 0; i < graph->vertices; i++){
        destroyList(&(graph->outGoingEdges[i]));
        destroyList(&(graph->inGoingEdges[i]));
    }    

    free(graph->outGoingEdges);
    free(graph->inGoingEdges);
}