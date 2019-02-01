#include<stdio.h>
struct mystack
{
	int top;
	int data[100];


};

typedef struct mystack stk;
push(struct mystack* stack,int n)
{
	int pos=stack->top;
	stack->data[pos]=n;
	pos++;
	stack->top=pos;
}
int pop(struct mystack* stack)
{
	int pos=stack->top;
	int temp=stack->data[pos];
	pos--;
	stack->top=pos;
	return temp;
}
int top(struct mystack* stack)
{
	int pos=stack->top-1;
	return stack->data[pos];

}
int print(struct mystack* stack)
{
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	int length=stack->top;
	int i,value;
	for(i=0;i<length;i++)
	{
		printf("%d\n",stack->data[length-i-1]);
	}
	
	printf("-----------------------------------------Printing Stack----------------------------------------------------\n");
	

}
int main()
{
	struct mystack stack;
	int i;
	stack.top=0;
	for(i=0;i<10;i++)
	{
		push(&stack,i);
	}
	print(&stack);
	pop(&stack);
	print(&stack);
	printf("Top is -----------:%d\n",top(&stack));

return 0;
}
