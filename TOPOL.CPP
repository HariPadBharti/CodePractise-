#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<process.h>


struct node;

struct link {
	int value;
	int rank;
	link * next;
	node * down;
	};

struct node
	{link * l;
	 node * down;
	 };

//------------------
link * makenode( int val)
{
link * temp= new link;
temp->value=val;
temp->rank=0;
temp->next=0;
temp->down=0;
return temp;
}
//------------------

link * addnode(int val, link * start)
{
link * temp=makenode(val);
if(start==NULL)
	{start=temp;
	return(start);
	}
link * temp2=start;
while(temp2->next!=NULL)
temp2=temp2->next;
temp2->next=temp;
return(start);
}
//---------------

link * connect(link * temp, link * start)
	{
	int val;
	clrscr();
	while(1)
	{cout<<"Enter the connections of "<<temp->value;
	 cin>>val;
	 link * temp2=start;
	 while(temp2!=NULL)
	 {if(temp2->value==val)
	 break;
	 temp2=temp2->next;
	 }
	 if(temp2==NULL)
	 cout<<"\nThe entered node does not exist";
	 else
	 {node * temp3=new node;
	 temp3->l=temp2;
	 temp3->down=NULL;
	 if(temp->down==NULL)
	 temp->down=temp3;
	 else
	 {
	 node * temp4=temp->down;
	 while(temp4->down!=NULL)temp4=temp4->down;
	 temp4->down=temp3;
	 }//secondary else ends
	 }//main else ends

	 cout<<"\n\nEnter more connections (press 0 to exit)";
	 cin>>val;
	 if(!val)
	 break;
	 }//while ends
	 return(temp);

}

//---------------
link * getconnections(link * start)
{
	if(start==NULL)
	{
	cout<<"EMPTY GRAPH";
	return(start);
	}
	else
	{link * temp=start;
	while(temp!=NULL)
		{
		temp=connect(temp,start);
		temp=temp->next;
		}
	return(temp);
	}

}
//------------------------



void main()
{       int val;
	link * start=NULL;
	clrscr();
	cout<<"Enter all of the nodes (not the connections, just the nodes)";
	while(1)
	{cout<<"\n\nEnter a node : ";
	cin>>val;
	start=addnode(val,start);
	cout<<"\nWant to continue (press 0 to exit)";
	cin>>val;
	if(!val)
	break;
	}
	if(start==NULL)
	exit(0);
	cout<<"Enter the connections";
	start=getconnections(start);

}