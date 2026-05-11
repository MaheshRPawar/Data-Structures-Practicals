#include<iostream>
using namespace std;

int graph[10][10];
int visited[10];
int n;

void dfs(int start)
{
    cout<<start<<" ";

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
    cout<<"Enter number of vertices: ";
    cin>>n;

    cout<<"Enter adjacency matrix:\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }

    int start;

    cout<<"Enter starting vertex: ";
    cin>>start;

    cout<<"DFS Traversal: ";

    dfs(start);

    return 0;
}