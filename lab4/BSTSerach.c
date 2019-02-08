#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    struct node *right;
    int data;
    int visted;
};

typedef struct node bstnode;
void bstTravel()
{
}

void insertBSTNode(bstnode *bstRoot,int data)
{
 
    bstnode *bstNode=(bstnode*)malloc(sizeof(bstnode));
    bstNode->data=data;
    bstNode->left=NULL;
    bstNode->right=NULL;
    bstNode->visted=0;
    bstnode *currentnode = bstRoot;
    while((currentnode->left!=NULL)&&(currentnode->right!=NULL))
    {
        if (bstNode->data >= currentnode->data)
        {
            currentnode = currentnode->right;
        }
        else
        {
            currentnode = currentnode->left;
        }
    }
        if (bstNode->data >= currentnode->data)
        {
             currentnode->right=bstNode;
        }
        else
        {
            currentnode->left=bstNode;
        }

}
void printBst(bstnode *root)
{
    int level;

}
int findMinBst(bstnode *root)
{
    bstnode *currentNode=root;
    while(currentNode->left!=NULL)
    {
        if (currentNode->visted==1) {
            //go right
            currentNode=currentNode->right;
        }
        else
        {
            currentNode=currentNode->left; 
            /* Go Left */
        }
        
              
    }
    int min=currentNode->data;
    currentNode->visted=1;  
    return min; 

}

main()
{
    bstnode *root = (bstnode*)malloc(sizeof(bstnode));
    root->data=100;
    root->left=NULL;
    root->right=NULL;
    root->visted=0;
    int count =20;
    int i;
    for(i = 0; i < count-1; i++)
    {
        int data=rand()%count;
        insertBSTNode(root,data);
        printf("%d\t",data);
    }
    printf("\n----------------Insertion compleate-----------------\n");
    for(i = 0; i < count; i++)
    {
        printf("%d\t",findMinBst(root));
    }
    printf("\n----------------Finding compleate-----------------\n");
    printf("\n%d\n",root->left->left->data);
    

}
