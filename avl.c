#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
typedef struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
	int bal;
}node;
node *RotateRight(node *);
node *RotateLeft(node *);
node *insert(node *,int);
node *insert_right_check(node *,int *);
node *insert_left_check(node *,int *);
node *insert_right_bal(node *);
node *insert_left_bal(node *);
void inorder(node *);
int main()
{
	int ch,key;
	node *root=NULL;
	while(1)
	{
		printf("1.INSERT\n");
		printf("2.DELETION\n");
		printf("3.INORDER TRAVERSAL\n");
		printf("4.QUIT\n");
		printf("Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
						printf("Enter the key to be inserted : ");
						scanf("%d",&key);
						root=insert(root,key);
						break;
			/*case 2: 
						printf("Enter the key to be deleted : ");
						scanf("%d",&key);
						root=del(root,key);
						break;
			*/case 3:
						inorder(root);
						break;
			case 4:
						exit(1);
		}
	}						
	return(0);
}
node *RotateRight(node *ptr)
{
	node *aptr;
	aptr=ptr->lchild;
	ptr->lchild=aptr->rchild;
	aptr->rchild=ptr;
	return(aptr);
}
node *RotateLeft(node *ptr)
{
	node *aptr;
	aptr=ptr->rchild;
	ptr->rchild=aptr->lchild;
	aptr->lchild=ptr;
	return(aptr);
}
node *insert(node *ptr,int key)
{
	static int taller;
	if(ptr==NULL)
	{
		ptr=(node *)malloc(sizeof(node));
		ptr->info=key;
		ptr->lchild=NULL;
		ptr->rchild=NULL;
		ptr->bal=0;
	}
	else if(key<ptr->info)
	{
		ptr->lchild=insert(ptr->lchild,key);
		if(taller==TRUE)
			ptr =insert_left_check(ptr,&taller);
	}
	else if(key>ptr->info)
	{
		ptr->rchild=insert(ptr->rchild,key);
		if(taller==TRUE)
			ptr=insert_right_check(ptr,&taller);
	}
	else
	{
		printf("DUPLICATE ELEMENT");
		taller=FALSE;
	}
	return(ptr);
}
node *insert_left_check(node *ptr,int *ptal)
{
	switch(ptr->bal)
	{
		case 0 :
					ptr->bal=1;
					break;
		case -1:
					ptr->bal=0;
					*ptal=FALSE;
					break;
		case 	1:
					ptr=insert_left_bal(ptr);
					*ptal=FALSE;
					break;
	}
	return(ptr);
}
node *insert_left_bal(node *ptr)
{
	node *aptr,*bptr;
	aptr=ptr->lchild;
	if(aptr->bal==1)
	{
		ptr->bal=0;
		aptr->bal=0;
		ptr=RotateRight(ptr);
	}
	else
	{
		bptr=aptr->rchild;
		switch(bptr->bal)
		{
			case -1 :
							ptr->bal=0;
							aptr->bal=1;
							break;
			case 1 :
							ptr->bal=-1;
							aptr->bal=0;
							break;
			case 0 :
							ptr->bal=0;
							aptr->bal=0;
							break;
		}
		bptr->bal=0;
		ptr->lchild=RotateLeft(aptr);
		ptr=RotateRight(ptr);
	}
	return(ptr);
}node *insert_right_check(node *ptr,int *ptal)
{
	switch(ptr->bal)
	{
		case 0 :
					ptr->bal=-1;
					break;
		case -1:
					ptr->bal=0;
					*ptal=FALSE;
					break;
		case 	1:
					ptr=insert_right_bal(ptr);
					*ptal=FALSE;
					break;
	}
	return(ptr);
}
node *insert_right_bal(node *ptr)
{
	node *aptr,*bptr;
	aptr=ptr->rchild;
	if(aptr->bal==-1)
	{
		ptr->bal=0;
		aptr->bal=0;
		ptr=RotateLeft(ptr);
	}
	else
	{
		bptr=aptr->lchild;
		switch(bptr->bal)
		{
			case -1 :
							ptr->bal=1;
							aptr->bal=0;
							break;
			case 1 :
							ptr->bal=0;
							aptr->bal=-1;
							break;
			case 0 :
							ptr->bal=0;
							aptr->bal=0;
							break;
		}
		bptr->bal=0;
		ptr->lchild=RotateRight(aptr);
		ptr=RotateLeft(ptr);
	}
	return(ptr);
}					
void inorder(node *ptr)
{
	node *aptr = ptr;
	if(aptr==NULL)
	{
		return;
	}	
	else
	{
		inorder(ptr->lchild);
		printf("%d\n",ptr->info);
		inorder(ptr->rchild);
	}
}																													