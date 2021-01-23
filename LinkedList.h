#ifndef LIST
#define LIST

typedef struct LinkedListNode
{
    struct LinkedListNode *next;
    void *data;
} LinkedListNode;

typedef struct LinkedList
{
    struct LinkedListNode *head;
    struct LinkedListNode *tail;
    int count;
} LinkedList;

typedef void(*listFunc)(void*data);

LinkedList* createLinkedList();
void insertStart( LinkedList*, void* );
void insertLast( LinkedList*, void* );
void* removeStart( LinkedList* );
void* removeLast( LinkedList* );
void printLinkedList( LinkedList* );
void freeLinkedList( LinkedList* );

#endif
