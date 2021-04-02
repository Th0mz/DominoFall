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

LinkedList getAdj(Graph graph, int vertice) {
    return graph.outGoingEdges[vertice];
}

int* getSources(Graph graph, int *numSources) {
    /* Gets all vertices that are sources */
    int i;

    /* numIncomingEdges[v] = number of incoming edges of v */
    int *numIncomingEdges = (int*) malloc(sizeof(int) * graph.vertices);

    *numSources = graph.vertices;
    LinkedList adjencies;
    node *adjVertice;

    /* Calculate the number of incoming edges for all vertices */
    for (i = 0; i < graph.vertices; i++) {

        adjencies = getAdj(graph, i);
        adjVertice = adjencies.head;
        
        for (; adjVertice != NULL; adjVertice = adjVertice->next) {

            if (numIncomingEdges[adjVertice->value] == 0) {
                /* The vertice adjacent vertice is not a source (was a income edge) */
                (*numSources)--;
            }
            
            numIncomingEdges[adjVertice->value]++;
        }
    }

    /* Check which vertices are sources  */
    int sourceIndex = 0;
    int *sources = (int*) malloc(sizeof(int) * (*numSources));

    for (i = 0; sourceIndex < (*numSources); i++) {
        if (numIncomingEdges[i] == 0) {
            sources[sourceIndex] = i;
            sourceIndex++;
        }
    }

    free(numIncomingEdges); 
    return sources;
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