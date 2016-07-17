#include<stdio.h>
#include<conio.h>
void selectionsort(int [],int );
int main()
{
	int n,i;
	printf("enter how many you want to enter in the array: ");
	scanf("%d",&n);
	
	int array[n];
	printf("\nenter the element\n: ");
	for(i=0;i<n;i++)
	{
  scanf("%d",&array[i]);
}
printf("\nyou entered the numbers in this arrangement : ");
for (i=0;i<n;i++)
{
    printf(" %d ",array[i]);
}

selectionsort (array, n);

printf("\nafter sorting the arrangement appears like this : ");

for(i=0;i<n;i++)
{
printf(" %d ",array[i]);
}

	getch();
	return (0);
	}

void selectionsort(int array[],int n)
{
     int i,k,t,min,temp;
     for (i=0;i<(n-1);i++)
	 {
		min=i;
		for (k=(i+1);k<n;k++)
		{
			if (array[k]<array[min])
			min=k;
		
		    }
			temp=array[min];
			array[min]=array[i];
			array[i]=temp;
		}
}
