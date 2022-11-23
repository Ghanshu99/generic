#ifndef __TM_DLL_C__

#define __TM_DLL_C__ 123

#include<stdlib.h>

#include<tm_common.h>

#include<tm_dll.h>

DoublyLinkedList *createDoublyLinkedList(bool *success)

{

DoublyLinkedList *doublyLinkedList;

if(success) *success=false;

doublyLinkedList=(DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));

if(doublyLinkedList==NULL) return NULL;

doublyLinkedList->start=NULL;

doublyLinkedList->end=NULL;

doublyLinkedList->size=0;

if(success) *success=true;

return doublyLinkedList;

}

 

void addToDoublyLinkedList(DoublyLinkedList *doublyLinkedList,void *ptr,bool *success)

{

DoublyLinkedListNode *node;

if(success) *success=false;

if(doublyLinkedList==NULL) return;

node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));

if(node==NULL) return;

node->ptr=ptr;

node->next=NULL;

if(doublyLinkedList->start==NULL)
{
doublyLinkedList->start=node;
doublyLinkedList->end=node;
}

else

{

doublyLinkedList->end->next=node;
node->previous=doublyLinkedList->end;
doublyLinkedList->end=node;

}

doublyLinkedList->size++;

if(success) *success=true;

}

 

void destroyDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

{

DoublyLinkedListNode *node;

if(doublyLinkedList==NULL) return;

while(doublyLinkedList->start!=NULL)

{

node=doublyLinkedList->start;

doublyLinkedList->start=doublyLinkedList->start->next;

free(node);

}

free(doublyLinkedList);

}

 

 

int getSizeOfDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

{

if(doublyLinkedList==NULL) return 0;

return doublyLinkedList->size;

}

 

void clearDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

{

DoublyLinkedListNode *node;

if(doublyLinkedList==NULL) return;

while(doublyLinkedList->start!=NULL)

{

node=doublyLinkedList->start;

doublyLinkedList->start=doublyLinkedList->start->next;

free(node);

}
doublyLinkedList->end=NULL;
doublyLinkedList->size=0;

if(doublyLinkedList) free(doublyLinkedList);

}

 

void insertIntoDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,void *ptr,bool *success)

{

DoublyLinkedListNode *node,*p1,*p2;

int x;

if(success) *success=false;

if(doublyLinkedList==NULL) return;

if(index<0 || index>doublyLinkedList->size) return;

if(doublyLinkedList->size==index)

{

addToDoublyLinkedList(doublyLinkedList,ptr,success);

return;

}

node=(DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));

if(node==NULL) return;

node->ptr=ptr;

node->next=NULL;

if(index==0)

{

node->next=doublyLinkedList->start;

doublyLinkedList->start=node;

doublyLinkedList->size++;

if(success) *success=true;

return;

}

x=0;

p1=doublyLinkedList->start;

while(x<index)

{

p2=p1;

p1=p1->next;

x++;

}

node->next=p1;

p2->next=node;

doublyLinkedList->size++;

if(success) *success=true;

}

 

void * removeFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)

{

DoublyLinkedListNode *p1,*p2;

int x;

void *ptr;

if(success) *success=false;

if(doublyLinkedList==NULL) return NULL;

if(index<0 || index>=doublyLinkedList->size) return NULL;

p1=doublyLinkedList->start;

x=0;

while(x<index)

{

p2=p1;

p1=p1->next;

x++;

}

ptr=p1->ptr;

if(doublyLinkedList->start==p1 && doublyLinkedList->end==p1)

{

doublyLinkedList->start=NULL;

doublyLinkedList->end=NULL;

}

else if(doublyLinkedList->start==p1)

{

doublyLinkedList->start=doublyLinkedList->start->next;

}

else if(doublyLinkedList->end==p1)

{

p2->next=NULL;

doublyLinkedList->end=p2;

}

else

{

p2->next=p1->next;

}

if(success) *success=true;

doublyLinkedList->size--;

free(p1);

return ptr;

}

 

void traverseDoublyLinkedList(DoublyLinkedList *doublyLinkedList)

{}

void * getFromDoublyLinkedList(DoublyLinkedList *doublyLinkedList,int index,bool *success)

{

DoublyLinkedListNode *node;

int x;

if(success) *success=false;

if(doublyLinkedList==NULL) return NULL;

if(index<0 || index>=doublyLinkedList->size) return NULL;

node=doublyLinkedList->start;

x=0;

while(x<index)

{

node=node->next;

x++;

}

if(success) *success=true;

return node->ptr;

}

 

void appendToDoublyLinkedList(DoublyLinkedList *targetDoublyLinkedList,DoublyLinkedList *sourceDoublyLinkedList,bool *success)

{

DoublyLinkedListNode *node,*s,*e,*t;

bool done;

if(success) *success=false;

if(targetDoublyLinkedList==NULL) return;

if(sourceDoublyLinkedList==NULL || sourceDoublyLinkedList->size==0)

{

if(success) *success=true;

return;

}

s=NULL;

e=NULL;

done=true;

t=sourceDoublyLinkedList->start;

while(t!=NULL)

{

node=(DoublyLinkedListNode *)malloc(sizeof(DoublyLinkedListNode));

if(node==NULL)

{

done=false;

}

node->ptr=t->ptr;

node->next=NULL;

if(s==NULL)

{

s=node;

e=node;

}

else

{

e->next=node;

e=node;

}

if(done==false)

{

while(s!=NULL)

{

node=s;

s=s->next;

free(node);

}

return;

}

t=t->next;

}

if(targetDoublyLinkedList->start==NULL)

{

targetDoublyLinkedList->start=s;

targetDoublyLinkedList->end=e;

targetDoublyLinkedList->size=sourceDoublyLinkedList->size;

}

else

{

targetDoublyLinkedList->end->next=s;

targetDoublyLinkedList->end=e;

targetDoublyLinkedList->size+=sourceDoublyLinkedList->size;

}

if(success) *success=true;

}

 

DoublyLinkedListIterator getDoublyLinkedListIterator(DoublyLinkedList *doublyLinkedList,bool *success)

{

DoublyLinkedListIterator doublyLinkedListIterator;

if(success) *success=false;

doublyLinkedListIterator.node=NULL;

if(doublyLinkedList->start==NULL) return doublyLinkedListIterator;

doublyLinkedListIterator.node=doublyLinkedList->start;

if(success) *success=true;

return doublyLinkedListIterator;

}

bool hasNextInDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator)

{

if(doublyLinkedListIterator==NULL) return false;
if(doublyLinkedListIterator->node==NULL) return false;
return true;

}

void * getNextElementFromDoublyLinkedList(DoublyLinkedListIterator *doublyLinkedListIterator,bool *success)

{

void *ptr=NULL;

if(success) *success=false;

if(doublyLinkedListIterator==NULL || doublyLinkedListIterator->node==NULL)

{

return ptr;

}

ptr=doublyLinkedListIterator->node->ptr;

doublyLinkedListIterator->node=doublyLinkedListIterator->node->next;

if(success) *success=true;

return ptr;

}

 

/*

void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,bool *success)

{

SinglyLinkedListNode *node,*p1,*ns,*ne;

ns=NULL;

ne=NULL;

int size=0;

if(success) *success=false;

if(targetSinglyLinkedList==NULL) return;

if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)

{

if(success) *success=true;

return;

}

p1=sourceSinglyLinkedList->start;

while(p1!=NULL)

{

node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));

if(node==NULL) break;

node->ptr=p1->ptr;

node->next=NULL;

if(ns==NULL && ne==NULL)

{

ns=node;

ne=node;

}

else

{

ne->next=node;

ne=node;

}

size++;

p1=p1->next;

}

if(size!=sourceSinglyLinkedList->size) return;

 

if(targetSinglyLinkedList->start==NULL)

{

targetSinglyLinkedList->start=ns;

targetSinglyLinkedList->end=ne;

}

else

{

targetSinglyLinkedList->end->next=ns;

targetSinglyLinkedList->end=ne;

}

targetSinglyLinkedList->size=targetSinglyLinkedList->size+size;

}

*/

#endif 
