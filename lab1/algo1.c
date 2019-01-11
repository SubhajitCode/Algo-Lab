#include<stdio.h>
void swap(int array[],int i,int j)
{
	int temp=array[i];
	array[i]=array[j];
	array[j]=temp;
}
void selectionsort(int array[],int size)
{
	int i,j,max,max_index;
	for(i=0;i<size;i++)
	{
		max=array[0];
		max_index=0;
		for(j=0;j<size-i;j++)
		{
			if(array[j]>max)
			{
				max=array[j];
				max_index=j;
			}
		}
		swap(array,j-1,max_index);
	}
}
main()
{
	int n;
	printf("How many You want to print ??:");
	scanf("%d",&n);
	int array[1000];
	int i;
	for(i=0;i<1000;i++)
	{
		array[i]=rand()%1000;
	}
	printf("UnSorted Vertion is :--------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
	printf("\n");
	selectionsort(array,1000);
	printf("Sorted Vertion is :--------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
		printf("\n");

}
