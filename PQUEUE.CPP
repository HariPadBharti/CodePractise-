#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct queue
{
 int data;
 int priority;
 struct queue *link;
}*front=NULL,*temp;

void insert()
{
 struct queue *q;
 int added_item;
 int item_priority;
 temp=(struct queue*)malloc(sizeof(struct queue));
 printf("Enter the element to be added in the queue :");
 scanf("%d",&added_item);
 printf("Enter its priority:");
 scanf("%d",&item_priority);
 temp->data=added_item;
 temp->priority=item_priority;
 if(front==NULL || item_priority<front->priority)
 {
   temp->link=front;
   front=temp;
 }
 else
 {
  q=front;
  while(q->link!=NULL && q->link->priority<=item_priority)
  q=q->link;
  temp->link=q->link;
  q->link=temp;
 }
 }


void delet()
{
 //struct queue *temp;
 if(front==NULL)
 printf("Queue underflow\n");
 else
 {
  temp=front;
  printf("Deleted item is %d\n",temp->data);
  front=front->link;
  free(temp);
 }
}

void display()
{
 struct queue *ptr;
 ptr=front;
 if(front==NULL)
 printf("Queue is empty\n");
 else
 {
  printf("Queue is :\n");
  printf("Priority item\n");
  while(ptr!=NULL)
   {
    printf("%d %d\n",ptr->priority,ptr->data);
    ptr=ptr->link;
   }
  }
}


void main()
{
int choice;
while(1)
{
printf("1.Insert\n");
printf("2.Delete\n");
printf("3.Display\n");
printf("4.Quit\n");
printf("Enter your choice:");
scanf("%d",&choice);

switch(choice)
{
 case 1: insert();
	 break;

 case 2: delet();
	 break;

 case 3: display();
	 break;


 case 4: return;
 default:
 printf("Wrong choice\n");
}
}
}










