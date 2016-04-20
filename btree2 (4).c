#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
}node;
node *x[50];
int front=-1,rear=-1;
node *create(node *,int);
void insertqueue(node*);
node *delqueue();
int queueempty();
void levelorder(node *);
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
	printf("\nLevelorder :");
	levelorder(root);
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
void levelorder(node *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	insertqueue(ptr);
	while(!queueempty())
	{
		ptr=delqueue();
		printf("%d  ",ptr->info);
		if(ptr->lchild!=NULL)
		    insertqueue(ptr->lchild);
		if(ptr->rchild!=NULL)
		    insertqueue(ptr->rchild);
	}
	printf("\n");
}
void insertqueue(node *p)
{
	if(rear==49)
	{
		printf("queue overflow");
	}
	if(rear==-1)	
	{
		front=0;
		rear=0;
	}
	else
		rear++;
		x[rear]=p;
}
node *delqueue()
{
	node *p;
	if((front==-1)||(front==rear+1))
	{
		printf("queue Underflow");
		return(NULL);
	}
	p=x[front];
	front++;
	return(p);
}
int queueempty()
{
	if((front==-1)||(front==rear+1))	
	    return(1);
	else
	    return(0);
}      								        	 