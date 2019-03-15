#include<stdio.h>
void merge(int left[],int left_size,int right[],int right_size,int destination[]);
void mergeSort(int array[],int left,int right,int destination[])
{
	if(left==right)
	{
	//	printf("%d\n",array[left]);
		destination[0]=array[left];
		return;
	}
	int middle=left+(right-left)/2;
	int left_array[middle-left];
	int right_array[right-middle+1];
	mergeSort(array,left,middle,left_array);
	mergeSort(array,middle+1,right,right_array);
	merge(left_array,(middle-left),right_array,(right-(middle+1)),destination);

}
void merge(int left[],int left_size,int right[],int right_size,int destination[] )
{
	int i=0,j=0,k=0;
	while(i<=left_size && j<=right_size)
	{
		if(left[i]>=right[j]){

			destination[k]=left[i];
			i++;k++;
		}
		else{
			destination[k]=right[j];
			j++;k++;
		}
	}
	if(i>left_size)
	{
		while(j<=right_size)
		{
			destination[k]=right[j];
			k++;j++;
		
		}
		
	}
	if(j>right_size)
	{
		while(i<=left_size)
		{
			destination[k]=left[i];
			k++;i++;
		
		}
		
	}

}

int main()
{
	int array[]={5,1,4,8,7,8,9,6};
	int dest[8];
	mergeSort(array,0,7,dest);
	int i;
	for(i=0;i<8;i++)
		printf("%d, ",dest[i]);
	printf("\n");
	return 0;
}
