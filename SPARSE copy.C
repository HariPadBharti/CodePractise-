#include<stdio.h>
#include<conio.h>
#include<alloc.h>
typedef struct node
	     {int col;
	      int row;
	      int val;
	      struct node *next;
	      struct node *down;
	     }node;
void main()
{
int x[10][10]={ 0,0,0,0,1,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,0,
		1,0,0,1,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,0,0,0,1,
		0,0,0,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,0,1,0,
		0,1,0,0,0,0,0,0,0,0,};
int y[10][10]={ 1,0,0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,0,0,0,
		0,0,1,1,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,0,1,0,
		0,0,0,0,0,0,0,0,0,1,};
int i,j,sum[10][10];
char ch;
node *mhead,*temp,*temp1,*end,*temp2,*mhead2,*temp3,*sumhead;
i=j=-1;
clrscr();
mhead=mhead2=NULL;
for(i=0;i<10;i++)
{for(j=0;j<10;j++)
 {sum[i][j]=0;};
};
/*entering values for 1 st array;*/
mhead=NULL;
j=-1;
while(j<10)
{temp=(node*)malloc(sizeof(node));
 temp->row=-1;
 temp->col=j;
 temp->val=0;
 temp->next=NULL;
 temp->down=NULL;
 if(mhead==NULL)
 {mhead=end=temp;}
 else
 {end->next=temp;
  end=temp;
 };
 j++;
};
j=-1;
i=0;
while(i<10)
{temp=(node*)malloc(sizeof(node));
 temp->row=i;
 temp->col=-1;
 temp->val=0;
 temp->next=NULL;
 temp->down=NULL;
 if(mhead->down==NULL)
 {mhead->down=end=temp;}
 else
 {end->down=temp;
  end=temp;
 };
 i++;
};
temp=mhead;
for(i=0;i<10;i++)
{temp=temp->down;
 temp1=mhead;
 for(j=0;j<10;j++)
  {temp1=temp1->next;
   if(x[i][j]>=1)
    { temp2=(node*)malloc(sizeof(node));
      temp2->row=i;
      temp2->col=j;
      temp2->val=x[i][j];
      temp2->next=NULL;
      temp2->down=NULL;
      if(temp1->down==NULL)
      {temp1->down=temp2;}
      else
      {end=temp1;
       while(end->down!=NULL)
	{end=end->down;};
       end->down=temp2;
      }
      if(temp->next==NULL)
      {temp->next=temp2;}
      else
       {end=temp;
	while(end->next!=NULL)
	{end=end->next;};
	end->next=temp2;
       }
    };
   };
};
i=0;
j=0;
printf("printing via row");
temp=mhead;
while(temp->down!=NULL)
{temp=temp->down;
 temp1=temp->next;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->next;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();
printf("printing via col");
temp=mhead;
while(temp->next!=NULL)
{temp=temp->next;
 temp1=temp->down;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->down;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();
/*entering values for 2 nd array;*/
mhead2=NULL;
j=-1;
while(j<10)
{temp=(node*)malloc(sizeof(node));
 temp->row=-1;
 temp->col=j;
 temp->val=0;
 temp->next=NULL;
 temp->down=NULL;
 if(mhead2==NULL)
 {mhead2=end=temp;}
 else
 {end->next=temp;
  end=temp;
 };
 j++;
};
j=-1;
i=0;
while(i<10)
{temp=(node*)malloc(sizeof(node));
 temp->row=i;
 temp->col=-1;
 temp->val=0;
 temp->next=NULL;
 temp->down=NULL;
 if(mhead2->down==NULL)
 {mhead2->down=end=temp;}
 else
 {end->down=temp;
  end=temp;
 };
 i++;
};
temp=mhead2;
for(i=0;i<10;i++)
{temp=temp->down;
 temp1=mhead2;
 for(j=0;j<10;j++)
  {temp1=temp1->next;
   if(y[i][j]>=1)
    { temp2=(node*)malloc(sizeof(node));
      temp2->row=i;
      temp2->col=j;
      temp2->val=y[i][j];
      temp2->next=NULL;
      temp2->down=NULL;
      if(temp1->down==NULL)
      {temp1->down=temp2;}
      else
      {end=temp1;
       while(end->down!=NULL)
	{end=end->down;};
       end->down=temp2;
      }
      if(temp->next==NULL)
      {temp->next=temp2;}
      else
       {end=temp;
	while(end->next!=NULL)
	{end=end->next;};
	end->next=temp2;
       }
    };
   };
};
i=0;
j=0;
printf("printing via row");
temp=mhead2;
while(temp->down!=NULL)
{temp=temp->down;
 temp1=temp->next;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->next;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();
printf("printing via col");
temp=mhead2;
while(temp->next!=NULL)
{temp=temp->next;
 temp1=temp->down;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->down;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();

printf("addition of two matrix");
temp=mhead;
temp1=mhead2;

while(temp!=NULL||temp1!=NULL)
{temp=temp->down;
temp1=temp1->down;
temp2=temp->next;
temp3=temp1->next;
while(temp2!=NULL||temp3!=NULL)
 {if(temp2->col<temp3->col)
    {i=temp2->row;
     j=temp2->col;
     sum[i][j]=temp2->val;
     temp2=temp2->next;
    }
  else
   {if(temp2->col==temp3->col)
      {i=temp2->row;
       j=temp2->col;
       sum[i][j]=temp2->val+temp3->val;
       temp2=temp2->next;
       temp3=temp3->next;
      }
    else
      { i=temp3->row;
	j=temp3->col;

	sum[i][j]=temp3->val;
	temp3=temp3->next;
      }
    }
   }
  if(temp2==NULL&&temp3!=NULL)
   {    while(temp3!=NULL)
	{i=temp3->row;
	j=temp3->col;
	sum[i][j]=temp3->val;
	temp3=temp3->next;
	};
   }
  else
  {if(temp2!=NULL&&temp3==NULL)
   {    while(temp2!=NULL)
	{i=temp2->row;
	j=temp2->col;
	sum[i][j]=temp2->val;
	temp2=temp2->next;
	};
   };
  };

};


sumhead=NULL;
j=-1;
while(j<10)
{temp=(node*)malloc(sizeof(node));
 temp->row=-1;
 temp->col=j;
 temp->val=0;
 temp->next=NULL;
 temp->down=NULL;
 if(sumhead==NULL)
 {sumhead=end=temp;}
 else
 {end->next=temp;
  end=temp;
 };
 j++;
};
j=-1;
i=0;
while(i<10)
{temp=(node*)malloc(sizeof(node));
 temp->row=i;
 temp->col=-1;
 temp->val=0;
 temp->next=NULL;
 temp->down=NULL;
 if(sumhead->down==NULL)
 {sumhead->down=end=temp;}
 else
 {end->down=temp;
  end=temp;
 };
 i++;
};
temp=sumhead;
for(i=0;i<10;i++)
{temp=temp->down;
 temp1=sumhead;
 for(j=0;j<10;j++)
  {temp1=temp1->next;
   if(sum[i][j]>=1)
    { temp2=(node*)malloc(sizeof(node));
      temp2->row=i;
      temp2->col=j;
      temp2->val=sum[i][j];
      temp2->next=NULL;
      temp2->down=NULL;
      if(temp1->down==NULL)
      {temp1->down=temp2;}
      else
      {end=temp1;
       while(end->down!=NULL)
	{end=end->down;};
       end->down=temp2;
      }
      if(temp->next==NULL)
      {temp->next=temp2;}
      else
       {end=temp;
	while(end->next!=NULL)
	{end=end->next;};
	end->next=temp2;
       }
    };
   };
};
i=0;
j=0;
printf("printing via row");
temp=sumhead;
while(temp->down!=NULL)
{temp=temp->down;
 temp1=temp->next;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->next;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();

printf("printing via col");
temp=sumhead;
while(temp->next!=NULL)
{temp=temp->next;
 temp1=temp->down;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->down;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();
printf("transpose of first matrix");

temp=mhead;
while(temp->down!=NULL)
{temp=temp->down;
 temp1=temp;
 while(temp1!=NULL)
 {i=temp1->row;
  temp1->row=temp1->col;
  temp1->col=i;
  temp1=temp1->next;
 };
};

printf("printing via row");
temp=mhead;
while(temp->next!=NULL)
{temp=temp->next;
 temp1=temp->down;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->down;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();

printf("transpose of second matrix");

temp=mhead2;
while(temp->down!=NULL)
{temp=temp->down;
 temp1=temp;
 while(temp1!=NULL)
 {i=temp1->row;
  temp1->row=temp1->col;
  temp1->col=i;
  temp1=temp1->next;
 };
};

printf("printing via row");
temp=mhead2;
while(temp->next!=NULL)
{temp=temp->next;
 temp1=temp->down;
 i=0;
 while(temp1!=NULL)
 {i++;
  printf("\nrow num =%d  col num =%d  val =%d",temp1->row,temp1->col,temp1->val);
  temp1=temp1->down;
 };
 temp->val=i;
};
fflush(stdin);
ch=getchar();

getch();
}