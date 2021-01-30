#ifndef GRAPH
#define GRAPH

#include "LinkedList.h"
#include "header.h"

typedef struct Graph
{
    LinkedList *vertices;
    int vertex_count;
    int edge_count;
} Graph;

typedef struct GraphVertex
{
    LinkedList *adjList;
    char label[STR];
    void *value;
    char type;
    int visited;
} GraphVertex; 

Graph* createGraph();
void addVertex( Graph*, char[], void*, char );
void addEdge( Graph*, char[], char[] );
int hasVertex( Graph*, char[] );
int getVertexCount();
int getEdgeCount();
GraphVertex* getVertex( Graph*, char[] );
LinkedList* getAdjacent( Graph*, char[] );
int isAdjacent( Graph*, char[], char[] );
int hasAdjacent( LinkedList*, char[] );
void printAdjList( LinkedList* );
void displayAsList();
void displayAsMatrix();
void freeGraph( Graph* );
void freeReadGraph( Graph* );
void setNew( Graph* );
void bfs( Graph* );
void dfs( Graph* );
int hasNewVertex( LinkedList * );
GraphVertex* getNewVertex( LinkedList * );

#endif
