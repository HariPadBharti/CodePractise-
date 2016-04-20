#include<stdio.h>
#include<stdlib.h> 
typedef struct node
{
 char str[30];
 struct node *left,*right;
}node;
node *root=NULL;
node * make_node(char*);
void tree();

node * make_node(char a[30])
{
 node * temp;
 temp=(node *)malloc(sizeof(node));
 temp->left=temp->right=NULL;
 strcpy(temp->str,a);
 return temp;
}
 
void tree()
{
root=make_node("Is it animal?");  // root
node *prt,*lft,*rgt;
prt=root;                          // points to root
lft=make_node("Can it fly?");
prt->left=lft;
rgt=make_node("Does it have wheel?");
prt->right=rgt;
prt=lft;                           //points to left of root
lft=make_node("bird");
prt->left=lft;
rgt=make_node("Does it have a tail?");
prt->right=rgt;
prt=rgt;                         //points to right to left of root
lft=make_node("mouse");
prt->left=lft;
rgt=make_node("spider");
prt->right=rgt;
prt=root->right;               //points to right of root
lft=make_node("bicycle");
prt->left=lft;
rgt=make_node("Is it nice?");
prt->right=rgt;
prt=rgt;                       //points to right of right root
lft=make_node("TA");
prt->left=lft;
rgt=make_node("teacher");
prt->right=rgt;
}
 
void preorder(node *p)
{
if(p!=NULL)
 {
 printf("%s\n",p->str);
 preorder(p->left);
 preorder(p->right);
 }
}
 
void inorder(node *p)
{
 if(p!=NULL)
 {
  inorder(p->left);
  printf("%s\n",p->str);
  inorder(p->right);
 }
}

void guess()
{
char ans[30],temp[30],q[30];
node *ptr,*lft,*rgt;
ptr=root;
lft=ptr->left;
rgt=ptr->right;
while((lft!=NULL)&&(rgt!=NULL))
{
printf("%s",ptr->str);
gets(ans);
if(strcmp(ans,"yes")==0)
 ptr=ptr->left;
else if(strcmp(ans,"no")==0)
 ptr=ptr->right;
 else printf("please enter yes/no\n");
lft=ptr->left;
rgt=ptr->right;
}// while ends
printf("Would your object happen to be %s?\n",ptr->str);
gets(ans);
if(strcmp(ans,"yes")==0)
printf("I win\n");
else if(strcmp(ans,"no")==0)
{
printf("I lose.What is your object  ");
fflush(stdin);
gets(temp);
printf("Type a yes/no question to distinguish your item from %s :",ptr->str);
fflush(stdin);
gets(q);
strcpy(ans,ptr->str);
lft=make_node(temp);
rgt=make_node(ans);
strcpy(ptr->str,q);
ptr->left=lft;
ptr->right=rgt;
}
}


int main()
{
 tree();
 guess();
 char *c;
 //preorder(root);
 // printf("---------------in\n");
 inorder(root);
while(1)
{
printf("press e to exit,otherwise to continue playing\n");
gets(c);
if(*c=='e')
exit(0);
guess();
}
return 0;
}




