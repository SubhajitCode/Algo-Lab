#include<stdio.h>
struct myqueue
{
	int bottom;
	int data[100];
    int top;


};

typedef struct myqueue myQueue;
enQueue(myQueue *mque,int n)
{
	int pos=mque->top;
	mque->data[pos]=n;
	pos++;
	mque->top=pos;
}
int deQueue(myQueue *mque)
{
	int pos=mque->bottom;
	int temp=mque->data[pos];
	pos++;
	mque->bottom=pos;
	return temp;
}
int front(myQueue *mque)
{
	int pos=mque->bottom;
	return mque->data[pos];

}
int print(myQueue *mque)
{
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	int length=(mque->top)-(mque->bottom);
	int i,value;
	for(i=(mque->bottom);i<length;i++)
	{
		printf("%d\n",mque->data[i]);
	}
	
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

}
int main()
{
	myQueue mque;
	int i;
	mque.top=0;
    mque.bottom=0;

	for(i=0;i<10;i++)
	{
		enQueue(&mque,i);
	}
	print(&mque);
	deQueue(&mque);
	print(&mque);
	printf("front is -----------:%d\n",front(&mque));

return 0;
}
