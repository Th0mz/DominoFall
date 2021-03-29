#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> readInput() {
    /* Transforms the input into a graph 
     represented with an adjacency list */

    int numDominos, connections;
    scanf("%d %d", &numDominos, &connections);
    vector<vector<int>> graph = vector<vector<int>>(numDominos, vector<int>());

    for (int i = 0; i < connections; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1].push_back(v - 1);
    }

    return graph;
}

void DFS(vector<vector<int>> graph) {
    /*

    DFS(G):
        for v in G.V:
            v.pi = NULL
            v.color = white

        time = 0
        for v in G.V
            if v.color == white:
                time = DFSVisit(G, v, time)
    */
}

void DFSVisit(vector<vector<int>> graph, ) {

}

void debugGraph(vector<vector<int>> graph) {
    for (int i = 0; i < graph.size(); i++) {
        printf("%d : ", i + 1);

        for (int j = 0; j < graph[i].size(); j++) {
            printf(" %d", graph[i][j] + 1);
        }
        printf("\n");
    }
}

int main() {
    vector<vector<int>> graph = readInput();
    
    return 0;
}