#include<stdio.h>
void swap(int array[],int i,int j)
{
	int temp=array[i];
	array[i]=array[j];
	array[j]=temp;
}
void sort(int array[],int size)
{
    int i,zerocount=0,onecount=0,twocount=0;
    for(i=0;i<size;i++)
    {
        if(array[i]==0)
            zerocount++;
        else if(array[i]==1)
            onecount++;
        else
            twocount++;
    }
    for(i=0;i<size;i++)
    {
        if(zerocount>0)
        {
            array[i]=0;
            zerocount--;
        }
        else if(onecount>0)
        {
            array[i]=1;
            onecount--;
        }
        else
        {
            array[i]=2;
            twocount--;
        }
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
		array[i]=rand()%3;
	}
	printf("UnSorted Vertion is :--------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
	printf("\n");
	sort(array,1000);
	printf("Sorted Vertion is :--------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf(" %d",array[i]);
	}
		printf("\n");

}
