#include <stdio.h>
#include <stdlib.h>
struct link
{
    int data;
    struct link *next;
};
typedef struct link link;
void print(link *head)
{
    printf("Printing -------------------------------------------------\n");

    int i;
    link *list = head;
    while (1)
    {
        printf("%d\t", list->data);
        list = list->next;
        if (list == NULL)
            break;
    }
    printf("\n");
    printf("Printing ------------------End-------------------------\n");
}
void delete_next_node(link *node)
{
    node->next = node->next->next;
    // free(node->next);
}

link *inverse(link *head)
{
    link *tail = head;
    link *node1 = head;
    link *node2 = head->next;
    link *temp;
    while (1)
    {
        //node2 should point to node1
        temp = node2->next; //store node2s next pointer
        node2->next = node1;
        //propagate nodes to the next nodes
        node1 = node2;
        if (temp == NULL)
        {

            tail->next = NULL;
            head = node1;
            break;
        }

        node2 = temp;
    }

    return head;
}

void removedup(link *head)
{

    int i = 0;
    link *list = head;
    while (1)
    {
        //fflush(stdout);
        //printf("%d\t",list->data);
    retry:
        if (list->next == NULL)
            break;
        if (list->data == list->next->data)
        {

            delete_next_node(list);
            if (list->next == NULL)
                break;
            goto retry;
        }
        list = list->next;
    }
}

void main()
{

    link *list = malloc(sizeof(link));
    link *head = list;
    int i;
    int length = 20;
    for (i = 0; i < length; i++)
    {
        list->data = 50 / (i + 1);
        if (length - 1 <= i)
            break;

        link *temp = (link *)malloc(sizeof(link));
        list->next = temp;
        list = temp;
    }
    list = NULL;
    print(head);
    removedup(head);
    print(head);
}
