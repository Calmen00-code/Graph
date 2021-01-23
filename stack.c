#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

LinkedList* createStack()
{
    LinkedList *stack = createLinkedList();
    return stack;
}

void push( LinkedList *stack, void *data )
{
    if( stack != NULL )
        insertStart( stack, data );
}

void* top( LinkedList *stack )
{
    void *data = NULL;
    data = peekFirst( stack );
    return data;
}

void* pop( LinkedList *stack )
{
    void *data = NULL;
    data = removeStart(stack);
    return data;
}

int isEmpty( LinkedList *queue )
{
    int empty = FALSE;
    if( queue->head == NULL )
        empty = TRUE;

    return empty;
}

void freeStack( LinkedList *stack )
{
    freeLinkedList(stack);
}
