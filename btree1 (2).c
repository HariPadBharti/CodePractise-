#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
}node;
node *create(node *,int);
node *insert(node *,int);
node *remove(node *,int);
void search(node *,int);
node *min(node *);
node *max(node *);
void preorder(node *);
void postorder(node *);
void inorder(node *);
int height(node *);
int main()
{
		node *root=NULL,*ptr;
		int ch,n,i,m;
		do
		{
			printf("1.Creation of a binary tree.\n");
			printf("2.Insertion of a node in a binary tree.\n");
			printf("3.Deletion of a node in a binary tree.\n");
			printf("4.To search any node in a binary tree.\n");
			printf("5.To find minimum element in a binary tree.\n");
			printf("6.To find maximum element in a binary tree.\n");
			printf("7.For preorder traversal in a binary tree.\n");
			printf("8.For postorder traversal in a binary tree.\n");
			printf("9.For inorder traversal in a binary tree.\n");
			printf("10.To find height of the binary tree.\n");
			printf("11.EXIT\n");
			printf("Enter your choice : ");
			scanf("%d",&ch);
			if(ch==1)
			{
				printf("How many nodes you want in a binary tree.\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter number you want to insert");
					scanf("%d",&m);
					root=create(root,m);
				}
			}
			if(ch==2)
			{
				printf("Enter number you want to insert");
				scanf("%d",&m);		
				root=insert(root,m);
			}
			if(ch==3)
			{
				printf("Enter number you want to delete");
				scanf("%d",&m);
				root=remove(root,m);
			}	
			if(ch==4)
			{
				printf("Enter number to search");
				scanf("%d",&m);
				search(root,m);
			}
			if(ch==5)
			{
				ptr=min(root);
				printf("\nThe minimum element of binary tree is %d",ptr->info);			
			}
			if(ch==6)
			{
				ptr=max(root);
				printf("\nThe maximum element of binary tree is %d",ptr->info);
			}
			if(ch==7)
			{
				printf("\nPreorder : ");
				preorder(root);
			}
			if(ch==8)
			{
				printf("\nPostorder : ");
				postorder(root);
			}
			if(ch==9)
			{
				printf("\nInorder : ");
				inorder(root);
			}
			if(ch==10)
			{
				m=height(root);
				printf("The height of the binary tree is %d ",m);
			}
			if(ch==11)
			{
				exit(0);
			}
		}while(ch>=1&&ch<=11);
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
		if(p<ptr->info)
		 ptr->lchild=create(ptr->lchild,p);
		else 
		if(p>ptr->info)
		 ptr->rchild=create(ptr->rchild,p);
		else
		printf("Duplicate record");
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
void 	postorder(node *ptr)
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
void search(node *ptr,int p)
{
	if(ptr==NULL)
	   return;
	else
	{
		if(p==ptr->info)
		   printf("number found");
		if(p<ptr->info)
		   search(ptr->lchild,p);
		if(p>ptr->info)
		   search(ptr->rchild,p);
	}
}		            
node *insert(node *ptr,int p)
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
		if(p<ptr->info)
		 ptr->lchild=create(ptr->lchild,p);
		if(p>ptr->info)
		 ptr->rchild=create(ptr->rchild,p);
		else
		printf("Duplicate record");
	}
	return(ptr);
}
node *remove(node *ptr,int p)
{
	node *save,*nptr;
	if(ptr==NULL)
	{
		printf("%d not found",p);
		return(ptr);
	}
	if(p<ptr->info)
	ptr->lchild=remove(ptr->lchild,p);
	else
	if(p>ptr->info)
	ptr->rchild=remove(ptr->rchild,p);
	else
	{
		if((ptr->lchild!=NULL)&&(ptr->rchild!=NULL))
		{
			nptr=ptr->rchild;
			while(nptr->lchild!=NULL)
			   nptr=nptr->lchild;
			ptr->info=nptr->info;
			ptr->rchild=remove(ptr->rchild,nptr->info);
		}
		else
		{
			save=ptr;
			if(ptr->lchild!=NULL)
			ptr=ptr->lchild;
			else
			if(ptr->rchild!=NULL)
			ptr=ptr->rchild;
			else
			ptr=NULL;
			free(save);
		}
	}
	return(ptr);
}				   					  		  		
node *min(node *ptr)
{
	if(ptr==NULL)
	  return(NULL);
	else
	if(ptr->lchild==NULL)
	    return(ptr);
	else
	    return(min(ptr->lchild));
}
node *max(node *ptr)
{
	if(ptr==NULL)
	   return(NULL);
	else
	if(ptr->rchild==NULL)
	   return(ptr);
	else
	   return(max(ptr->rchild));
}
int height(node *ptr)
{
	int hl,hr;
	if(ptr==NULL)
	   return(0);
	hl=height(ptr->lchild);
	hr=height(ptr->rchild);
	if(hl>hr)
	   return(1+hl);
	else
	   return(1+hr);
}	   	         