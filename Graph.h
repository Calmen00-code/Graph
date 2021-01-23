#ifndef GRAPH
#define GRAPH

#include "LinkedList.h"
#include "GraphVertex.h"

typedef struct Graph
{
    LinkedList *vertices;
} Graph;

Graph* createGraph();
void addVertex( Graph*, char[], void* );
void addEdge( Graph*, char[], char[] );
int hasVertex( Graph*, char[] );
int getVertexCount();
int getEdgeCount();
GraphVertex* getVertex( Graph*, char[] );
LinkedList* getAdjacent( Graph*, char[] );
int isAdjacent( char[], char[] );
void displayAsList();
void displayAsMatrix();
void freeGraph( Graph* );

#endif
