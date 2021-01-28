#include <stdio.h>
#include "Graph.h"
#include "print.h"
#include "header.h"
#include "file.h"
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

void printList( LinkedList *list )
{ 
    LinkedListNode *listNd = list->head;

    while ( listNd != NULL ) {
        printCharacter( ((GraphVertex *)(listNd->data))->value );
        listNd = listNd->next;
    }
    printf("\n");    
}

int main(int argc, char *argv[])
{
    char A = 'A', B = 'B', C = 'C', D = 'D', E = 'E';
    char F = 'F', G = 'G', H = 'H', I = 'I', J = 'J'; 
    int exist = 0;
    Graph *graph = createGraph(), *graph_2 = NULL, *graph_3 = NULL;
    GraphVertex *vertex = NULL;
    LinkedList *adjList = NULL;

/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST addVertex:\n\n"); 
 
    addVertex( graph, "A", &A, 'c' );
    printf("Add A: %sPASSED%s\n", GRN, RESET);
    addVertex( graph, "B", &B, 'c' );
    printf("Add B: %sPASSED%s\n", GRN, RESET);
    addVertex( graph, "C", &C, 'c' );
    printf("Add C: %sPASSED%s\n", GRN, RESET);
    addVertex( graph, "D", &D, 'c' );
    printf("Add D: %sPASSED%s\n", GRN, RESET);
    addVertex( graph, "E", &E, 'c' );
    printf("Add E: %sPASSED%s\n", GRN, RESET);

    addEdge( graph, "A", "B" );
    addEdge( graph, "A", "D" );
    addEdge( graph, "A", "E" );
    addEdge( graph, "B", "E" );
    addEdge( graph, "B", "C" );
    addEdge( graph, "E", "C" );
    addEdge( graph, "C", "D" );

/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST Add Existing Vertex\n\n");
 
    printf("A: ");
    addVertex( graph, "A", &A, 'c' );
    printf("B: ");
    addVertex( graph, "B", &B, 'c' );
    printf("C: ");
    addVertex( graph, "C", &C, 'c' );
    printf("D: ");
    addVertex( graph, "D", &D, 'c' );
    printf("E: ");
    addVertex( graph, "E", &E, 'c' );
 
/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST hasVertex\n\n");
    
    printf("A: ");
    exist = hasVertex( graph, "A" );
    if( exist == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    exist = hasVertex( graph, "B" );
    printf("B: ");
    if( exist == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    exist = hasVertex( graph, "C" );
    printf("C: ");
    if( exist == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    exist = hasVertex( graph, "D" );
    printf("D: ");
    if( exist == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    exist = hasVertex( graph, "E" );
    printf("E: ");
    if( exist == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    exist = hasVertex( graph, "0" );
    printf("Invalid: ");
    if( exist == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST getVertex\n\n");

    printf("A: ");
    vertex = getVertex( graph, "A" );
    printCharacter( vertex->value );
    printf("\n");

    printf("B: ");
    vertex = getVertex( graph, "B" );
    printCharacter( vertex->value );
    printf("\n");
    
    printf("C: ");
    vertex = getVertex( graph, "C" );
    printCharacter( vertex->value );
    printf("\n");

    printf("D: ");
    vertex = getVertex( graph, "D" );
    printCharacter( vertex->value );
    printf("\n");

    printf("E: ");
    vertex = getVertex( graph, "E" );
    printCharacter( vertex->value );
    printf("\n");

    printf("Invalid: ");
    vertex = getVertex( graph, "1" );
    printf("\n");

/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST getAdjacent\n\n");

    printf("A: ");
    adjList = getAdjacent( graph, "A" ); 
    printAdjList( adjList );
   
    printf("B: ");
    adjList = getAdjacent( graph, "B" );
    printAdjList( adjList );

    printf("C: ");
    adjList = getAdjacent( graph, "C" );
    printAdjList( adjList );

    printf("D: ");
    adjList = getAdjacent( graph, "D" );
    printAdjList( adjList );

    printf("E: ");
    adjList = getAdjacent( graph, "E" );
    printAdjList( adjList );
    freeGraph(graph);

/* ====================================================== */
    printf("\n======================================\n");
    printf("TEST BFS\n\n");
    graph = createGraph();

    addVertex( graph, "A", &A, 'c' );
    addVertex( graph, "B", &B, 'c' );
    addVertex( graph, "C", &C, 'c' );
    addVertex( graph, "D", &D, 'c' );
    addVertex( graph, "E", &E, 'c' );

    addEdge( graph, "A", "B" );
    addEdge( graph, "A", "D" );
    addEdge( graph, "A", "E" );
    addEdge( graph, "B", "E" );
    addEdge( graph, "B", "C" );
    addEdge( graph, "E", "C" );
    addEdge( graph, "C", "D" );
    printf("graph: ");
    bfs( graph );
    freeGraph( graph );

    graph_2 = createGraph();
    addVertex( graph_2, "A", &A, 'c' );
    addVertex( graph_2, "B", &B, 'c' );
    addVertex( graph_2, "C", &C, 'c' );
    addVertex( graph_2, "D", &D, 'c' );
    addVertex( graph_2, "E", &E, 'c' );
    addVertex( graph_2, "F", &F, 'c' );
    addVertex( graph_2, "G", &G, 'c' );

    addEdge( graph_2, "A", "B" );
    addEdge( graph_2, "A", "C" );
    addEdge( graph_2, "A", "D" );
    addEdge( graph_2, "A", "E" );
    addEdge( graph_2, "B", "E" );
    addEdge( graph_2, "C", "D" );    
    addEdge( graph_2, "D", "F" );
    addEdge( graph_2, "E", "F" );
    addEdge( graph_2, "E", "G" );
    addEdge( graph_2, "F", "G" );
    printf("graph_2: ");
    bfs( graph_2 );
    freeGraph( graph_2 );

    graph_3 = createGraph();
    addVertex( graph_3, "A", &A, 'c' );
    addVertex( graph_3, "B", &B, 'c' );
    addVertex( graph_3, "C", &C, 'c' );
    addVertex( graph_3, "D", &D, 'c' );
    addVertex( graph_3, "E", &E, 'c' );
    addVertex( graph_3, "F", &F, 'c' );
    addVertex( graph_3, "G", &G, 'c' );
    addVertex( graph_3, "H", &H, 'c' );
    addVertex( graph_3, "I", &I, 'c' );
    addVertex( graph_3, "J", &J, 'c' );

    addEdge( graph_3, "A", "B" );
    addEdge( graph_3, "A", "C" );
    addEdge( graph_3, "A", "D" );
    addEdge( graph_3, "B", "E" );
    addEdge( graph_3, "C", "F" );
    addEdge( graph_3, "D", "E" );    
    addEdge( graph_3, "D", "F" );
    addEdge( graph_3, "D", "H" );
    addEdge( graph_3, "E", "G" );
    addEdge( graph_3, "F", "I" );
    addEdge( graph_3, "G", "H" );
    addEdge( graph_3, "H", "I" );
    addEdge( graph_3, "G", "J" );
    addEdge( graph_3, "H", "J" );
    addEdge( graph_3, "I", "J" );
    printf("graph_3: ");
    bfs( graph_3 ); 
    freeGraph( graph_3 );

/* ====================================================== */
    printf("\n======================================\n");
    printf("TEST DFS\n\n");
    graph = createGraph();

    addVertex( graph, "A", &A, 'c' );
    addVertex( graph, "B", &B, 'c' );
    addVertex( graph, "C", &C, 'c' );
    addVertex( graph, "D", &D, 'c' );
    addVertex( graph, "E", &E, 'c' );

    addEdge( graph, "A", "B" );
    addEdge( graph, "A", "D" );
    addEdge( graph, "A", "E" );
    addEdge( graph, "B", "C" );
    addEdge( graph, "B", "E" );
    addEdge( graph, "C", "D" );
    addEdge( graph, "E", "C" );
    printf("graph: ");
    dfs( graph );
    freeGraph( graph );    

    graph_2 = createGraph();
    addVertex( graph_2, "A", &A, 'c' );
    addVertex( graph_2, "B", &B, 'c' );
    addVertex( graph_2, "C", &C, 'c' );
    addVertex( graph_2, "D", &D, 'c' );
    addVertex( graph_2, "E", &E, 'c' );
    addVertex( graph_2, "F", &F, 'c' );
    addVertex( graph_2, "G", &G, 'c' );

    addEdge( graph_2, "A", "B" );
    addEdge( graph_2, "A", "C" );
    addEdge( graph_2, "A", "D" );
    addEdge( graph_2, "A", "E" );
    addEdge( graph_2, "B", "E" );
    addEdge( graph_2, "C", "D" );    
    addEdge( graph_2, "D", "F" );
    addEdge( graph_2, "E", "F" );
    addEdge( graph_2, "E", "G" );
    addEdge( graph_2, "F", "G" );
    printf("graph_2: ");
    dfs( graph_2 );
    freeGraph( graph_2 );

    graph_3 = createGraph();
    addVertex( graph_3, "A", &A, 'c' );
    addVertex( graph_3, "B", &B, 'c' );
    addVertex( graph_3, "C", &C, 'c' );
    addVertex( graph_3, "D", &D, 'c' );
    addVertex( graph_3, "E", &E, 'c' );
    addVertex( graph_3, "F", &F, 'c' );
    addVertex( graph_3, "G", &G, 'c' );
    addVertex( graph_3, "H", &H, 'c' );
    addVertex( graph_3, "I", &I, 'c' );
    addVertex( graph_3, "J", &J, 'c' );

    addEdge( graph_3, "A", "B" );
    addEdge( graph_3, "A", "C" );
    addEdge( graph_3, "A", "D" );
    addEdge( graph_3, "B", "E" );
    addEdge( graph_3, "C", "F" );
    addEdge( graph_3, "D", "E" );    
    addEdge( graph_3, "D", "F" );
    addEdge( graph_3, "D", "H" );
    addEdge( graph_3, "E", "G" );
    addEdge( graph_3, "F", "I" );
    addEdge( graph_3, "G", "H" );
    addEdge( graph_3, "H", "I" );
    addEdge( graph_3, "G", "J" );
    addEdge( graph_3, "H", "J" );
    addEdge( graph_3, "I", "J" );
    printf("graph_3: ");
    dfs( graph_3 ); 
    freeGraph( graph_3 );

/* ====================================================== */
    printf("\n======================================\n");
    printf("TEST Read Graph From File: \n\n");
    printf("graph_1.txt:\n");
    graph = readGraph( "graph_1.txt" ); 

    printf("BFS: ");
    bfs( graph );

    printf("DFS: ");
    dfs( graph );
    
    
    freeReadGraph( graph );

    graph = readGraph( "graph_2.txt" );
    dfs( graph );
    freeReadGraph( graph );

    return 0;
}
