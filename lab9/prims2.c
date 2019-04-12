#include<stdio.h>
#include<stdbool.h>
#define V 5
#define INF 99999
#define INT_MAX 99999
struct Edge
{
	int src;
	int weight;
	int dest;

};

typedef struct Edge Edge;
Edge newEdge(int src,int weight,int dest)
{
	Edge edge;
	edge.src=src;
	edge.weight=weight;
	edge.dest=dest;
	return edge;
}

void printTree(Edge tree[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("(%d)--------%d---------->(%d)\n",tree[i].src,tree[i].weight,tree[i].dest);
	}
}
bool isValidEdge(int u,int v,bool visited[])
{
	if(u==v)
		return false;
	if(visited[u]&&!visited[v])
		return true;
	if(!visited[u]&&visited[v])
		return true;
	return false;
}

void primsMST(int Weight[][V])
{
	int src=0,i,j,k;
	bool visited[V];
	Edge tree[V-1];
	for(i=0;i<V;i++)
	{
			visited[V]=false;
	}
	visited[src]=true;
	for(k=0;k<V-1;k++)
	{
		int min=INF,a=-1,b=-1;
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				if(isValidEdge(i,j,visited)&&(min>Weight[i][j]))
				{
					a=i;
					b=j;
					min=Weight[i][j];
				}

			}
		}
		if((a!=-1)&&(b!=-1))
		{
			visited[a]=true;
			visited[b]=true;
			tree[k]=newEdge(a,min,b);
			printf("%d %d  %d\n",a,min,b);
		}
	}

	printTree(tree,V-1);

}
int main()
{
	int Graph[V][V]={ 
		{ INF, 2, INF, 6, INF }, 
		{ 2, INF, 3, 8, 5 }, 
		{ INF, 3, INF, INF, 7 }, 
		{ 6, 8, INF, INF, 9 }, 
		{ INF, 5, 7, 9, INF }, 
	};
       primsMST(Graph);	
	return 0;
}
