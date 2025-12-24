#include <stdio.h>

int n, a[10][10], vis[10], src;
void dfs(int v);
void bfs(int v);
int main()
{
    int i, j, connected = 1;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("a[%d][%d]=",i,j);
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }
    printf("\nDFS traversal: ");
    dfs(1);

    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("\nGraph is connected");
    else
        printf("\nGraph is not connected");
    for (i = 1; i <= n; i++)
        vis[i] = 0;

    printf("\nEnter source vertex for BFS: ");
    scanf("%d", &src);

    printf("BFS traversal: ");
    bfs(src);

    return 0;
}
void dfs(int v)
{
    int j;
    vis[v] = 1;
    printf("%d ", v);

    for (j = 1; j <= n; j++)
    {
        if (a[v][j] == 1 && vis[j] == 0)
            dfs(j);
    }
}
void bfs(int v)
{
    int q[10], f = 0, r = 0, u, i;

    q[r++] = v;
    vis[v] = 1;

    while (f < r)
    {
        u = q[f++];
        printf("%d ", u);

        for (i = 1; i <= n; i++)
        {
            if (a[u][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                q[r++] = i;
            }
        }
    }
}
