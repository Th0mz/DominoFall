#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"


int main() {
    LinkedList list;
    initList(&list);

    push(&list, 5);
    push(&list, 4);
    push(&list, 3);
    push(&list, 2);
    push(&list, 1);
    
    print(&list);
    destroy(&list);
    
/*
    int numDominos, connections;
    scanf("%d %d", &numDominos, &connections);

    for (int i = 0; i < connections; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
    }   
    */
   
    return 0;   
}