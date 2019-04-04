#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int vertexNum;
    int weight;
    struct Node* next;
};
struct Edge
{
    int srcVertex;
    int destVertex;
    int weight;
   
};
struct heapNode{
    int Vertex;
    int key;
};
typedef struct heapNode heapNode;
struct Heap{    
    int size;
    heapNode** arr;
    int *pos;
};

typedef struct Node node;
typedef struct Edge Edge;
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
void createEdge(node* vertex,int weight,int vertexNum)
{
    while(vertex->next!=NULL){
       vertex=vertex->next;
    }
    vertex->next=newNode(weight,vertexNum);   
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
    if (right<n && heap->arr[right]->key<heap->arr[min_idx]->key) {
        min_idx=right;
    }
    if (left<n && heap->arr[left]->key<heap->arr[min_idx]->key) {
       min_idx=left;
    }
    if (min_idx!=pos) {
        
        swap(&heap->arr[min_idx],&heap->arr[pos]);
        heap->pos[heap->arr[min_idx]->Vertex]=pos;
        heap->pos[heap->arr[pos]->Vertex]=min_idx;
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
    heapNode* min=heap->arr[0];
    int n=heap->size;
    heap->arr[0]=heap->arr[n-1];
    heap->pos[heap->arr[0]->Vertex]=0;
    heap->pos[min->Vertex]=n-1;
    heap->size--;
    heapify(heap,0);
    return min;
}
void decreaseKey(Heap* heap,int Vertex,int key)
{
    int i=heap->pos[Vertex];
    int parent_idx=(i-1)/2;
    heap->arr[i]->key=key;
    while(i>=0&&heap->arr[i]->key<heap->arr[parent_idx]->key)
    {
        heap->pos[heap->arr[i]->Vertex]=parent_idx;
        heap->pos[heap->arr[parent_idx]->Vertex]=i;
        swap(&heap->arr[i],&heap->arr[parent_idx]);
        i=parent_idx;
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
    for(i=0;i<n;i++)
    {
        printf("%d - %d\t ---%d\n",edge[i].srcVertex,edge[i].destVertex,edge[i].weight);

    }

}
void primMST(node* vertex[],int n )
{
    Edge tree[n-1];
    int i;
    Heap* heap=newHeap(n);
    for( i = 0; i < n; i++)
    {
        heap->arr[i]=newHeapNode(i,__INT_MAX__);
        heap->pos[i]=i;  
    }
    heap->arr[0]->key=0;
    i=0;int src=-1,dest=-1;
    while(heap->size>0){
        heapNode* minNode=extractMin(heap);
        int u=minNode->Vertex;
        node* current_node=vertex[u]->next;
        while(current_node!=NULL){
            int v=current_node->vertexNum;
            if(isInHeap(heap,v)&&heap->arr[heap->pos[v]]->key>current_node->weight)
            {
                    decreaseKey(heap,v,current_node->weight);
                    tree[i++]=newEdge(u,v,current_node->weight);
            }
            current_node=current_node->next;
          
        }
        



    }
    printTree(tree,n-1);
    

}



int main()
{
    node* vertices[4];
    int i;
    for( i = 0; i < 4; i++)
    {
        vertices[i]=newNode(i,0);//vertex Initialization
    }
    createEdge(vertices[0],2,1);
    createEdge(vertices[1],2,2);
    createEdge(vertices[0],1,2);
    createEdge(vertices[2],3,3);
    primMST(vertices,4);
    printf("debug\n");

return 0;
}
