#include<tm_avl_tree.h>
#include<stdio.h>
#include<stdlib.h>
int myComparator(void *left,void *right)
{
int *leftInt ,*rightInt;
leftInt=(int *)left;
rightInt=(int *)right;
return (*leftInt)-(*rightInt);
}
int main()
{
AVLTreeInOrderIterator iterator;
char more;
int *x;
int num;
AVLTree *tree;
int success;
tree=createAVLTree(&success,myComparator);
if(success==false)
{
printf("Unable to create tree,low on memory\n");
return 0;
}
while(1)
{
printf("enter a number to be inserted in tree :");
scanf("%d",&num);
fflush(stdin);
x=(int *)malloc(sizeof(int));
*x=num;
insertIntoAVLTree(tree,(void *)x,&success);
if(success) printf("add of item that contains %d inserted in tree \n",*x);
else printf("Unable to insert in tree \n");
printf("insert more (Y/N) :");
getchar();
more=getchar();
fflush(stdin);
if(more!='y'  && more!='Y') break;
}
printf("In order iteration starts \n");
iterator=getAVLTreeInOrderIterator(tree,&success);
if(success) 
{
while(hasNextInAVLTree(&iterator))
{
x=(int *)getNextElementFromAVLTree(&iterator,&success);
printf("%d\n",*x);
}
}

while(1)
{
printf("enter a number to search :");
scanf("%d",&num);
fflush(stdin);
x=getFromAVLTree(tree,&num,&success);
if(success) printf("%d found\n",*x);
else printf("%d not found \n",num);
printf("Search more(Y/N) :");
getchar();
more=getchar();
fflush(stdin);
if(more!='y' && more!='Y') break;
}
destroyAVLTree(tree);
return 0;
}
