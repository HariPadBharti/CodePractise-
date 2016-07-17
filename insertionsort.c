#include<stdio.h>
#include<conio.h>

void insertionsort(int [],int );

int main()
{
int n,i;

	printf("how many elements you want in the array");
	scanf("%d",&n);
	int a[n];
	printf("\nenter elements in the array\n:");

for (i=0;i<n;i++)
{
	scanf("%d",&a[i]);
	}
	
printf("\nyou entered these numbers:");

for (i=0;i<n;i++)
{
	printf(" %d ",a[i]);
	}

insertionsort(a,n);

printf("\nThe arrangement of elements after insertion sort is this :");

for (i=0;i<n;i++)
printf(" %d ",a[i]);

getch();
return 0;
	
}	

void insertionsort(int a[],int n)
{
	int i,j,elementstore;
		for(i=1;i<n;i++)
		{
			j=i;
			elementstore=a[i];
				while((a[j-1]>elementstore)&&(j>=1))
				{
					a[j]=a[j-1];
					j--;
					}
				a[j]=elementstore;
				
				}
	}			
