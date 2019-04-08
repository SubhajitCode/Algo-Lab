#include <stdio.h>
#include <stdlib.h>
#define INF 9999
#define V 4
void printMatrix(int mat[][V])
{
    int i,j;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (mat[i][j]==INF) {
               printf("%7s","INF");
            }
            else
                printf("%7d",mat[i][j]);
        }
        printf("\n");
    }
    
}
void floyedWarshall(int graph[][V])
{
    int dist[V][V];
    //intialize the Distance
    int i, j, k;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if(dist[i][j]>(dist[i][k]+dist[k][j]))
                {
                    dist[i][j]=(dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    //printing the soltion Matrinx
    printMatrix(dist);

}

int main()
{
    int graph[V][V] = {{0, 5, INF, 10},
                       {INF, 0, 3, INF},
                       {INF, INF, 0, 1},
                       {INF, INF, INF, 0}};
    floyedWarshall(graph);

    return 0;
}