#include <stdio.h>
#include <stdlib.h>

int visited[20], stack[20], queue[20];
int top = -1, rear = -1, front = -1, n;
int adjacent[20][20];
void dfs(int);
void bfs(int);
void main()
{
    int i, j, s;
    int ch;

    printf("\nEnter no of vertices:");
    scanf("%d", &n);

    printf("Enter the Adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adjacent[i][j]);
        }
    }

    while (1)
    {
        for (i = 1; i <= n; i++)
            visited[i] = 0;

        printf("\nEnter 0/1 for BFS or DFS(-1 to terminate):\t");
        scanf("%d", &ch);

        switch (ch)
        {
        case 0:
            printf("\nEnter starting node:\t");
            scanf("%d", &s);
            printf("BFS Traversal:\n");
            bfs(s);
            break;
        case 1:
            printf("\nEnter starting node:\t");
            scanf("%d", &s);
            printf("DFS Traversal:\n");
            dfs(s);
            break;
        case -1:
            exit(0);
        default:
            printf("Enter valid choice!\n");
        }
    }
}
void bfs(int s)
{
    int i, node;
    printf("%d -> ", s);
    front = 0;
    queue[++rear] = s;
    visited[s] = 1;
    while (front <= rear)
    {
        node = queue[front++];
        for (i = 1; i <= n; i++)
        {
            if (adjacent[node][i] == 1 && visited[i] != 1)
            {
                printf("%d -> ", i);
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
void dfs(int s)
{
    int i;
    stack[++top] = s;
    printf("%d -> ", s);
    visited[s] = 1;
    for (i = 1; i <= n; i++)
    {
        if (adjacent[s][i] == 1 && visited[i] != 1)
        {
            dfs(i);
        }
    }
    stack[top--];
}
