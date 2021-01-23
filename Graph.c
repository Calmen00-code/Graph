#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "stack.h"
#include "queue.h"

/*
FUNCTION: createGraph
IMPORT: none
EXPORT: Pointer of the graph
*/
Graph* createGraph()
{
    Graph *graph = malloc(sizeof(Graph));
    graph->vertices = createLinkedList();
    return graph;
}

/*
FUNCTION: addVertex
IMPORT: graph (Graph Pointer), addLabel (String), addValue (void Pointer)
EXPORT: none
*/
void addVertex( Graph* graph, char addLabel[], void* addValue )
{
    GraphVertex *newVertex = malloc(sizeof(GraphVertex));
    newVertex->adjList = createLinkedList();
    strcpy(newVertex->label, addLabel);
    newVertex->value = addValue;
    newVertex->visited = FALSE;

    insertLast( graph->vertices, newVertex );
}

/*
FUNCTION: addEdge
IMPORT: graph (Graph Pointer), Label for both vertex (String)
EXPORT: none
*/
void addEdge( Graph *graph, char label_1[], char label_2[] )
{
    GraphVertex *vertex_1 = NULL, *vertex_2 = NULL;

    if ( hasVertex(graph, label_1) == FALSE ) 
        printf("Vertex \"%s\" does not exist\n", label_1);
    else if ( hasVertex(graph, label_2) == FALSE )
        printf("Vertex \"%s\" does not exist\n", label_2);
    else
    {
        vertex_1 = getVertex( graph, label_1 );
        vertex_2 = getVertex( graph, label_2 );
        insertLast( vertex_1->adjList, vertex_2 );    /* Store vertex_2 in the linked list of vertex_1 */
        insertLast( vertex_2->adjList, vertex_1 );    /* Store vertex_1 in the linked list of vertex_2 */
    }
}

/*
FUNCTION: getVertex
IMPORT: graph (Graph Pointer), getLabel (String)
EXPORT: theVertex (Graph Vertex)
*/
GraphVertex* getVertex( Graph* graph, char getLabel[] )
{
    LinkedList* theList = graph->vertices; 
    LinkedListNode* listNode = theList->head;
    GraphVertex *theVertex = NULL;

    if ( hasVertex(graph, getLabel) == FALSE ) 
        printf("Vertex \"%s\" does not exist\n", getLabel);
    else
    {
        /* ASSERTION: Iterate until List Node was found */
        while ( strcmp( ((GraphVertex *)(listNode->data))->label, getLabel ) != 0 )
            listNode = listNode->next;

        theVertex = (GraphVertex *)(listNode->data);
    }
    return theVertex;
}

/*
FUNCTION: getAdjacent
IMPORT: graph (Graph Pointer), adjLabel (String)
EXPORT: retList (LinkedList)
*/
LinkedList* getAdjacent( Graph *graph, char adjLabel[] )
{
    LinkedList *theList = graph->vertices, *retList = NULL;
    LinkedListNode *listNode = theList->head;
    
    /* ASSERTION: Iterate until the Node was found */
    while( strcmp( ((GraphVertex *)(listNode->data))->label, adjLabel ) != 0 )
        listNode = listNode->next;

    retList = ((GraphVertex *)(listNode->data))->adjList;

    return retList;
}

/*
FUNCTION: hasVertex
IMPORT: graph (Graph Pointer), hasLabel (String)
EXPORT: exist (Integer -> Represents Boolean)
*/
int hasVertex( Graph *graph, char hasLabel[] )
{
    LinkedList* theList = graph->vertices; 
    LinkedListNode* listNode = theList->head;
    int exist = FALSE;

    /* ASSERTION: Iterate until List Node was found OR
                  last node (Tail) */
    while ( listNode != NULL &&
            strcmp( ((GraphVertex *)(listNode->data))->label, hasLabel ) != 0 )
        listNode = listNode->next;

    if( listNode != NULL )
        exist = TRUE;

    return exist;
}

/*
FUNCTION: bfs
IMPORT: graph (Graph Pointer)
EXPORT: none
*/
void bfs( Graph* graph )
{
    GraphVertex *v = NULL, *w = NULL;   /* v = current vertex, w = adjacent of v */
    LinkedList *adjList = NULL; LinkedListNode *adjNode = NULL; 
    LinkedList *queue = graph->vertices;
    enqueue( queue, queue->head );
 
    while( isEmpty( queue ) != TRUE )
    {
        v = dequeue( queue );   /* Returning next unvisited Graph Vertex */
        adjList = getAdjacent( graph, v->label );   /* Get all adjacent vertex of v */
        w = v;  /* Will be marked as OLD */ 
        adjNode = adjList->head;

        /* ASSERTION: When adjacent of v is all VISITED */
        while( w->visited != TRUE && adjNode != NULL )
        {
            enqueue( queue, adjNode );
            printf("%s ", w->label);
            w->visited = TRUE;          /* w is marked as OLD */
            adjNode = adjNode->next;
            w = (GraphVertex *)(adjNode->data);
        }
    }
}
