#include <stdio.h>
struct node {
	int data;
	struct node* next;
};
typedef struct node node;
void printList(node* head)
{
    int i;
    node *list=head;
    while(1)
    {
        printf("%d\t",list->data);
        list=list->next;
        if (list==NULL)
            break;
    }
    printf("\n");
}

void createList(node *head,int n){
	node *list=head;
	node *temp;
	int i;
	for(i=0;i<n;i++)
	{
		list->data=i;
		if(i==n-1)
		{
			list->next=NULL;
			break;
		}
		temp=(node*)malloc(sizeof(node));
		list->next=temp;
		list=temp;	
	}


}

main()
{
	node* head = (node*)malloc(sizeof(node));
	createList(head,10);
	printList(head);




}
