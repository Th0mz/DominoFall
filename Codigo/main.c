#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

typedef struct graph {
    int vertices, edges;
    LinkedList *graph;
} Graph;


Graph graph;

void initGraph(int vertices, int edges) {
    int i;

    graph.vertices = vertices;
    graph.edges = edges;

    graph.graph = (LinkedList *) malloc(sizeof(LinkedList) * vertices);

    for (i = 0; i < vertices; i++)
        initList(&(graph.graph[i]));
}

void processInput() {
    int vertices, edges, i;
    scanf("%d %d", &vertices, &edges);

    initGraph(vertices, edges);

    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push(&(graph.graph[u - 1]), v - 1);
    }

}

int main() {
    int i;  
    processInput();
    
    for (i = 0; i < graph.vertices; i ++){
        printf("i = %d   ", i + 1);
        print(graph.graph[i]); 
    }

    for (i = 0; i < graph.vertices; i++)
        destroy(&(graph.graph[i]));

    return 0;   
}