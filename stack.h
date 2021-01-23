#ifndef STACK
#define STACK

#include "LinkedList.h"

LinkedList *createStack();
void push( LinkedList *, void * );
void *top( LinkedList * );
void *pop( LinkedList * );
int isEmpty( LinkedList * );
void freeStack( LinkedList * );

#endif
