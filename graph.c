#include <stdio.h>
int a[10][10], visit[10], n;
void dfs(int v)
{
    visit[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[v][i] == 1 && visit[i] == 0)
        {
            dfs(i);
        }
    }
}
void main()
{
    int v, i, j;
    printf("\nEnter size: ");
    scanf(" %d", &n);
    printf("\nEnter matrix: ");
    for (i = 0; i < n; i++)
    {
        visit[i] = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter starting vector: ");
    scanf(" %d", &v);
    dfs(v);
    printf("\nnodes visitable from %d : ", v);
    for (i = 0; i < n; i++)
    {
        if (visit[i] == 1 && i != v)
        {
            printf("%d\t", i);
        }
    }
}