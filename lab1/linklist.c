#include <stdio.h>
 struct linklist
{
    int data;
    struct linklist *next;
} ;

void main()
{
    struct linklist link[4];
    int i;
    struct linklist *list=&link[0];
    for (i=0;i<4;i++)
    {
        link[i].next=&link[i+1];
    }
    link[4].next=NULL;

    for (i=0;i<5;i++)
    {
        list->data=i;//rand()%10;
        if (i==5)
            continue;
        list=list->next;
    }
    list=&link[0];
    for (i=0;;i++)
    {
        printf("%d ",list->data);
        if(list->next==NULL)
            break;
        list=list->next;
    }
    printf("\n-----------------------------------------------------------------\n");
    

}
