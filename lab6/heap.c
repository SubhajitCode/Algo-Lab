#include<stdio.h>
#include <math.h>
void swap(int *a,int*b);
void heapify(int heap[],int pos);
int heap_Max(int heap[]);
void heap_Pop(int *heap[]);
int heap_Insert(int heap[],int data,int end)
{
	//heap Insert
	heap[end+1]=data;//Insert the data into end leaf and call heapyfy
	heapify(heap,end+1);//call heapify
	return end+1;//update n+1

}
void heapify(int heap[],int pos)
{
	int parent=(pos-1)/2;
	if(parent<0)
	{
		return;//base case if root
	}
	if(heap[pos]>heap[parent])
	{
		swap(&heap[pos],&heap[parent]);//swap if gearter
		heapify(heap,parent);//recursive call 
	}

}
int heap_Max(int heap[])
{
//return max element
	int ret=heap[0];
	return ret;
}

void heap_Pop(int *heap[])
{
	int ret=*heap[0];
	*heap=*(heap+1);
}
void print_heap(int heap[],int size)
{
	int no_rows=log(size)/log(2);
	int i,j,k=1,l=0;
	for(i=0;i<no_rows;i++)
	{
		for(j=0;j<no_rows-i;j++)
		{
			printf(" ");
		}
		for(j=0;j<k;j++)
		{
			printf("%d ",heap[l++]);
		}
		k=k*2;
		printf("\n");
	}
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;

}
void main()
{
	int size=20;
	int heap[size];
	int current_end=-1,i;
	for(i=0;i<size;i++)
	{
		current_end=heap_Insert(heap,rand()%size,current_end);
	}

	print_heap(heap,size);
	printf("\n max element is %d",heap_Max(heap));
	int **my_heap=&heap;
	heap_Pop(my_heap);
	print_heap(my_heap,size-1);


}
