#ifndef QUEUE
#define QUEUE

#include "LinkedList.h"

LinkedList* createQueue();
void enqueue( LinkedList*, void*, char );
void* dequeue( LinkedList* );
void* peek( LinkedList* );
int isQueueEmpty( LinkedList* );
void freeQueue();

#endif
