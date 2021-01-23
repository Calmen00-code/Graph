#include <stdio.h>
#include "Graph.h"
#include "print.h"
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
    /*char F = 'F', G = 'G', H = 'H', I = 'I', J = 'J';*/ 
    int exist = 0;
    Graph *graph = createGraph();
    GraphVertex *vertex = NULL;
    LinkedList *adjList = NULL;

    addVertex( graph, "A", &A );
    addVertex( graph, "B", &B );
    addVertex( graph, "C", &C );
    addVertex( graph, "D", &D );
    addVertex( graph, "E", &E );

    addEdge( graph, "A", "B" );
    addEdge( graph, "A", "D" );
    addEdge( graph, "A", "E" );
    addEdge( graph, "B", "E" );
    addEdge( graph, "B", "C" );
    addEdge( graph, "E", "C" );
    addEdge( graph, "C", "D" );

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
    printList( adjList );
    
    printf("B: ");
    adjList = getAdjacent( graph, "B" );
    printList( adjList );

    printf("C: ");
    adjList = getAdjacent( graph, "C" );
    printList( adjList );

    printf("D: ");
    adjList = getAdjacent( graph, "D" );
    printList( adjList );

    printf("E: ");
    adjList = getAdjacent( graph, "E" );
    printList( adjList );
    
    return 0;
}
