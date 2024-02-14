// 11. Develop a Program in C for the following operations on Graph(G)
// of Cities
//         a.Create a Graph of N cities using Adjacency Matrix.b.Print all the nodes reachable from a given starting node in a digraph using DFS /
//     BFS
//         method

#include <stdio.h>
#include <stdio.h>

const int MAX = 100;
const int SIZE = 10;
void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);

typedef struct
{
    int iaItems[10];
    int iFront;
    int iRear;
} QUEUE;

void fnQInsert(QUEUE *stQueue, int elem);
int fnQDelete(QUEUE *stQueue);
int fnQFull(QUEUE *stQueue);
int fnQEmpty(QUEUE *stQueue);

int main(void)
{
    int graph[MAX][MAX];
    int visited[MAX];
    int numVert, startVert, i, j;

    printf("Enter the number of vertices : ");
    scanf("%d", &numVert);
    printf("Enter the adjacency matrix :\n");
    for (i = 0; i < numVert; i++)
        visited[i] = 0;
    for (i = 0; i < numVert; i++)
        for (j = 0; j < numVert; j++)
            scanf("%d", &graph[i][j]);
    printf("Enter the starting vertex : ");
    scanf("%d", &startVert);
    fnBreadthFirstSearchReach(startVert - 1, graph, visited, numVert);
    printf("Vertices which can be reached from vertex %d are :-\n", startVert);
    for (i = 0; i < numVert; i++)
        if (visited[i])
            printf("%d ", i + 1);
    printf("\n");
    return 0;
}

void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n)
{
    QUEUE stQueue;
    stQueue.iFront = 0;
    stQueue.iRear = -1;
    int frontVertex, i;
    v[vertex] = 1;
    fnQInsert(&stQueue, vertex);
    while (!fnQEmpty(&stQueue))
    {
        frontVertex = fnQDelete(&stQueue);
        for (i = 0; i < n; i++)
        {
            if (g[frontVertex][i] && !v[i])
            {
                v[i] = 1;
                fnQInsert(&stQueue, i);
            }
        }
    }
}

void fnQInsert(QUEUE *stQueue, int iItem)
{
    if (fnQFull(stQueue))
        printf("\nQueue Overflow\n");
    else
    {
        stQueue->iRear++;
        stQueue->iaItems[stQueue->iRear] = iItem;
    }
}

int fnQDelete(QUEUE *stQueue)
{
    int item;
    if (fnQEmpty(stQueue))
        printf("\nQueue Underflow\n");
    else if (stQueue->iRear == stQueue->iFront)
    {
        item = stQueue->iaItems[stQueue->iFront];
        stQueue->iRear = -1;
        stQueue->iFront = 0;
    }
    else
    {
        item = stQueue->iaItems[stQueue->iFront++];
    }
    return item;
}

int fnQFull(QUEUE *stQueue)
{
    if (stQueue->iRear == SIZE - 1)
        return 1;
    else
        return 0;
}

int fnQEmpty(QUEUE *stQueue)
{
    if (stQueue->iRear == stQueue->iFront - 1)
        return 1;
    else
        return 0;
}

// Enter the number of vertices : 4 Enter the adjacency matrix : 0 1 0 0 1 0 0 0 0 0 0 1 0 0 1 0 Enter the starting vertex : 1 Vertices which can be reached from vertex 1 are : -1 2

// Enter the number of vertices : 4
// Enter the adjacency matrix :
// 0 1 0 0
// 1 0 0 0
// 0 0 0 1
// 0 0 1 0
// Enter the source vertex : 3

// Vertex 1 is not reachable

// Vertex 2 is not reachable

// Vertex 3 is reachable

// Vertex 4 is reachable
