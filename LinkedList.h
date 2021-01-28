#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct LinkedListNode
{
    struct LinkedListNode *next;
    void *data;
    char type;
} LinkedListNode;

typedef struct LinkedList
{
    struct LinkedListNode *head;
    struct LinkedListNode *tail;
    int count;
} LinkedList;

LinkedList* createLinkedList();
void insertStart( LinkedList*, void*, char );
void insertLast( LinkedList*, void*, char );
void* removeStart( LinkedList* );
void* removeLast( LinkedList* );
void printLinkedList( LinkedList* );
void* peekFirst( LinkedList * );
void* peekLast( LinkedList * );
void freeLinkedList( LinkedList* );

#endif
