#include<stdio.h>

int graph[10][10];
int visited[10];
int n;

void dfs(int start)
{
    printf("%d ",start);

    visited[start] = 1;

    for(int i=0;i<n;i++)
    {
        if(graph[start][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }

    int start;

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    printf("DFS Traversal: ");

    dfs(start);

    return 0;
}