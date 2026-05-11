#include<iostream>
using namespace std;

int graph[10][10];
int visited[10];
int queueArr[10];
int n;

void bfs(int start)
{
    int front = 0;
    int rear = 0;

    queueArr[rear] = start;
    rear++;

    visited[start] = 1;

    while(front < rear)
    {
        int current = queueArr[front];
        front++;

        cout<<current<<" ";

        for(int i=0;i<n;i++)
        {
            if(graph[current][i] == 1 && visited[i] == 0)
            {
                queueArr[rear] = i;
                rear++;

                visited[i] = 1;
            }
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

    cout<<"BFS Traversal: ";

    bfs(start);

    return 0;
}