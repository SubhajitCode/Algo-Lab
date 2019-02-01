#include<stdio.h>

struct link{
    int data;
    struct link *next;
};
typedef struct link link;
typedef struct link node;
void printlink(link* head,link *tail)
{
    printf("Printing -------------------------------------------------\n");  

    int i;
    link *list=head;
    while(1)
    {
        printf("%d\n",list->data);
        if (list==tail)
            break;
        list=list->next;
    }
    printf("\n");
	printf("Printing --------------------Ended-----------------------------\n");  
}
node* insertLink(link *top,int n)
{
	link *list=malloc(sizeof(link));
	list->next=top;
	top->data=n;
	return list;
}

node* deleteLink(link *head)
{
	link *list=head;
    link *temp=list->next;
    list->next=temp->next;
	return list;

}

struct myQueue
{
	node *top;
    node *bottom;
};

typedef struct myQueue myQueue;
enQueue(myQueue* mq,int n)
{

	mq->top=insertLink(mq->top,n);
	
}
int deQueue(myQueue* mq)
{
	int temp=mq->bottom->data;
	mq->bottom=deleteLink(mq->bottom);
	return temp;
	
}
int frontQueue(myQueue* mq)
{
	return mq->bottom->data;

}
int printQueue(myQueue* mq)
{
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
		printlink(mq->top,mq->bottom);
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

}
int main()
{
	struct myQueue mq;
	int i;
	mq.top=mq.bottom;
    //mq.bottom->next=NULL;
	for(i=0;i<10;i++)
	{
		enQueue(&mq,i);
	}
	printQueue(&mq);
	
	deQueue(&mq);
	printQueue(&mq);
	printf("Top is -----------:%d\n",frontQueue(&mq));

return 0;
}
