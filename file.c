#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "header.h"

Graph* readGraph( char fileName[] )
{
    FILE *readPtr = NULL;
    char label_1[STR] = "", label_2[STR] = "";
    char *value_1 = NULL, *value_2 = NULL;
    Graph* graph = NULL;

    readPtr = fopen( fileName, "r" );
    if ( readPtr == NULL )
        perror("Error while reading file");
    else
    {
        graph = createGraph();
        while ( fscanf( readPtr, "%[^ ] %[^\n]\n", label_1, label_2 ) != EOF )
        { 
            if ( hasVertex( graph, label_1 ) != TRUE )
            {
                value_1 = malloc(sizeof(char) * STR);
                strcpy( value_1, label_1 );
                addVertex( graph, label_1, value_1, 's' );
            }

            if ( hasVertex( graph, label_2 ) != TRUE )
            {
                value_2 = malloc(sizeof(char) * STR);
                strcpy( value_2, label_2 );
                addVertex( graph, label_2, value_2, 's' );
            }

            addEdge( graph, label_1, label_2 );
        }
        fclose( readPtr ); readPtr = NULL;
    }
    return graph;
}
