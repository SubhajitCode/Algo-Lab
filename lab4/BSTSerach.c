#include <stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	struct node *right;
	int data;
	int visted;
};
int i=0;


void insertBSTNode(bstnode *bstRoot,int data)
{

	bstnode *bstNode=(bstnode*)malloc(sizeof(bstnode));
	bstNode->data=data;
	bstNode->left=NULL;
	bstNode->right=NULL;
	bstNode->visted=0;
	bstnode *currentnode = bstRoot;
	while(1)
	{
		if (bstNode->data >= currentnode->data)
		{
			if(currentnode->right==NULL)
			{
				currentnode->right=bstNode;
				break;
			}
			else
			{
				currentnode = currentnode->right;
			}
		}
		else
		{
			if(currentnode->left==NULL)
			{
				currentnode->left=bstNode;
				break;
			}
			else
			{
				currentnode = currentnode->left;
			}
		}
	}


}
void printBst(bstnode *root)
{
	int level;

}
void inOrderTraverse(bstnode *root,int arr[])
{
	if (root==NULL) {
		return;
	}

	inOrderTraverse(root->left,arr);
	arr[i]=root->data;
	i++;
	//printf("%d  i%d  ",root->data,i);
	inOrderTraverse(root->right,arr);

}

void main()
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
	int arr[count];
	bstnode *copy=root;
	inOrderTraverse(copy,arr);
	for(i = 0; i < count; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n----------------Finding compleate-----------------\n");



}
