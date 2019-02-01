#include<stdio.h>

struct link{
    int data;
    struct link *next;
};
typedef struct link link;
typedef struct link node;
void printlink(link* head)
{
    printf("Printing -------------------------------------------------\n");  

    int i;
    link *list=head;
    while(1)
    {
        printf("%d\n",list->data);
        list=list->next;
        if (list==NULL)
            break;
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

node* delete(link *head)
{
	link *list=head;
    link *temp=list->next;
    list->next=temp->next;
	return list;

}

struct mystack
{
	node *top;
};

typedef struct mystack stk;
enQueue(struct mystack* stack,int n)
{

	stack->top=insertLink(stack->top,n);
	
}
int deQueue(struct mystack* stack)
{
	int temp=stack->top->data;
	stack->top=delete(stack->top);
	return temp;
	
}
int frontQueue(struct mystack* stack)
{
	return stack->top->next->data;

}
int printQueue(struct mystack* stack)
{
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
		printlink(stack->top->next);
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

}
int main()
{
	struct mystack stack;
	int i;
	stack.top->next=NULL;
	for(i=0;i<10;i++)
	{
		pushStack(&stack,i);
	}
	printStack(&stack);
	
	popStack(&stack);
	printStack(&stack);
	printf("Top is -----------:%d\n",topStack(&stack));

return 0;
}
