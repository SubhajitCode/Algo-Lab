#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define V 4
#define INF 99999
void printSoln(int dist[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Vertex (%d) -------------->Distance(%d)\n",i,dist[i]);
	}
}
void Dijkstra( int Weight[][V],int src )
{
	int dist[V];
	int i,j;
	for(i=0;i<V;i++)
	{
		dist[i]=INF;
	}
	dist[src]=0;
	bool included[V];
	for(i=0;i<V;i++)
		included[i]=false;
	for(i=0;i<V-1;i++)
	{
		int min=INF,idx=0;
		for(j=0;j<V;j++)
		{
			if((included[j]==false)&&(min>dist[j]))
			{
				min=dist[j];
				idx=j;
			}
		}
		printf("%d %d ",min,idx);
		included[idx]=true;
		for(j=0;j<V;j++)
		{
			if((dist[j]>(min+Weight[idx][j]))&&!included[j])
			{
				dist[j]=Weight[idx][j]+min;
			}
		}
	}
	printSoln(dist,V);

}

int main()
{
	int Graph[V][V]={{0, 5, INF, 10},
		{INF, 0, 3, INF},
		{INF, 2, 0, 1},
		{INF, INF, INF, 0}};	
	Dijkstra(Graph,0);
	return 0;
}

