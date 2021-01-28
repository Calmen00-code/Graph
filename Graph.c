#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "stack.h"
#include "queue.h"
#include "header.h"
#include "print.h"

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
void addVertex( Graph* graph, char addLabel[], void* addValue, char valueType )
{
    GraphVertex *newVertex = malloc(sizeof(GraphVertex));
    newVertex->adjList = createLinkedList();
    strcpy(newVertex->label, addLabel);
    newVertex->value = addValue;
    newVertex->type = valueType;
    newVertex->visited = FALSE;

    if ( hasVertex( graph, addLabel ) == FALSE )
        insertLast( graph->vertices, newVertex, valueType );
    else
        printf("Vertex \"%s\" already exist\n", addLabel);
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

        /* Store vertex_2 in the linked list of vertex_1 */
        insertLast( vertex_1->adjList, vertex_2, vertex_2->type );    

        /* Store vertex_1 in the linked list of vertex_2 */
        insertLast( vertex_2->adjList, vertex_1, vertex_1->type );    
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
    LinkedList *theList = NULL, *retList = NULL;
    LinkedListNode *listNode = NULL; 

    if ( graph != NULL )
    {
        theList = graph->vertices;
        listNode = theList->head;

        /* ASSERTION: Iterate until the Node was found */
        while( listNode->next != NULL && 
               strcmp( ((GraphVertex *)(listNode->data))->label, adjLabel ) != 0 )
            listNode = listNode->next;

        retList = ((GraphVertex *)(listNode->data))->adjList;
    }
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
FUNCTION: printAdjList
IMPORT: adjList (LinkedList)
EXPORT: none
*/
void printAdjList( LinkedList *adjList )
{
    LinkedListNode *listNd = adjList->head;
    GraphVertex *adjVertex = NULL;
    printFunc printPtr;

    /* ASSERTION: Traverse until the last node of the adjacency list */
    while ( listNd != NULL ) 
    {
        adjVertex = (GraphVertex *)(listNd->data);  /* adjList is a lists of graph vertex */
        printPtr = getFunc( adjVertex->type );      /* Using vertex type, and get the print function pointer */
        (*printPtr)(adjVertex->value);              /* Using the pointer, call the correct print function */
        listNd = listNd->next;
    }
    printf("\n");    
}

/*
FUNCTION: bfs
IMPORT: graph (Graph Pointer)
EXPORT: none
*/
void bfs( Graph* graph )
{
    GraphVertex *v = NULL; 
    LinkedList *adjList = NULL; 
    LinkedListNode *theNode = NULL, *adjNode = NULL;

    LinkedList *queue = createQueue();    
    theNode = graph->vertices->head;           /* Traversal will start on the head of vertices */
    enqueue( queue, theNode->data, 'p' ); 

    /* ASSERTION: Stops when all vertex is visited */
    while ( isQueueEmpty( queue ) != TRUE )
    {
        v = (GraphVertex *)dequeue( queue );            /* Returning next current Graph Vertex */
        adjList = getAdjacent( graph, v->label );       /* Get all adjacent vertex of v */
        adjNode = adjList->head;

        /* ASSERTION: When adjacent of v is all VISITED */
        while ( adjNode != NULL )
        {
            if ( v->visited != TRUE )
            {
                printf("%s ", v->label);
                v->visited = TRUE;                      /* Current Vertex is marked as OLD */
                enqueue( queue, adjNode->data, 'p' );
            }
            v = (GraphVertex *)(adjNode->data);
            adjNode = adjNode->next;
        }
    }
    printf("\n");
    freeQueue( queue ); queue = NULL;
}

/*
FUNCTION: dfs
IMPORT: graph (Graph Pointer)
EXPORT: none
*/
void dfs( Graph *graph )
{
    GraphVertex *v = NULL;
    LinkedList *stack = createStack(), *adjList = NULL;
    LinkedListNode *theNode = NULL;

    /* Every vertex will be stored as stack in DFS */
    theNode = graph->vertices->head;
    push( stack, theNode->data, 'p' );
    v = (GraphVertex *)(theNode->data);
    v->visited = TRUE;
    printf("%s ", v->label); 

    /* ASSERTION: Iterate until all vertex is VISITED */
    while ( isStackEmpty( stack ) != TRUE )
    {
        adjList = getAdjacent( graph, v->label );   /* Get the next vertex to visit */

        /* ASSERTION: Check for the next unvisited node */
        while ( hasNewVertex( adjList ) == TRUE )
        {
            v = getNewVertex( adjList );
            printf("%s ", v->label);
            v->visited = TRUE;
            push( stack, v, 'p' );   /* Store the next vertex into stack */
            adjList = getAdjacent( graph, v->label );   /* Get the next vertex to visit */
        }
        v = (GraphVertex *)(pop( stack ));      /* Retrieve the node to check if it was unvisited */
    }         
    printf("\n");
    freeStack( stack );
}

/*
FUNCTION: hasNewVertex
IMPORT: adjList (LinkedList Pointer)
EXPORT: hasNew (Integer)
*/
int hasNewVertex( LinkedList *adjList )
{
    GraphVertex *v = NULL;
    LinkedListNode *listNd = adjList->head;
    int hasNew = FALSE;

    /* ASSERTION: Stop when list reaches tail OR an univisited node has found */
    while ( hasNew == FALSE && listNd != NULL )
    {
        v = (GraphVertex *)(listNd->data);      /* Get the vertex */

        if ( v->visited == FALSE )
            hasNew = TRUE;

        listNd = listNd->next;
    }
    return hasNew;
}

/*
FUNCTION: getNewVertex
IMPORT: adjList (LinkedList Pointer)
EXPORT: newVertex (GraphVertex Pointer)
*/
GraphVertex* getNewVertex( LinkedList *adjList )
{
    GraphVertex *newVertex = NULL;
    LinkedListNode *adjNode = adjList->head;
    int stop = FALSE;

    while ( adjNode != NULL && stop == FALSE )
    {
        newVertex = (GraphVertex *)(adjNode->data);
        if ( newVertex->visited == FALSE )
            stop = TRUE;

        adjNode = adjNode->next;
    }
    return newVertex;
}

/*
FUNCTION: freeGraph
IMPORT: graph (Graph Pointer)
EXPORT: none
*/
void freeGraph( Graph *graph )
{
    LinkedListNode *theNode = graph->vertices->head, *freeNode = NULL;
    GraphVertex *freeVertex = NULL;

    while ( theNode != NULL )
    {
        freeVertex = ((GraphVertex *)(theNode->data));     /* Get the vertex */
        freeLinkedList( freeVertex->adjList );             /* Free the adjList of the vertex */

        freeNode = theNode;                                /* Assign to freeNode so we can use it theNode */
        theNode = theNode->next;
        free( freeNode->data ); freeNode->data = NULL;     /* Free the vertex */ 
        free( freeNode ); freeNode = NULL;                 /* Free the node that stored the vertex */
    }
    free( graph->vertices ); graph->vertices = NULL;
    free( graph ); graph = NULL;
}
