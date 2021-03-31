#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
#include "graph.h"

#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

Graph graph;

void processInput() {
    int vertices, edges, i;
    scanf("%d %d", &vertices, &edges);

    initGraph(&graph, vertices, edges);

    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        push(&(graph.outGoingEdges[u - 1]), v - 1);
        push(&(graph.inGoingEdges[v - 1]), u - 1);
    }

}

void dfs(Graph graph, int *order, int orderSize) {
    int i, time = 0;
    
    int color[graph.vertices];
    LinkedList adj;
    node *adjVertice;
    int visitingVertice;

    LinkedList stack;
    initList(&stack);

    for (i = 0; i < graph.vertices; i++) {
         color[i] = WHITE;
    }

    for (i = 0; i < orderSize; i++) {
        if (color[order[i]] == 0) {
            /* Insert the root in the stack */
            push(&stack, order[i]);
            while (isEmpty(stack) != TRUE) {
                visitingVertice = stack.head->value;

                if (color[visitingVertice] == WHITE) {
                    color[visitingVertice] = GRAY;
                    printf("Node = %d -> Init Time = %d\n", visitingVertice + 1, ++time);

                    adj = getAdj(graph, visitingVertice);
                    for (adjVertice = adj.head; adjVertice != NULL; adjVertice = adjVertice->next) {
                        if (color[adjVertice->value] == WHITE) 
                            push(&stack, adjVertice->value);
                    }

                } else {
                    visitingVertice = pop(&stack);
                    if (color[visitingVertice] == GRAY) {
                        printf("Node = %d -> End Time = %d\n", visitingVertice + 1, ++time);
                        color[visitingVertice] = BLACK;
                    }
                }
            }             
        }
    }
}




int main() {
    int i;
    int k;
    int *sources;  
    processInput();

    k = getNumberSources(graph);
    sources = getSources(graph, k);

    printf("Sources:\n");
    for (i = 0; i < k; i++)
        printf("%d ", sources[i] + 1);

    printf("\n");

    dfs(graph, sources, k);


    printf("k = %d\n", k);

    printf("Vertices:\n");
    for (i = 0; i < graph.vertices; i ++){
        printf("i = %d   ", i + 1);
        print(graph.outGoingEdges[i]); 
    }

    destroyGraph(&graph);
    free(sources);
    return 0;   
}