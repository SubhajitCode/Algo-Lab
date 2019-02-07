#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
	//Structior of node in Linklist
};
typedef struct node node;
struct myQueue
{
	node* front;
   	node* rear;
};

typedef struct myQueue myQueue;
void printLinkedList(node* front,node *rear)
{
    printf("Printing -------------------------------------------------\n");  

    int i;
    node *link=front;//start from rear
    while(1)
    {
        printf("%d\n",link->data);
        if (link==rear)
            break;//end at front
        link=link->next;
    }
    printf("\n");
	printf("Printing --------------------Ended-----------------------------\n");  
}
node* insertLinkAtRear(node *rear,int n)
{
	//insert link at rear
	node *link=malloc(sizeof(node));
	link->data=n;
	rear->next=link;
	return link;
}

node* deleteLinkFromFront(node *front)
{
	//delete from front
    node *temp=front->next;
    free(front);
	return temp;

}


void enQueue(myQueue* mq,int n)
{
	if (mq->rear==NULL) {
			node *temp=(node*)malloc(sizeof(node));
			temp->data=n;
			temp->next=NULL;
			mq->rear=temp;
			mq->front=temp;
			mq->front->next=temp;
	}
	else
	{
		mq->rear=insertLinkAtRear(mq->rear,n);
	}	
	
}
int deQueue(myQueue* mq)
{
	if(mq->front==NULL)
	{
		printf("Sorry Que is Empty\n");
		return 0;

	}
	else
	{
			int data=mq->front->data;
		mq->front=deleteLinkFromFront(mq->front);
		return(data);
	}
	
}
int frontQueue(myQueue* mq)
{
	if(mq->front==NULL)
	{
		printf("Sorry Que is Empty\n");
		return 0;

	}
	
	return mq->front->data;

}
int printQueue(myQueue* mq)
{
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
		printLinkedList(mq->front,mq->rear);
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

} 
int main()
{
	 myQueue *mq=(myQueue*)malloc(sizeof(myQueue));
	 mq->front=NULL;
	 mq->rear=NULL;
	int i;

	for(i=0;i<10;i++)
	{
		enQueue(mq,i);
	}
	printQueue(mq);
	
	deQueue(mq);
	//deQueue(mq);
	printQueue(mq);
	printf("Front is -----------:%d\n",frontQueue(mq));

return 0;
}
