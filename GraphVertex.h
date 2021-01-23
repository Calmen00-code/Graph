#ifndef GRAPH_VERTEX
#define GRAPH_VERTEX

#define STR_LEN 100

#include "Graph.h"
#include "LinkedList.h"

typedef struct GraphVertex
{
    LinkedList *adjList;
    char label[STR_LEN];
    void *value;
    int visited;
} GraphVertex; 

char* getLabel();
void *getValue();
LinkedList* getAdjacent();
/* void addEdge( GraphVertex* ); */
int getVisited();
char* toString();
void freeGraphVertex( GraphVertex* );

#endif
