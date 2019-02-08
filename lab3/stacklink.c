#include<stdio.h>
#include<stdlib.h>
struct link{
	//LinkList Node
    int data;
    struct link *next;//ponting at next node 
};
typedef struct link node;
void printLinkList(node* head)
{
//Prints the Whole Linklist
    int i;
    node *link=head;
    while(1)
    {
        printf("%d\n",link->data);
        link=link->next;
        if (link==NULL)
            break;
    }
    printf("\n");
}
node* insertNode(node *top,int n)
{
	//alocate mem new Node
	node *link=(node*)malloc(sizeof(node));
	link->next=top;//connect the link with the prev top
	link->data=n; //insert Data
	return link; //return the now top
}

node* deleteNode(node *head)
{
	node *tmp=head->next;//temporarily save the next node
	free(head);//dealocate the mem from heap
	return(tmp);//return now top after poping the top

}

struct mystack
{
	node *top;//Stack by link list
};

typedef struct mystack stk;
void pushStack(struct mystack* stack,int n)
{

	stack->top=insertNode(stack->top,n);//Insert new Node at top
	
}
int popStack(struct mystack* stack)
{
	int temp=stack->top->data; //Save the Prev top
	stack->top=deleteNode(stack->top);//Delete the top
	return temp;//Return the prev top
	
}
int topStack(struct mystack* stack)
{
	return stack->top->data;//Return the top of the stack

}
void printStack(struct mystack* stack)
{
	//Wrapper arount Printing List
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
		printLinkList(stack->top);
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

}
int main()
{
	struct mystack stack;
	int i;
	stack.top=NULL;
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
