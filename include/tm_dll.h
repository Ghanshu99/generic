#ifndef __TM_DLL_H__

#define __TM_DLL_H__123

#include<tm_common.h>

typedef struct _$_TM_DLL_NODE

{

void *ptr;

struct _$_TM_DLL_NODE *next;
struct _$_TM_DLL_NODE *previous;
}DoublyLinkedListNode;

 

typedef struct _$_TM_DLL

{

struct _$_TM_DLL_NODE *start;

struct _$_TM_DLL_NODE *end;

int size;

}DoublyLinkedList;

 

typedef struct _$_TM_DLL_ITREATOR

{

DoublyLinkedListNode *node;

}DoublyLinkedListIterator;


typedef struct _$_TM_DLL_REVERSE_ITREATOR

{

DoublyLinkedListNode *node;

}DoublyLinkedListReverseIterator;
 

 

 

DoublyLinkedList *createDoublyLinkedList(bool *success);

void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success);

void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success);

void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success);

void traverseDoublyLinkedList(DoublyLinkedList *doublyLinkedList);

void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success);

void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *suucess);

DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success);

bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator);

void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success);

DoublyLinkedListReverseIterator getDoublyLinkedListReverseIterator(DoublyLinkedList *doublyLinkedList,bool *success);

bool hasPreviousInDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator);

void * getPreviousElementFromDoublyLinkedList(DoublyLinkedListReverseIterator *doublyLinkedListReverseIterator,bool *success);

#endif
