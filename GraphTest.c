#include <stdio.h>
#include "Graph.h"
#include "print.h"
#include "header.h"
#include "file.h"
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define UBLU "\033[4;34m"
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
    printf("TEST Add Graph:\n\n"); 
 
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
    printf("Vertex Count: ");
    if ( graph->vertex_count == 5 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "A", "B" );
    printf("isAdjacent A and B: ");
    if ( isAdjacent( graph, "A", "B" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);
    
    addEdge( graph, "A", "D" );
    printf("isAdjacent A and D: ");
    if ( isAdjacent( graph, "A", "D" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "A", "E" );
    printf("isAdjacent A and E: ");
    if ( isAdjacent( graph, "A", "E" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "B", "E" );
    printf("isAdjacent B and E: ");
    if ( isAdjacent( graph, "B", "E" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "B", "C" );
    printf("isAdjacent B and C: ");
    if ( isAdjacent( graph, "B", "C" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "E", "C" );
    printf("isAdjacent E and C: ");
    if ( isAdjacent( graph, "E", "C" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "C", "D" );
    printf("isAdjacent C and D: ");
    if ( isAdjacent( graph, "C", "D" ) == TRUE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("isAdjacent A and C: ");
    if ( isAdjacent( graph, "A", "C" ) == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("isAdjacent C and A: ");
    if ( isAdjacent( graph, "C", "A" ) == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("isAdjacent B and D: ");
    if ( isAdjacent( graph, "B", "D" ) == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("isAdjacent D and B: ");
    if ( isAdjacent( graph, "D", "B" ) == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("isAdjacent D and E: ");
    if ( isAdjacent( graph, "D", "E" ) == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("isAdjacent E and D: ");
    if ( isAdjacent( graph, "E", "D" ) == FALSE )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Edge Count: ");
    if ( graph->edge_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST Display As List:\n\n"); 
    displayAsList( graph ); 

/* ====================================================== */

    printf("\n======================================\n");
    printf("TEST Display As Matrix:\n\n"); 
    displayAsMatrix( graph ); 

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
 
    /* Vertex count should remain the same and no changes are done */
    printf("Vertex Count: ");
    if ( graph->vertex_count == 5 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

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

    printf("%sgraph%s\n", UBLU, RESET);
    graph = createGraph();
    addVertex( graph, "A", &A, 'c' );
    addVertex( graph, "B", &B, 'c' );
    addVertex( graph, "C", &C, 'c' );
    addVertex( graph, "D", &D, 'c' );
    addVertex( graph, "E", &E, 'c' );
    printf("Vertex Count: ");
    if ( graph->vertex_count == 5 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "A", "B" );
    addEdge( graph, "A", "D" );
    addEdge( graph, "A", "E" );
    addEdge( graph, "B", "E" );
    addEdge( graph, "B", "C" );
    addEdge( graph, "E", "C" );
    addEdge( graph, "C", "D" );
    printf("Edge Count: ");
    if ( graph->edge_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("BFS: ");
    bfs( graph );
    printf("\n");
    freeGraph( graph );


    printf("%sgraph_2%s\n", UBLU, RESET);
    graph_2 = createGraph();
    addVertex( graph_2, "A", &A, 'c' );
    addVertex( graph_2, "B", &B, 'c' );
    addVertex( graph_2, "C", &C, 'c' );
    addVertex( graph_2, "D", &D, 'c' );
    addVertex( graph_2, "E", &E, 'c' );
    addVertex( graph_2, "F", &F, 'c' );
    addVertex( graph_2, "G", &G, 'c' );
    printf("Vertex Count: ");
    if ( graph_2->vertex_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

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
    printf("Edge Count: ");
    if ( graph_2->edge_count == 10 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);
    printf("BFS: ");
    bfs( graph_2 );
    printf("\n");
    freeGraph( graph_2 );


    printf("%sgraph_3%s\n", UBLU, RESET);
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
    printf("Vertex Count: ");
    if ( graph_3->vertex_count == 9 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);
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
    printf("Edge Count: ");
    if ( graph_3->edge_count == 15 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("BFS: ");
    bfs( graph_3 ); 
    printf("\n");
    freeGraph( graph_3 );

/* ====================================================== */
    printf("\n======================================\n");
    printf("TEST DFS\n\n");

    printf("%sgraph%s\n", UBLU, RESET);
    graph = createGraph();
    addVertex( graph, "A", &A, 'c' );
    addVertex( graph, "B", &B, 'c' );
    addVertex( graph, "C", &C, 'c' );
    addVertex( graph, "D", &D, 'c' );
    addVertex( graph, "E", &E, 'c' );
    printf("Vertex Count: ");
    if ( graph->vertex_count == 5 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    addEdge( graph, "A", "B" );
    addEdge( graph, "A", "D" );
    addEdge( graph, "A", "E" );
    addEdge( graph, "B", "C" );
    addEdge( graph, "B", "E" );
    addEdge( graph, "C", "D" );
    addEdge( graph, "E", "C" );
    printf("Edge Count: ");
    if ( graph->edge_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("DFS: ");
    dfs( graph );
    printf("\n");
    freeGraph( graph );    

    printf("%sgraph_2%s\n", UBLU, RESET);
    graph_2 = createGraph();
    addVertex( graph_2, "A", &A, 'c' );
    addVertex( graph_2, "B", &B, 'c' );
    addVertex( graph_2, "C", &C, 'c' );
    addVertex( graph_2, "D", &D, 'c' );
    addVertex( graph_2, "E", &E, 'c' );
    addVertex( graph_2, "F", &F, 'c' );
    addVertex( graph_2, "G", &G, 'c' );
    printf("Vertex Count: ");
    if ( graph_2->vertex_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

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
    printf("Edge Count: ");
    if ( graph_2->edge_count == 10 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("DFS: ");
    dfs( graph_2 );
    printf("\n");
    freeGraph( graph_2 );

    printf("%sgraph_3%s\n", UBLU, RESET);
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
    printf("Vertex Count: ");
    if ( graph_3->vertex_count == 10 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

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
    printf("Edge Count: ");
    if ( graph_3->edge_count == 15 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("DFS: ");
    dfs( graph_3 ); 
    printf("\n");
    freeGraph( graph_3 );

/* ====================================================== */
    printf("\n======================================\n");
    printf("TEST Read Graph From File: \n\n");

    printf("%sgraph_1.txt%s\n", UBLU, RESET);
    graph = readGraph( "graph_1.txt" );
    printf("Vertex Count: ");
    if ( graph->vertex_count == 5 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Edge Count: ");
    if ( graph->edge_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("BFS: ");
    bfs( graph );
    printf("DFS: ");
    dfs( graph );    
    freeReadGraph( graph );

    printf("\n");

    printf("%sgraph_2.txt%s\n", UBLU, RESET);
    graph = readGraph( "graph_2.txt" );

    printf("Vertex Count: ");
    if ( graph->vertex_count == 7 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("Edge Count: ");
    if ( graph->edge_count == 10 )
        printf("%sPASSED%s\n", GRN, RESET);
    else
        printf("%sFAILED%s\n", RED, RESET);

    printf("BFS: ");
    bfs( graph );
    printf("DFS: ");
    dfs( graph );    
    freeReadGraph( graph );

    return 0;
}
