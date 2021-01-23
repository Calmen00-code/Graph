#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* createLinkedList()
{
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

void insertStart( LinkedList* list, void* inData )
{
    /* Creating the node first */
    LinkedListNode *newNd = malloc(sizeof(LinkedListNode));
    newNd->data = inData;
    newNd->next = NULL;

    /* If head and tail is NULL, then allocate the newNd as head and tail */
    if( list->head == NULL && list->tail == NULL )
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

void insertLast( LinkedList* list, void *inData )
{
    /* Creating the node first */
    LinkedListNode *newNd = malloc(sizeof(LinkedListNode));
    newNd->data = inData;
    newNd->next = NULL;

    /* If head and tail is NULL, then allocate the newNd as head and tail */
    if( list->head == NULL && list->tail == NULL )
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

void* removeStart( LinkedList *list )
{
    LinkedListNode *delNd = NULL;
    void *delData = NULL;

    /* Make sure the list is not empty */
    if( list->head != NULL && list->tail != NULL )
    {
        delNd = list->head; /* Remove start is removing from head */
        list->head = delNd->next;   /* Move to next pointer */

        delData = delNd->data;
        free(delNd); delNd = NULL;
        list->count--;
    }
    return delData;
}

void* removeLast( LinkedList *list )
{
    LinkedListNode *delNd = NULL, *travelNd = NULL;
    void *delData = NULL;

    /* Make sure the list is not empty */
    if( list->head != NULL && list->tail != NULL )
    {
        delNd = list->tail; /* Remove last is removing from tail */

        travelNd = list->head; /* Traversal starts from head */

        /* Loop stops at the node before the tail */
        while( travelNd->next != delNd )
            travelNd = travelNd->next;  /* Move to next pointer */

        travelNd->next = NULL;
        list->tail = travelNd;

        delData = delNd->data;
        free(delNd); delNd = NULL;
        list->count--;
    }
    return delData;
}

void freeLinkedList( LinkedList *list )
{
    LinkedListNode *currNd, *delNd;

    currNd = list->head;
    while( currNd != NULL )
    {
        delNd = currNd;
        free(delNd->data); delNd->data = NULL;
        currNd = currNd->next;

        free(delNd); delNd = NULL;
    }
    free(list); list = NULL;
} 
