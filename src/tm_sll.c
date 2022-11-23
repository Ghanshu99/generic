#ifndef __TM_SLL__C

#define __TM_SLL__C 123

#include<stdlib.h>

#include<tm_common.h>

#include<tm_sll.h>

SinglyLinkedList *createSinglyLinkedList(bool *success)

{

SinglyLinkedList *singlyLinkedList;

if(success) *success=false;

singlyLinkedList=(SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));

if(singlyLinkedList==NULL) return NULL;

singlyLinkedList->start=NULL;

singlyLinkedList->end=NULL;

singlyLinkedList->size=0;

if(success) *success=true;

return singlyLinkedList;

}

 

void addToSinglyLinkedList(SinglyLinkedList *singlyLinkedList,void *ptr,bool *success)

{

SinglyLinkedListNode *node;

if(success) *success=false;

if(singlyLinkedList==NULL) return;

node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));

if(node==NULL) return;

node->ptr=ptr;

node->next=NULL;

if(singlyLinkedList->start==NULL)

{

singlyLinkedList->start=node;

singlyLinkedList->end=node;

}

else

{

singlyLinkedList->end->next=node;

singlyLinkedList->end=node;

}

singlyLinkedList->size++;

if(success) *success=true;

}

 

void destroySinglyLinkedList(SinglyLinkedList *singlyLinkedList)

{

SinglyLinkedListNode *node;

if(singlyLinkedList==NULL) return;

while(singlyLinkedList->start!=NULL)

{

node=singlyLinkedList->start;

singlyLinkedList->start=singlyLinkedList->start->next;

free(node);

}

free(singlyLinkedList);

}

 

 

int getSizeOfSinglyLinkedList(SinglyLinkedList *singlyLinkedList)

{

if(singlyLinkedList==NULL) return 0;

return singlyLinkedList->size;

}

 

void clearSinglyLinkedList(SinglyLinkedList *singlyLinkedList)

{

SinglyLinkedListNode *node;

if(singlyLinkedList==NULL) return;

while(singlyLinkedList->start!=NULL)

{

node=singlyLinkedList->start;

singlyLinkedList->start=singlyLinkedList->start->next;

free(node);

}

singlyLinkedList->size=0;

if(singlyLinkedList) free(singlyLinkedList);

}

 

void insertIntoSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,void *ptr,bool *success)

{

SinglyLinkedListNode *node,*p1,*p2;

int x;

if(success) *success=false;

if(singlyLinkedList==NULL) return;

if(index<0 || index>singlyLinkedList->size) return;

if(singlyLinkedList->size==index)

{

addToSinglyLinkedList(singlyLinkedList,ptr,success);

return;

}

node=(SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));

if(node==NULL) return;

node->ptr=ptr;

node->next=NULL;

if(index==0)

{

node->next=singlyLinkedList->start;

singlyLinkedList->start=node;

singlyLinkedList->size++;

if(success) *success=true;

return;

}

x=0;

p1=singlyLinkedList->start;

while(x<index)

{

p2=p1;

p1=p1->next;

x++;

}

node->next=p1;

p2->next=node;

singlyLinkedList->size++;

if(success) *success=true;

}

 

void * removeFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)

{

SinglyLinkedListNode *p1,*p2;

int x;

void *ptr;

if(success) *success=false;

if(singlyLinkedList==NULL) return NULL;

if(index<0 || index>=singlyLinkedList->size) return NULL;

p1=singlyLinkedList->start;

x=0;

while(x<index)

{

p2=p1;

p1=p1->next;

x++;

}

ptr=p1->ptr;

if(singlyLinkedList->start==p1 && singlyLinkedList->end==p1)

{

singlyLinkedList->start=NULL;

singlyLinkedList->end=NULL;

}

else if(singlyLinkedList->start==p1)

{

singlyLinkedList->start=singlyLinkedList->start->next;

}

else if(singlyLinkedList->end==p1)

{

p2->next=NULL;

singlyLinkedList->end=p2;

}

else

{

p2->next=p1->next;

}

if(success) *success=true;

singlyLinkedList->size--;

free(p1);

return ptr;

}

 

void traverseSinglyLinkedList(SinglyLinkedList *singlyLinkedList)

{}

void * getFromSinglyLinkedList(SinglyLinkedList *singlyLinkedList,int index,bool *success)

{

SinglyLinkedListNode *node;

int x;

if(success) *success=false;

if(singlyLinkedList==NULL) return NULL;

if(index<0 || index>=singlyLinkedList->size) return NULL;

node=singlyLinkedList->start;

x=0;

while(x<index)

{

node=node->next;

x++;

}

if(success) *success=true;

return node->ptr;

}

 

void appendToSinglyLinkedList(SinglyLinkedList *targetSinglyLinkedList,SinglyLinkedList *sourceSinglyLinkedList,bool *success)

{

SinglyLinkedListNode *node,*s,*e,*t;

bool done;

if(success) *success=false;

if(targetSinglyLinkedList==NULL) return;

if(sourceSinglyLinkedList==NULL || sourceSinglyLinkedList->size==0)

{

if(success) *success=true;

return;

}

s=NULL;

e=NULL;

done=true;

t=sourceSinglyLinkedList->start;

while(t!=NULL)

{

node=(SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode));

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

if(targetSinglyLinkedList->start==NULL)

{

targetSinglyLinkedList->start=s;

targetSinglyLinkedList->end=e;

targetSinglyLinkedList->size=sourceSinglyLinkedList->size;

}

else

{

targetSinglyLinkedList->end->next=s;

targetSinglyLinkedList->end=e;

targetSinglyLinkedList->size+=sourceSinglyLinkedList->size;

}

if(success) *success=true;

}

 

SinglyLinkedListIterator getSinglyLinkedListIterator(SinglyLinkedList *singlyLinkedList,bool *success)

{

SinglyLinkedListIterator singlyLinkedListIterator;

if(success) *success=false;

singlyLinkedListIterator.node=NULL;

if(singlyLinkedList->start==NULL) return singlyLinkedListIterator;

singlyLinkedListIterator.node=singlyLinkedList->start;

if(success) *success=true;

return singlyLinkedListIterator;

}

bool hasNextInSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator)

{

if(singlyLinkedListIterator==NULL) return false;
if(singlyLinkedListIterator->node==NULL) return false;
return true;

}

void * getNextElementFromSinglyLinkedList(SinglyLinkedListIterator *singlyLinkedListIterator,bool *success)

{

void *ptr=NULL;

if(success) *success=false;

if(singlyLinkedListIterator==NULL || singlyLinkedListIterator->node==NULL)

{

return ptr;

}

ptr=singlyLinkedListIterator->node->ptr;

singlyLinkedListIterator->node=singlyLinkedListIterator->node->next;

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
