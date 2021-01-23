#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

LinkedList* createQueue()
{
    LinkedList *queue = malloc(sizeof(LinkedList));
    return queue;
}

void enqueue( LinkedList *queue, void *data )
{
    if( queue != NULL )
        insertLast( queue, data );
}

void* dequeue( LinkedList *queue )
{
    void *retData = NULL;
    if( queue != NULL )
        retData = removeStart( queue );

    return retData;
}

void* peek( LinkedList *queue )
{
    void *retData = NULL;
    retData = peekLast( queue );

    return retData;
}

int isEmpty( LinkedList *queue )
{
    int empty = FALSE;
    if( queue->head == NULL )
        empty = TRUE;

    return empty;
}

void freeQueue( LinkedList *queue )
{
    freeLinkedList( queue );
}
