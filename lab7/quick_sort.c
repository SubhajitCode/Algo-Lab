#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*(a);
	*(a)=*(b);
	*(b)=temp;

}
int partition(int array[],int left,int right )
{
	int p=array[left];//choose pivot
	int i=left+1,j;
	for(j=(left+1);j<=right;j++)
	{
		if(array[j]<p)
		{
			swap(&array[i],&array[j]);
			i++;
		}
		
	}
	swap(&array[left],&array[i-1]);
//	printf("%d \n",(i-1));
	return (i-1);
	
}
void quickSort(int array[],int left,int right)
{
	if(left>=right)
		return;
	int pivot=partition(array,left,right);
	quickSort(array,left,pivot-1);
	quickSort(array,pivot+1,right);

}
void main()
{
	int array[]={5,4,6,9,8,1,3,2};
	quickSort(array,0,7);
	int i;
	for(i=0;i<8;i++)
		printf("%d, ",array[i]);
	printf("\n");
}

