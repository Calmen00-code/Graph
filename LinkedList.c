#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "print.h"

LinkedList* createLinkedList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void insertStart( LinkedList* list, void* inData, char valueType )
{
    /* Creating the node first */
    LinkedListNode *newNd = malloc(sizeof(LinkedListNode));
    newNd->data = inData;
    newNd->type = valueType;
    newNd->next = NULL;

    /* If head and tail is NULL, then allocate the newNd as head and tail */
    if ( list->head == NULL && list->tail == NULL )
    {
        list->head = newNd;
        list->tail = newNd;
    }
    else
    {
        /* newNd will be head, so it has new next pointer */
        newNd->next = list->head;
        list->head = newNd;
    }
    list->count++;
}

void insertLast( LinkedList* list, void *inData, char valueType )
{
    /* Creating the node first */
    LinkedListNode *newNd = malloc(sizeof(LinkedListNode));
    newNd->data = inData;
    newNd->type = valueType;
    newNd->next = NULL;

    /* If head and tail is NULL, then allocate the newNd as head and tail */
    if ( list->head == NULL && list->tail == NULL )
    {
        list->head = newNd;
        list->tail = newNd;
    }
    else
    {
        list->tail->next = newNd;   /* Current tail has new connection */
        list->tail = newNd;         /* new tail is updated */
    }
    list->count++;
}

void* peekFirst( LinkedList *list )
{   
    LinkedListNode *lastNd = NULL; 

    if ( list != NULL )
        lastNd = list->head;
    return lastNd;
}

void* peekLast( LinkedList *list )
{
    LinkedListNode *lastNd = NULL;

    if ( list != NULL )
        lastNd = list->tail;
    return lastNd;
}

void* removeStart( LinkedList *list )
{
    LinkedListNode *delNd = NULL;
    void *delData = NULL;

    /* Make sure the list is not empty */
    if ( list->head != NULL && list->tail != NULL )
    {
        if ( list->head == list->tail )
        {
            delNd = list->head;
            delData = delNd->data;
            free(delNd);
            list->head = NULL; list->tail = NULL;
        }
        else
        {
            delNd = list->head;         /* Remove start is removing from head */
            list->head = delNd->next;   /* Move to next pointer */
            delData = delNd->data;
            free(delNd); delNd = NULL;
        }
        list->count--;
    }
    return delData;
}

void* removeLast( LinkedList *list )
{
    LinkedListNode *delNd = NULL, *travelNd = NULL;
    void *delData = NULL;

    /* Make sure the list is not empty */
    if ( list->head != NULL && list->tail != NULL )
    {
        if ( list->head == list->tail )
        {
            delNd = list->head;
            delData = delNd->data;
            free(delNd);
            list->head = NULL; list->tail = NULL;
        }
        else
        {
            delNd = list->tail; /* Remove last is removing from tail */
            travelNd = list->head; /* Traversal starts from head */

            /* Loop stops at the node before the tail */
            while ( travelNd->next != delNd )
                travelNd = travelNd->next;  /* Move to next pointer */

            /* Tail's next always points to NULL */
            travelNd->next = NULL;
            list->tail = travelNd;

            delData = delNd->data;
            free(delNd); delNd = NULL;
        }
        
        list->count--;
    }
    return delData;
}

void printLinkedList( LinkedList *list )
{
    LinkedListNode *printNd = NULL;
    printFunc printPtr;

    /* Checking if the list is NOT EMPTY */
    if ( list != NULL )
    {
        printNd = list->head;

        /* ASSERTION: Iterate until the last node */
        while( printNd != NULL )
        {
            printPtr = getFunc( printNd->type );    /* Get the function pointer based on the value type */
            (*printPtr)(printNd->data);             /* Using the function pointer to call the print function */
            printNd = printNd->next;
        }
    }
    printf("\n");
}

void freeLinkedList( LinkedList *list )
{
    LinkedListNode *currNd, *delNd;

    currNd = list->head;
    while( currNd != NULL )
    {
        delNd = currNd;
        currNd = currNd->next;
        free(delNd); delNd = NULL;
    }
    free(list); list = NULL;
} 
