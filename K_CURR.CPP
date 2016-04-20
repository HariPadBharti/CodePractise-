//coin xchange

#include<stdio.h>
#include<conio.h>
#include<iostream.h>

int count(int value,int i)
{
int a[6]={1,5,10,20,50,100};
if(value==0)
return 0;

else
{
	if(value>=a[i])
	{value=value-a[i];
	return(1+count(value,i));
	}
	else
	{
	i--;
	return (count(value,i));
	}
}
}
int main()
{

clrscr();
int k=678;
k=count(k,5);
cout<<k;
getch();
return 0;
	}