#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 1


/* ------------ LINKEDLIST ------------ */
    /* Structures */

typedef struct node
{
    struct node *next;
    int value;
} node;


typedef struct linkedList {

    node *head;
} LinkedList;

    /* Functions */

void initList(LinkedList *list)
{
    /* Initialization of the list as a empty list */
    list->head = NULL;
}

int pop(LinkedList *list) {
    /* Removes the first element in the list */
    node *removedElement;
    int value;

    if (list->head == NULL)
        return -1;

    /* Store locally the fist element so it can be freed */
    removedElement = list->head;
    value = removedElement->value;

    /* Update list head */
    list->head = list->head->next;

    free(removedElement);
    return value;
}

void push(LinkedList *list, int value) {
    /* Adds a new element to the begining of the list */
    node *newNode;

    /* Allocate memory */
    newNode = (node*) malloc(sizeof(node));

    /* Define newNode */
    newNode->value = value;
    newNode->next = list->head;
    
    list->head = newNode;

}

void destroyList(LinkedList *list) {
    /* Frees all the memory associated with the list */
    node *node, *nextNode;

    node = list->head;

    while(node != NULL) {
        nextNode = node->next;
        free(node);
        node = nextNode;
    }
}

int isEmpty(LinkedList list) {
    if (list.head == NULL)
        return 1;
    else
        return 0;
}

void print(LinkedList list) {
    /* Display list */
    node *i;

    for (i = list.head; i != NULL; i = i->next)
        printf("%d ", i->value + 1);

    printf("\n");
}



/* ------------ GRAPH ------------ */
    /* Structure */

typedef struct graph {
    /* Graph representation with adjency list */

    int vertices, edges;
    LinkedList *outGoingEdges;
    LinkedList *inGoingEdges;
} Graph;

    /* Functions */

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



/* ------------ MAIN ------------ */

void processInput(Graph *graph) {
    int vertices, edges, i;
    scanf("%d %d", &vertices, &edges);

    initGraph(graph, vertices, edges);

    for (i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        push(&(graph->outGoingEdges[u - 1]), v - 1);
        push(&(graph->inGoingEdges[v - 1]), u - 1);
    }

}

int largestPath(Graph graph, int *sources, int sourcesSize) {
    /* Calculates the overall largest path in the hole graph */
    int i;

    /* DEBUG : int time = 0; */
    
    /* color[v] = State of vertice v:
        - WHITE : Not visited
        - GRAY : Being processed
        - BLACK : Processed
    */
    int color[graph.vertices];

    /* longestPath[v] = longest path from v */
    int longestPath[graph.vertices];
    int overallLongestPath = - INFINITY;

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

    /*  */
    for (i = 0; i < sourcesSize; i++) {
        if (color[sources[i]] == 0) {
            /* Insert the starting vertice in the stack */
            push(&stack, sources[i]);
            
            while (isEmpty(stack) != TRUE) {
                visitingVertice = stack.head->value;

                if (color[visitingVertice] == WHITE) {
                    color[visitingVertice] = GRAY;
                    /* DEBUG : printf("Node = %d -> Init Time = %d\n", visitingVertice + 1, ++time); */

                    adj = getAdj(graph, visitingVertice);
                    for (adjVertice = adj.head; adjVertice != NULL; adjVertice = adjVertice->next) {
                        if (color[adjVertice->value] == WHITE) 
                            push(&stack, adjVertice->value);
                    }

                } else {
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
    }

    /* Check which source has the biggest largest path */
    for (i = 0; i < sourcesSize; i++) {
        if (overallLongestPath < longestPath[sources[i]])
            overallLongestPath = longestPath[sources[i]];
    }

    return overallLongestPath + 1;  
}


int main() {
    
    int k, l;
    
    Graph graph;
    int *sources;  
    
    processInput(&graph);

    k = getNumberSources(graph);
    sources = getSources(graph, k);

    l = largestPath(graph, sources, k);
    printf("%d %d\n", k, l);


    /*
    DEBUG : 

    printf("Sources:\n");
    for (i = 0; i < k; i++)
        printf("%d ", sources[i] + 1);

    printf("\n");

    printf("Vertices:\n");
    for (i = 0; i < graph.vertices; i ++){
        printf("i = %d   ", i + 1);
        print(graph.outGoingEdges[i]); 
    }

    */

    destroyGraph(&graph);
    free(sources);
    return 0;   
}