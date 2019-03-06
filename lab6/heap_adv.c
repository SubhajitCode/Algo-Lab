#include<stdio.h>
#include <math.h>
void swap(int *a,int*b);
void heapify(int heap[],int pos);
int heap_Max(int heap[]);
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
void heapify_2(int heap[],int pos,int size)
{
	int child1=2*pos+1;
	int child2=2*pos+2;
	if(child1>=size)
		return;
	//find max
	int temp,max;
	if(heap[child1]>heap[child2])
		max=child1;
	else if(child2<size)
		max=child2;
	else
		max=pos;
	if(heap[max]>heap[pos])
	{
		swap(&heap[pos],&heap[max]);
		heapify_2(heap,max,size);
//		heapify_2(heap,child2,size);
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
	int no_rows=log(size)/log(2)+1;
	int i,j,k=1,l=0,m;
	for(i=0;i<no_rows;i++)
	{
		for(j=0;j<pow(2,(no_rows-i-1))-1;j++)
			printf(" ");
		for(m=0;m<k;m++)
		{
			printf("%2d",heap[l++]);
				if(l>=size)
					break;
			for(j=0;j<pow(2,(no_rows-i))-1;j++)
			{
				printf(" ");
			}
		}
		printf("\n");
		k=k*2;
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
	int size=31;
	int heap[size];
	int i;
	for(i=0;i<size;i++)
	{
		heap[i]=rand()%31;
		printf("%d ",heap[i]);

	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		heapify_2(heap,size-i-1,size);
	}
	print_heap(heap,size);

}
