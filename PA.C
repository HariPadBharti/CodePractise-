#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct tree{
int sum;
struct tree *right;
struct tree *down;
}tree;
int a[100];
int u=0;
tree *root=NULL;
tree *ptr=NULL;
tree* score(int,int,int,int,int[100][100]);
void make(tree*);
void display(tree*);
void main(){
int c[100][100];
int i,j,x1,y1,a1,b1,max;
tree *temp;
clrscr();
printf("enter the no. of rows and columns in matrix\n");
scanf("%d%d",&a1,&b1);
printf("enter values of matrix\n");
for(i=0;i<a1;i++){
for(j=0;j<b1;j++){
scanf("%d",&c[i][j]);
}
}
printf("enter the starting row\n");
scanf("%d",&x1);
printf("enter the starting column\n");
scanf("%d",&y1);
temp=score(x1,y1,a1,b1,c);
temp=root;
display(temp);
make(temp);
max=0;
printf("\n");
for(i=0;i<u;i++)
{
if(a[i]>max){
max=a[i];
}
printf("%d\t",a[i]);
}
printf("max score is %d",max);
getch();
}

tree* score(int x,int y,int a,int b,int d[100][100]){
if(x>(a-1) || y>(b-1)){
return NULL;
}
else{

tree *temp=NULL;
temp=(tree*)malloc(sizeof(tree));
temp->sum=(ptr->sum)+(d[x][y]);
temp->down=NULL;
temp->right=NULL;

if(root==NULL){
root=temp;
}
ptr=temp;
temp->down=score(x+1,y,a,b,d);
ptr=temp;
temp->right=score(x,y+1,a,b,d);
ptr=temp;
return temp;
}
}

void display(tree *temp){
if(temp!=NULL){
printf("%d\t",temp->sum);
display(temp->down);
display(temp->right);
}
}
void make(tree *temp)
{
if(temp!=NULL){
if(temp->right==NULL || temp->down==NULL){
a[u]=temp->sum;
u++;
}
make(temp->down);
make(temp->right);
}
}


