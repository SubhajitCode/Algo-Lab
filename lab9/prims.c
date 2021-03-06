//prims algorithm Heap imlementation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
struct Node{
    int vertexNum;
    int weight;
    struct Node* next;
};
typedef struct Node node;
struct Edge
{
    int srcVertex;
    int destVertex;
    int weight;
   
};
typedef struct Edge Edge;
struct heapNode{
    int Vertex;
    int key;
    Edge edge;
};
typedef struct heapNode heapNode;
struct Heap{    
    int size;
    heapNode** arr;
    int *pos;
};
typedef struct Heap Heap;
void swap(heapNode **a,heapNode **b)
{
	heapNode* temp=*a;
	*a=*b;
	*b=temp;

}
heapNode* newHeapNode(int v,int key)
{
    heapNode* haepnode=(heapNode*)malloc(sizeof(heapNode)); 
    haepnode->Vertex=v ;
    haepnode->key=key;
    return haepnode;
}


node* newNode(int weight,int vertexNum)
{
    node* tempNode=(node*)malloc(sizeof(node));
    tempNode->vertexNum=vertexNum;
    tempNode->weight=weight;
    tempNode->next=NULL;
    return tempNode;
}
void createEdge(node* graph[],int src,int weight,int dest)
{
    node* vertex=graph[src];
    while(vertex->next!=NULL){
       vertex=vertex->next;
    }
    vertex->next=newNode(weight,dest); 
    vertex=  graph[dest];
     while(vertex->next!=NULL){
       vertex=vertex->next;
    }
    vertex->next=newNode(weight,src);
}
Edge newEdge(int src,int dest,int weight)
{
    Edge edge;
    edge.srcVertex=src;
    edge.destVertex=dest;
    edge.weight=weight;
    return edge;
}
void heapify(Heap* heap,int pos)
{

    int n=heap->size;
    int min_idx=pos;
    int left=2*pos+1;
    int right=2*pos+2;
    if (left<n && heap->arr[left]->key<heap->arr[min_idx]->key) {
       min_idx=left;
    }
    if (right<n && heap->arr[right]->key<heap->arr[min_idx]->key) {
        min_idx=right;
    }
    if (min_idx!=pos) {
        
        heap->pos[heap->arr[min_idx]->Vertex]=pos;
        heap->pos[heap->arr[pos]->Vertex]=min_idx;
        swap(&heap->arr[min_idx],&heap->arr[pos]);
        heapify(heap,min_idx);
    }
}
void buildHeap(Heap* heap)
{
    int i,n=heap->size;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(heap,i);
    }

}
heapNode* extractMin(Heap* heap)
{
    if(heap->size==0)
        return NULL;
    heapNode* min=heap->arr[0];
    int n=heap->size;
    heap->arr[0]=heap->arr[n-1];
    heap->pos[heap->arr[n-1]->Vertex]=0;
    heap->pos[min->Vertex]=n-1;
    heap->size--;
    heapify(heap,0);
    return min;
}
void decreaseKey(Heap* heap,int Vertex,int key,Edge edge)
{
    int i=heap->pos[Vertex];
    int parent_idx=(i-1)/2;
    heap->arr[i]->key=key;
    heap->arr[i]->edge=edge;
    while(i>0&&heap->arr[i]->key<heap->arr[parent_idx]->key)
    {
        heap->pos[heap->arr[i]->Vertex]=parent_idx;
        heap->pos[heap->arr[parent_idx]->Vertex]=i;
        swap(&heap->arr[i],&heap->arr[parent_idx]);
        i=parent_idx;
        parent_idx=(i-1)/2;
    }
}
bool isInHeap(Heap* heap,int v)
{
    if (heap->pos[v]<heap->size) {
        return true;
    }
    return false;
}
Heap* newHeap(int size)
{
    Heap* heap=(Heap*)malloc(sizeof(heap));
    heap->size=size;
    heap->arr=(heapNode**)malloc(sizeof(heapNode*)*size);
    heap->pos=(int*)malloc(sizeof(int)*size);
    return heap;
}
void printTree(Edge edge[],int n)
{
    int i;
    int sum=0;
    for(i=1;i<n;i++)
    {
        printf("%d - %d\t ---%d\n",edge[i].srcVertex,edge[i].destVertex,edge[i].weight);
        sum=sum+edge[i].weight;

    }
 printf(" ----------Sum ofthe weight is ---%d\n",sum );
}

void print_heap(heapNode* heap[],int size)
{
    //debug features
    printf(" ----------heap start -------------\n");
	int no_rows=log(size)/log(2)+1;
	int i,j,k=1,l=0,m;
	for(i=0;i<no_rows;i++)
	{
		for(j=0;j<pow(2,(no_rows-i-1))-1;j++)
			printf(" ");
		for(m=0;m<k;m++)
		{
            if (heap[l]->key>10) {
                printf("%d.%c",heap[l]->Vertex,'M');
            }
            else
            {
                printf("%d.%d",heap[l]->Vertex,heap[l]->key);
            }
            l++;
				if(l>=size)
					break;
			for(j=0;j<pow(2,(no_rows-i))-1;j++)
			{
				printf(" ");
			}
		}
		printf("\n");
		k=k*2;
	}
     printf(" ----------heap end -------------\n");
}

void primMST(node* vertex[],int n )
{
    Edge tree[n];
    int parent[n];
    int key[n];
    int i;
    Heap* heap=newHeap(n);
    for( i = 0; i < n; i++)
    {
        parent[i]=-1;
        key[i]=__INT_MAX__;
        heap->arr[i]=newHeapNode(i,__INT_MAX__);
        heap->pos[i]=i;  
    }
    heap->arr[0]->key=0;
    heap->pos[0]=0;
    key[0]=0;
    i=0;int src=-1,dest=-1;
    while(heap->size!=0){
        heapNode* minNode=extractMin(heap);
        tree[i++]=minNode->edge;
        int u=minNode->Vertex;
        node* current_node=vertex[u]->next;
        while(current_node!=NULL){
            int v=current_node->vertexNum;
            if(isInHeap(heap,v)&&heap->arr[heap->pos[v]]->key>current_node->weight)
            {
                    Edge edge=newEdge(u,v,current_node->weight);
                    key[v]=current_node->weight;
                    parent[v]=u;
                    decreaseKey(heap,v,current_node->weight,edge);
            }
            current_node=current_node->next;
          
        }
        



    }
    printTree(tree,n);
   //printArray(parent,n);
    

}



int main()
{
    node* vertices[9];
    int i;
    for( i = 0; i < 9; i++)
    {
        vertices[i]=newNode(i,0);//vertex Initialization
    }
    createEdge(vertices,0,4,1);//adding eache edge
    createEdge(vertices,0,8,7);
    createEdge(vertices,1,8,2);
    createEdge(vertices,1,11,7);
    createEdge(vertices,2,7,3);
    createEdge(vertices,2,2,8);
    createEdge(vertices,2,4,5);
    createEdge(vertices,3,9,4);
    createEdge(vertices,3,14,5);
    createEdge(vertices,4,10,5);
    createEdge(vertices,5,2,6);
    createEdge(vertices,6,1,7);
    createEdge(vertices,6,6,8);
    createEdge(vertices,7,7,8);

    primMST(vertices,9);

return 0;
}
