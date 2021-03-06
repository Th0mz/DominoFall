#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
#include "graph.h"

#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 1

void processInput(Graph *graph) {
    
    int vertices, edges, i;
    scanf("%d %d", &vertices, &edges);

    initGraph(graph, vertices, edges);

    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        push(&(graph->outGoingEdges[u - 1]), v - 1);
    }

}

int calculateLargestPath(Graph graph, int *sources, int sourcesSize) {
    /* Calculates the overall largest path in the hole graph */
    int i;

    /* DEBUG : int time = 0; */
    
    /* color[v] = State of vertice v:
        - WHITE : Not visited
        - GRAY : Being processed
        - BLACK : Processed
    */
    char *color = (char*) malloc(sizeof(char) * graph.vertices);

    /* longestPath[v] = longest path from v */
    int *longestPath = (int*) malloc(sizeof(int) * graph.vertices);

    /* Current vertice that is being process */
    int visitingVertice;
    
    /* visitingVertice adjacencies */
    LinkedList adj;
    node *adjVertice;

    /* Longest path between all adjacencies */
    int longestAdjPath;


    LinkedList stack;
    initList(&stack);

    /* Setup, all vertices start:
        - Unvisited (color = white)
        - Longest Path = -Infinity 
    */
    for (i = 0; i < graph.vertices; i++) {
         color[i] = WHITE;
         longestPath[i] = -INFINITY;
    }

    /* For each source do a modified DFS to calculate 
       the largest path from source to all the reachable 
       vertices 
    */
    for (i = 0; i < sourcesSize; i++) {
        /* Insert the starting vertice in the stack */
        push(&stack, sources[i]);
        
        while (isEmpty(stack) != TRUE) {
            visitingVertice = stack.head->value;

            if (color[visitingVertice] == WHITE) {
                /* Vertice wasnt visited yet so visit it */
                
                /* DEBUG : printf("Node = %d -> Init Time = %d\n", visitingVertice + 1, ++time); */
                color[visitingVertice] = GRAY;

                adj = getAdj(graph, visitingVertice);
                for (adjVertice = adj.head; adjVertice != NULL; adjVertice = adjVertice->next) {
                    if (color[adjVertice->value] == WHITE) 
                        push(&stack, adjVertice->value);
                }

            } else {
                /* Vertice was completely visited so calculate 
                   finish it and calculate the largest path */
                   
                visitingVertice = pop(&stack);
                if (color[visitingVertice] == GRAY) {
                    /* DEBUG : printf("Node = %d -> End Time = %d\n", visitingVertice + 1, ++time); */
                    color[visitingVertice] = BLACK;

                    /* Calculate the finished vertice longest path
                        Vertice is black => All of his childs where 
                        processed */
                    adj = getAdj(graph, visitingVertice);

                    /* Is a sink => LongestPath from a sink = 0 */
                    if (isEmpty(adj)) 
                        longestPath[visitingVertice] = 1;
                    
                    /* Check which adjacent vertice was the highest longestPath so 
                        the visitingVertice longestPath his child biggest path + 1 */
                    longestAdjPath = -INFINITY;
                    for (adjVertice = adj.head; adjVertice != NULL; adjVertice = adjVertice->next) {
                        if (longestPath[adjVertice->value] > longestAdjPath)
                            longestAdjPath = longestPath[adjVertice->value];
                    }

                    /* Set the visiting vertice longestPath */
                    longestPath[visitingVertice] = longestAdjPath + 1;
                }
    
            }             
        }
    }

    /* Check which source has the biggest largest path */
    int overallLongestPath = - INFINITY;
    for (i = 0; i < sourcesSize; i++) {
        if (overallLongestPath < longestPath[sources[i]])
            overallLongestPath = longestPath[sources[i]];
    }

    free(color);
    free(longestPath);

    return overallLongestPath + 1;  
}


int main() {
    
    int k, l;
    
    Graph graph;
    int *sources;  
    
    processInput(&graph);
    sources = getSources(graph, &k);

    l = calculateLargestPath(graph, sources, k);
    printf("%d %d\n", k, l);

    destroyGraph(&graph);
    free(sources);
    return 0;   
}