#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
}node;
node *create(node *,int);
void preorder(node *);
void postorder(node *);
void inorder(node *);
int main()
{
	node *root=NULL;
	int n,i,m;
	printf("How many nodes you want to enter");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
	   printf("Enter you want to imsert");
	   scanf("%d",&n);
	   root=create(root,n);
	}
	printf("\nPreorder :");
	preorder(root);
	printf("\nPostorder :");
	postorder(root);
	printf("\nInorder :");
	inorder(root);
	return(0);
}
node *create(node *ptr,int p)
{
	if(ptr==NULL)
	{
		ptr=(node*)malloc(sizeof(node));
		ptr->info=p;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
	}
	else
	{
		if(ptr->info==p)
		printf("Dupliccate record not allowed");
		else
		if(ptr->info>p)
		ptr->lchild=create(ptr->lchild,p);
		else
		if(ptr->info<p)
		ptr->rchild=create(ptr->rchild,p);
	}
	return(ptr);
 }		
void preorder(node *ptr)
{
	if(ptr==NULL)
	   return;
	else
	{
		printf("%d  ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}	
void postorder(node *ptr)
{
	if(ptr==NULL)
	   return;
	else
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d  ",ptr->info);
	}
}
void inorder(node *ptr)
{
	if(ptr==NULL)
	   return;
	else
	{
		inorder(ptr->lchild);
		printf("%d  ",ptr->info);
		inorder(ptr->rchild);
	}
}		
		   						