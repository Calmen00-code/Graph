#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "header.h"

LinkedList* createQueue()
{
    LinkedList *queue = createLinkedList();
    return queue;
}

void enqueue( LinkedList *queue, void *data, char dataType )
{
    if( queue != NULL )
        insertLast( queue, data, dataType );
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

int isQueueEmpty( LinkedList *queue )
{
    int empty = FALSE;
    if( queue->count == 0 )
        empty = TRUE;

    return empty;
}

void freeQueue( LinkedList *queue )
{
    freeLinkedList( queue );
}
