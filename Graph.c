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
    graph->vertex_count = 0;
    graph->edge_count = 0;
    return graph;
}

/*
FUNCTION: addVertex
IMPORT: graph (Graph Pointer), addLabel (String), addValue (void Pointer)
EXPORT: none
*/
void addVertex( Graph* graph, char addLabel[], void* addValue, char valueType )
{
    GraphVertex *newVertex = NULL;

    if ( hasVertex( graph, addLabel ) == FALSE )
    {
        newVertex = malloc(sizeof(GraphVertex));
        newVertex->adjList = createLinkedList();
        strcpy(newVertex->label, addLabel);
        newVertex->value = addValue;
        newVertex->type = valueType;
        newVertex->visited = FALSE;

        insertLast( graph->vertices, newVertex, valueType );
        graph->vertex_count++;
    }
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
        if ( isAdjacent( graph, label_1, label_2 ) == FALSE )
        {
            insertLast( vertex_1->adjList, vertex_2, vertex_2->type );    
            insertLast( vertex_2->adjList, vertex_1, vertex_1->type );    

            graph->edge_count++;
        }
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
FUNCTION: isAdjacent
IMPORT: graph (Graph Pointer), label_1 (String), label_2 (String)
EXPORT: adjacent (Integer)
PURPOSE: Returns TRUE if label_1 and label_2 is an adjacency vertex to each other
*/
int isAdjacent( Graph* graph, char label_1[], char label_2[] )
{
    LinkedList *adjList_1 = NULL, *adjList_2 = NULL;
    int adjacent = FALSE;

    if ( hasVertex( graph, label_1 ) == TRUE && hasVertex( graph, label_2 ) == TRUE )
    {
        adjList_1 = getAdjacent( graph, label_1 );
        adjList_2 = getAdjacent( graph, label_2 );

        if ( hasAdjacent( adjList_1, label_2 ) == TRUE && hasAdjacent( adjList_2, label_1 ) == TRUE )
            adjacent = TRUE;
    }
    return adjacent;
}

/*
FUNCTION: hasAdjacent
IMPORT: adjList (LinkedList), check_label (String)
EXPORT: exist (Integer)
PURPOSE: Returns TRUE if the vertex of check_label is existed in adjList
*/
int hasAdjacent( LinkedList *adjList, char check_label[] )
{
    LinkedListNode *adjNode = NULL;
    GraphVertex *adjVertex = NULL;
    int exist = FALSE;
    adjNode = adjList->head;

    /* ASSERTION: Traverse through the adjacent list and 
                  check if check_label exist in adjacent vertex */
    while ( adjNode != NULL && exist == FALSE )
    {
        adjVertex = (GraphVertex *)(adjNode->data);
    
        /* Stop the loop if current vertex label is the check_label */
        if ( strcmp(adjVertex->label, check_label) == 0 )
            exist = TRUE;
        else
            adjNode = adjNode->next;
        /* Otherwise, continue to traverse the list */
    }
    return exist;
}

/*
FUNCTION: getAdjacent
IMPORT: graph (Graph Pointer), adjLabel (String)
EXPORT: retList (LinkedList)
PURPOSE: Get the vertex from adjLabel and use the vertex to get the adjacency list
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
PURPOSE: Returns TRUE if the vertex with hasLabel is existed in the graph
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
PURPOSE: Print the adjList value for a vertex
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
FUNCTION: setNew
IMPORT: graph (Graph Pointer)
EXPORT: none
PURPOSE: Set all vertex in the graph to be UNVISITED (For Traversal)
*/
void setNew( Graph *graph )
{
    LinkedList *theList = graph->vertices;
    LinkedListNode *theNode = theList->head;
    GraphVertex *theVertex = NULL;

    /* ASSERTION: Traverse through all the list to set all to unvisited */
    while ( theNode != NULL )
    {
        /* Set current vertex to FALSE (UNVISITED) */
        theVertex = (GraphVertex *)(theNode->data);
        theVertex->visited = FALSE;

        theNode = theNode->next;    /* Traverse to the next node */
    }
}

/*
FUNCTION: bfs
IMPORT: graph (Graph Pointer)
EXPORT: none
PURPOSE: Breath First Search
*/
void bfs( Graph* graph )
{
    printFunc printData;
    GraphVertex *v = NULL; 
    LinkedList *queue = NULL;
    LinkedList *adjList = NULL; 
    LinkedListNode *theNode = NULL, *adjNode = NULL;

    setNew( graph );
    queue = createQueue();    
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
                printData = getFunc( v->type );
                (*printData)(v->value);
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
PURPOSe: Depth First Search
*/
void dfs( Graph *graph )
{
    printFunc printData;
    GraphVertex *v = NULL;
    LinkedList *stack = createStack(), *adjList = NULL;
    LinkedListNode *theNode = NULL;

    setNew( graph );

    /* Every vertex will be stored as stack in DFS */
    theNode = graph->vertices->head;
    push( stack, theNode->data, 'p' );
    v = (GraphVertex *)(theNode->data);
    v->visited = TRUE;
    printData = getFunc( v->type );
    (*printData)(v->value);

    /* ASSERTION: Iterate until all vertex is VISITED */
    while ( isStackEmpty( stack ) != TRUE )
    {
        adjList = getAdjacent( graph, v->label );   /* Get the next vertex to visit */

        /* ASSERTION: Check for the next unvisited node */
        while ( hasNewVertex( adjList ) == TRUE )
        {
            v = getNewVertex( adjList );
            printData = getFunc( v->type );
            (*printData)(v->value);
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
PURPOSE: Returns TRUE if an Adjacent List has an UNVISITED Vertex
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
FUNCTION: displayAsMatrix
IMPORT: graph (Graph Pointer)
EXPORT: none
*/
void displayAsMatrix( Graph *graph )
{   
    LinkedList *rowList = NULL, *colList = NULL;
    LinkedListNode *rowNode = NULL, *colNode = NULL;
    GraphVertex *rowVertex = NULL, *colVertex = NULL;

    rowList = graph->vertices;
    colList = graph->vertices;

    colNode = colList->head;

    printf("\t");
    /* Print column label */
    while ( colNode != NULL )
    {
        colVertex = (GraphVertex *)(colNode->data);
        printf("%s\t", colVertex->label);
        colNode = colNode->next;
    }
    printf("\n");
    
    rowNode = rowList->head;

    /* Print row label */
    while ( rowNode != NULL )
    {
        rowVertex = (GraphVertex *)(rowNode->data);
        printf("%s\t", rowVertex->label);

        colNode = colList->head;

        /* Verify if the current vertex is an adjacent vertex to other vertex in the list */
        while ( colNode != NULL )
        {
            colVertex = (GraphVertex *)(colNode->data);
            if ( isAdjacent( graph, rowVertex->label, colVertex->label ) == TRUE )
                printf("%d\t", ADJACENT);
            else
                printf("%d\t", NOT_ADJACENT); 

            colNode = colNode->next;
        }    
        printf("\n");
        rowNode = rowNode->next;
    }
}

/*
FUNCTION: displayAsList
IMPORT: graph (Graph Pointer)
EXPORT: none
*/
void displayAsList( Graph *graph )
{
    LinkedList *theList = NULL, *adjacentList = NULL;
    LinkedListNode *theNode = NULL, *adjNode = NULL;
    GraphVertex *vertex = NULL, *v = NULL;

    theList = graph->vertices;
    theNode = theList->head;

    /* Traverse through the outermost list */
    while ( theNode != NULL )
    {
        vertex = (GraphVertex *)(theNode->data);    /* Vertex from outermost list */
        printf("%s: ", vertex->label);

        adjacentList = vertex->adjList;
        adjNode = adjacentList->head;

        /* Traverse through the inner list (Adjacent List) */
        while ( adjNode != NULL )
        {
            v = (GraphVertex *)(adjNode->data);
            printf("%s ", v->label);
            adjNode = adjNode->next; 
        }
        printf("\n");
        theNode = theNode->next;
    }
}

/*
FUNCTION: getNewVertex
IMPORT: adjList (LinkedList Pointer)
EXPORT: newVertex (GraphVertex Pointer)
PURPOSE: Get the next UNVISITED Vertex in the Adjacency List IMPORTED
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
PURPOSE: Free all the graph after used
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
        free( freeVertex ); freeVertex = NULL;             /* Free the vertex */ 
        free( freeNode ); freeNode = NULL;                 /* Free the node that stored the vertex */
    }
    free( graph->vertices ); graph->vertices = NULL;
    free( graph ); graph = NULL;
}

/*
FUNCTION: freeReadGraph
IMPORT: graph (Graph Pointer)
EXPORT: none
PURPOSE: Free the graph that was read from the file 
         Because the value of the graph was allocated instead of defined in GraphTest.c
*/
void freeReadGraph( Graph *graph )
{
    LinkedListNode *theNode = graph->vertices->head, *freeNode = NULL;
    GraphVertex *freeVertex = NULL;

    while ( theNode != NULL )
    {
        freeVertex = ((GraphVertex *)(theNode->data));     /* Get the vertex */
        freeLinkedList( freeVertex->adjList );             /* Free the adjList of the vertex */

        freeNode = theNode;                                /* Assign to freeNode so we can use it theNode */
        theNode = theNode->next;
        freeVertex = (GraphVertex*)(freeNode->data);

        free( freeVertex->value ); freeVertex->value = NULL;
        free( freeVertex ); freeVertex = NULL;             /* Free the vertex */ 
        free( freeNode ); freeNode = NULL;                 /* Free the node that stored the vertex */
    }
    free( graph->vertices ); graph->vertices = NULL;
    free( graph ); graph = NULL;
}
