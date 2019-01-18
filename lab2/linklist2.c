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
void insert(link *head,int n)
{
	link *list=head;
	int i;
	for(i=0;i<n-2;i++)
	{
		list=list->next;
	}
	printf("Enter the insert element\n");  
	link *temp=malloc(sizeof(link));
	int k;scanf("%d",&k);
	temp->data=k;
	temp->next=list->next;
	list->next=temp;
}
void delete(link *head,int n)
{
	link *list=head;
	int i;
	for(i=0;i<n-2;i++)
	{
		list=list->next;
	}
    link *temp=list->next;
    list->next=temp->next;

}
void inverse(link *head)
{
    link *list;
    link *temp;
    link *temp2;
    link *tail=head;
    temp =head;
    list =head;
    list=list->next;

    //while(temp2-)
    while(1)
    {
        
        temp2=list->next;
        list->next=temp;
        list=temp2;
        temp=temp->next;
        printf("%d \t",temp->data);
        if(list==NULL)
        {
            head=temp;
            break;
        }
            

    }
    tail->next=NULL;




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
    //insert(head,2);
    //print(head);
    //delete(head,2);
    //print(head);
    inverse(head);
    print(head);


}