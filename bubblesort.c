#include<stdio.h>
#include<conio.h>

void bubblesort(int []);
int main()
{
	int a[10],i;
	printf("\nenter the elements in the array :");
for (i=0;i<10;i++)
{
	scanf("%d",&a[i]);
	}

bubblesort(a);

for (i=0;i<10;i++)
printf("\n %d ",a[i]);
 
getch();
return 0;
}


void bubblesort(int a[])
{
int temp,k,i;
	for(k=9;k>=0;k--)
	{
		for(i=0;i<=(k-1);i++)
		{
			if(a[i]>a[i+1])
			{
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				}
			}
		}
}
