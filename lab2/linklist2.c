#include<stdio.h>
#include<stdlib.h>
struct link{
    int data;
    struct link *next;
};
typedef struct link link;
void print(link* head)
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
}


link* inverse(link *head)
{
	link *tail=head;
	link *node1=head;
	link *node2=head->next;
	link *temp;
	while(1)
	{
		//node2 should point to node1
		temp=node2->next;//store node2s next pointer
		node2->next=node1;
		//propagate nodes to the next nodes
		node1=node2;
		if(temp==NULL)
		{
		
			tail->next=NULL;
			head=node1;
			break;
		}
		
		node2=temp;

	}

return head;

}


void main()
{   
   
    link *list =malloc(sizeof(link));
    link *head =list;
    int i;
    for(i=0;i<10;i++)
    {
        list->data=i;
        if(i==9)
            break;
        link *temp =(link*)malloc(sizeof(link));
        list->next=temp;
        list=temp;
    }
    list->next=NULL;
   print(head);
    head=inverse(head);
    print(head);


}
