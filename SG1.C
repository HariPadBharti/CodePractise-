#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
typedef struct node
{
 int code;
 char name[4];
 char num[4];
 struct node *next;
}node;
typedef struct slot
{
 int n;
 struct slot *next1;
 node *bot,*botend;
}slot;
typedef struct day
{
 char a[4];
 struct day *bot1;
 node *head,*end;
}day;
typedef struct header
{
 day *start1;
 slot *start2;
}header;
void main()
{
 int x,t;
 char c[4],d[4];
 printf("Enter the number of slots\t");
 scanf("%d",&t);

 getch();
}