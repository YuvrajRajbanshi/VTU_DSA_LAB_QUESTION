

#include <stdio.h>
const int MAX = 100;
void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n);

int main(void)
{
    int i, j, k;
    int visited[MAX];
    int graph[MAX][MAX];
    int numVert, Vert;
    printf("Enter the number of vertices : ");
    scanf("%d", &numVert);
    for (i = 0; i < numVert; i++)
        visited[i] = 0;
    printf("Enter the adjacency matrix :\n");
    for (i = 0; i < numVert; i++)
        for (j = 0; j < numVert; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the source vertex : ");
    scanf("%d", &Vert);
    fnDepthFirstSearch(Vert, visited, graph, numVert);
    for (k = 0; k < numVert; k++)
    {
        if (visited[k])
        {
            printf("\nVertex %d is reachable\n", k + 1);
        }
        else
        {
            printf("\nVertex %d is not reachable\n", k + 1);
        }
    }
    return 0;
}

void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n)
{
    int i;
    v[currentVertex] = 1;
    for (i = 0; i < n; i++)
    {
        if (g[currentVertex][i] && !v[i])
            fnDepthFirstSearch(i, v, g, n);
    }
}
