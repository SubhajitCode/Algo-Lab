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
        printf("%d\t",list->data);
        list=list->next;
        if (list==NULL)
            break;
    }
    printf("\n");
	printf("Printing --------------------Ended-----------------------------\n");  
}
node* insertLink(link *top,int n)
{
	link *list=top;
	int i;
	link *temp=malloc(sizeof(link));
	temp->data=n;
	temp->next=list->next;
	list->next=temp;
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
	node *tail;
	node *top;
};

typedef struct mystack stk;
pushStack(struct mystack* stack,int n)
{

	stack->top=insertLink(stack->top,n);
	
}
int popStack(struct mystack* stack)
{
	int temp=stack->top->data;
	stack->top=delete(stack->top);
	return temp;
	
}
int topStack(struct mystack* stack)
{
	return stack->top->data;

}
int printStack(struct mystack* stack)
{
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
		printlink(stack->top);
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

}
int main()
{
	struct mystack stack;
	int i;
	stack.tail=NULL;
	stack.top->next=stack.tail;
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
