#include<stdio.h>
#include<stdlib.h>
#define INF 9999
#define V 4
void printArray(int dist[],int v)
{
     printf("\n");  
    int i;
    for( i = 0; i < v; i++)
    {
       printf("%7d",dist[i]);
    }
    printf("\n");   

}
void bellmanFord(int graph[][V],int src)
{
    int dist[V];
    int predec[V];
    int i,j,k;
    for(i=0;i<V;i++)
        dist[i]=INF;
    dist[src]=0;
    for(k=0;k<V-1;k++)
    {
        for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                int u=i;
                int v=j;
                int w=graph[i][j];
                if ((dist[u]+w)<dist[v]) {
                    dist[v]=(dist[u]+w);
                    predec[v]=u;
                }
                

            }
        }
    }

    for(i=0;i<V;i++)
        {
            for(j=0;j<V;j++)
            {
                int u=i;
                int v=j;
                int w=graph[i][j];
                if ((dist[u]+w)<dist[v]) {
                   printf("\nGraph Contains Negetive Edge cycle\n");
                   exit(1);
                }
                

            }
        }


    printArray(dist,V);



}
int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, 2, 0, 1},
                       {INF, INF, INF, 0}};
    bellmanFord(graph,0);

return 0;
}
