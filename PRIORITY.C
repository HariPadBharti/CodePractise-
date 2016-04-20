#include<stdio>
//#include<conio>
#include<alloc>


struct node{
int value;
int priority;
struct node *next;
}*start,*end,*prev,*curr,*temp;
struct node *front=NULL;





/*struct node *getnode(){
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the value");
scanf("%d",temp->value);
printf("enter the priority");
scanf("%d",temp->priority);
temp->next=NULL;
return temp;
} */


void insert(){

struct node *n_node;
//_node=getnode();
 struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the value");
scanf("%d",n_node->value);
printf("enter the priority");
scanf("%d",n_node->priority);
temp->info=n_node->value;
temp->priority=n_node->priority;
//temp->next=NULL;
if(start==NULL || n_node->priority<start->priority)
{
temp->next=start;
start=temp;
}
else
{curr=start;
//prev=NULL;

while((curr->priority<n_node->priority)&&curr->next!=NULL)
{ curr=curr->next;
temp->next=curr->next;
curr->next=temp;}}
}



void display()
{
temp=start;
while(temp!=NULL)
{
printf("%d",temp->value);
temp=temp->next;
}}

void main()
{int ch;
char con;
clrscr();
do
{
printf("1:insert");
printf("2:display");

printf("enter ur choice");
scanf("%d",&ch);

switch(ch)
{
case 1:insert();
     break;
case 2:display();
      break;
     }
printf("do u want to continue");
con=getch();
}
while (con=='y');
}
