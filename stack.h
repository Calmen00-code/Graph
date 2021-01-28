#ifndef STACK
#define STACK

#include "LinkedList.h"

LinkedList *createStack();
void push( LinkedList *, void *, char );
void *top( LinkedList * );
void *pop( LinkedList * );
int isStackEmpty( LinkedList * );
void freeStack( LinkedList * );

#endif
