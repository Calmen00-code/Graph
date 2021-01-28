#ifndef GRAPH_VERTEX
#define GRAPH_VERTEX

#include "Graph.h"
#include "LinkedList.h"
#include "header.h"

typedef struct GraphVertex
{
    LinkedList *adjList;
    char label[STR];
    void *value;
    char type;
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
