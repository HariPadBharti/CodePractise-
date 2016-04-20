#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
typedef struct node
{
 int info;
 struct node *left;
 struct node *right;
}node;
node *root=NULL;
node *insert(int,node *);
node *create(int);
void inorder(node *);
void main()
{
 int a,ch;
 while(1)
 {
  printf("\nMENU\n1.Enter the element\n2.Display inorder\n3.Exit\nEnter your choice\t");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:      printf("\nEnter the value\t");
		scanf("%d",&a);
		root=insert(a,root);
		break;
   case 2:	printf("\nInorder traversal is \n");
		inorder(root);
		break;
   case 3:	exit(0);
		break;
   default: printf("\nYou enter the wrong choice");
  }
 }

}
node *create(int x)
{
 node *temp;
 temp=(node *)malloc(sizeof(node));
 temp->info=x;
 temp->left=NULL;
 temp->right=NULL;
 return(temp);
}
node *insert(int x,node *t)
{
 if(t==NULL)
  t=create(x);
 else
 {
  if(t->info>x)
   t->left=insert(x,t->left);
  else
  if(t->info<=x)
   t->right=insert(x,t->right);
 }
 return(t);
}
void inorder(node *rt)
{
if(rt==NULL)
return;
else
 {
  inorder(rt->left);
  printf("%d ",rt->info);
  inorder(rt->right);
 }
}