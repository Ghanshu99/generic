#include<stdio.h>
#include<stdlib.h>
#include<stack.h>
void appendToPostfix(char c,char *pf,int *terminatorIndex)
{
pf[*terminatorIndex]=c;
*terminatorIndex=*terminatorIndex+1;
pf[*terminatorIndex]='\0';
}
int main()
{
char elem;
char *m;
char infix[101],postfix[101];
int succ;
Stack *stack;
int i,terminatorIndex;
printf("enter an infix expression \n");
scanf("%s",infix);
stack=createStack(succ);
postfix[0]='\0';
terminatorIndex=0;
i=0;
while(infix[i]!='\0')
{
elem=infix[i];
if(elem=='(')
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i++;
continue;
}
if(elem==')')
{
while(1) //poppoing loop starts
{
m=(char *)popFromStack(stack,&succ);
if(*m=='(') 
{
free(m);
break;
}
appendToPostfix(*m,postfix,&terminatorIndex);
free(m);
} //popping loop ends
i++;
continue;
}
if(isOperand(elem))
{
if(isStackEmpty(stack))
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i++;
continue;
}
m=(char *)elementAtTopOfStack(stack,&succ);
if(*m=='(')
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i++;
continue;
}
if(getPrecedenceLevel(*m)<getPrecedenceLevel(elem))
{
m=(char *)malloc(sizeof(char));
*m=elem;
pushOnStack(stack,(void *)m,&succ);
i++;
continue;
}
while(1)  //popping loop starts
{
if(isStackEmpty(stack)) break;
m=elementAtTopOfStack(stack,&succ);
if(*m=='(') break;
if(getPrecedenceLevel(*m)<getPrecedenceLevel(elem)) break;
m=(char *)popFromStack(stack,&succ);
appendToPostfix(*m,postfix,&terminatorIndex);
free(x);
}   //popping loop ends
}// infix loop ends
while(!isStackEmpty(stack))
{
m=popFromStack(stack,&succ);
appendToPostfix(*m,postfix,&terminatorIndex);
free(m);
}
}
printf("postfix expression \n %s",postfix);
return 0;
}
