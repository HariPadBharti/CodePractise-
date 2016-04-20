#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int n;
int *greedy(int *,int*);
int *countcost(int *,int *);
int *c;
void main()
{
	clrscr();
	int *d;
	cout<<"Enter no of stations available:\t";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter distance of "<<i<<"th station\t";
		cin>>d[i];
		cout<<"\nEnter cost of "<<i<<"th station\t";
		cin>>c[i];
	//	createlist(d,c);
	}
	cout<<"\n No. of station using greedy are: ";
	int *g1=greedy(d,c);
	cout<<*g1<<" and cost is "<<*(&g1[1]);
	getch();
	cout<<"\n Efficiect no. of stations with min. cost are ";
	int *g2=countcost(d,c);
	cout<<*g2<<" and cost is "<<*(&g2[1]);
	getch();
}


int *greedy(int *a,int *b)
{
	int count=0,i=0,j;
	int c1,*d1;
	c1=0;
	for(j=0;j<n;j++)
	{
		if((a[j+1]-a[i])>100 && j<n-1)
		{
			i=j;
			count+=1;
			c1=c1+b[j];
		}
	}
	*d1=count;
	*(&d1[1])=c1;
	return d1;
}
int *countcost(int *a,int *b)
{
	int count=0,i=0,j=0;
	int c1,*d1;
	//t1_ptr=0;
	c1=0;
	//int j=0;
	while(j<n)
	{
		if((a[j+1]-a[i])>100 && j<n-1 && i<n-1)
		{

			int jj;
			int t1[100];
			int ii=j;
			for(jj=i+1;jj<=j;jj++)
			{
				t1[jj]=c[jj];
			       //	cout<<t1[jj];
			}
			int min=t1[i+1];
			for(jj=i+1;jj<=j;jj++)
			{
				if(min>=t1[jj])
				{
					min=t1[jj];
					ii=jj;
				}
			}
			i=ii;
			j=ii;
			i=j;
			count+=1;
			c1=c1+b[j];
		}
	j=j+1;
	}
	*d1=count;
	*(&d1[1])=c1;
	return d1;
}

