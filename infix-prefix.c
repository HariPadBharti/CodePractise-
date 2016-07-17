#include<stdio.h>
#include<conio.h>
#include<string.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char item)
{
 top++;
 stack[top]=item;
} 

char pop()
{
 char a;
 a=stack[top];
 top--;
  return a;
}

int prcd(char symbol)
{
 switch(symbol)
 {
  case '+':
  case '-':return 2; break;
  case '*':
  case '/':return 4; break;
  case '^':
  case '%':return 6; break;
  case '(':
  case ')':
  case '#':return 1; break;
 }
}

int isoperator(char symbol)
{
 switch(symbol)
 {
  case '+':
  case '-':
  case '*':
  case '/':
  case '^':
  case '%':
  case '(':
  case ')':return 1; break;
  default:return 0;
 }
}

void convertip(char infix[],char prefix[])
{
 int i,symbol,j=0;

 infix=strrev(infix); //Used 'strrev' to reverse string

 stack[++top]='#';

 for(i=0;i<strlen(infix);i++)
 {
  symbol=infix[i];

  if(isoperator(symbol)==0)
  {
   prefix[j]=symbol;
   j++;
  }

  else
  {
   if(symbol==')')
    push(symbol);
   
   else if(symbol=='(')
   {
    while(stack[top]!=')')
    {
     prefix[j]=pop();
     j++;
    }
    pop();//pop out (.
   }

   else
   {
    if(prcd(symbol)>prcd(stack[top])) 
     push(symbol);

    else
    {
     while(prcd(symbol)<=prcd(stack[top])) 
     {
      prefix[j]=pop();
      j++;
     }
     push(symbol);
    }
   }
  }
 }

 while(stack[top]!='#')
 {
  prefix[j]=pop();
  j++;
 }

 prefix[j]='\0';//null terminate string.
 prefix=strrev(prefix);
}
void main() 
{
 char infix[20],prefix[20];
 clrscr();

 printf("Enter the valid infix string: \n");
 gets(infix);
 convertip(infix,prefix);

 printf("The corresponding prefix string is: \n");
 puts(prefix);

 getch();
}