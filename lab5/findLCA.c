#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};
typedef struct node bstnode;

struct link
{
    int data;
    struct link *next;
};
typedef struct link link;
struct list
{
    link *head;
    int size;
};
typedef struct list list;

int i = 0;
int getLink(list *list1, int n)
{
    link *head = list1->head;
    int i;
    for (i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            printf("Exception Null Pointer Acess\n");
            exit(1);
            /* code */
        }

        head = head->next;
    }
    return head->data;
}
pushLink(list *list1, int currentnode)
{
    link *head = list1->head;
    link *newnode = (link *)malloc(sizeof(link));
    newnode->data = currentnode;
    newnode->next = head;
    list1->head = newnode;
    list1->size++;
}
int popLink(list *list1)
{
    link *newhead = list1->head;
    int top = -1;
    if (newhead != NULL)
    {
        top = newhead->data;
        list1->head = newhead->next;
        list1->size--;
        free(newhead);
    }

    return top;
}
void insertBSTNode(bstnode *bstRoot, int data)
{

    bstnode *bstNode = (bstnode *)malloc(sizeof(bstnode));
    bstNode->data = data;
    bstNode->left = NULL;
    bstNode->right = NULL;
    bstnode *currentnode = bstRoot;
    while (1)
    {
        if (bstNode->data >= currentnode->data)
        {
            if (currentnode->right == NULL)
            {
                currentnode->right = bstNode;
                break;
            }
            else
            {
                currentnode = currentnode->right;
            }
        }
        else
        {
            if (currentnode->left == NULL)
            {
                currentnode->left = bstNode;
                break;
            }
            else
            {
                currentnode = currentnode->left;
            }
        }
    }
}
bstnode *newNode(int k)
{
    bstnode *temp = (bstnode *)malloc(sizeof(bstnode));
    temp->data = k;
    temp->left = temp->right = NULL;
    return temp;
}
bool findPath(bstnode *root, list *path, int k)
{

    if (root == NULL)
        return false;

    pushLink(path, root->data);
    if (root->data == k)
        return true;

    if ((root->left && findPath(root->left, path, k)) ||
        (root->right && findPath(root->right, path, k)))
        return true;
    popLink(path);
    return false;
}

int findLCA(bstnode *root, int n1, int n2)
{
    list path1;
    list path2;
    path1.head = NULL;
    path2.head = NULL;
    path1.size = 0;
    path2.size = 0;

    if (!findPath(root, &path1, n1) || !findPath(root, &path2, n2))
        return -1;
    int i;
    int j1, j2;
    for (i = 0; i < path1.size && i < path2.size; i++)
    {
        j1 = path1.size - i - 1;
        j2 = path2.size - i - 1;
        if (getLink(&path1, j1) != getLink(&path2, j2))
            break;
    }
    return getLink(&path1, j1 + 1);
}
void main()
{

    bstnode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printf("\n");
    printf("LCA of %d %d is =%d\n", 4, 6, findLCA(root, 4, 6));
    printf("LCA of %d %d is =%d\n", 6, 7, findLCA(root, 6, 7));
}