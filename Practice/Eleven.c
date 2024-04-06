#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5
#define SIZE 5

typedef struct
{

    int items[10];
    int front;
    int rear;
} Queue;

// typedef struct node *NODEPTR;

int fnBreadthSearch(int vertex, int g[MAX][MAX], int visited[], int n);
int fnFull(Queue *stQueue);
int fnEmpty(Queue *stQueue);
void fnInsert(Queue *stQueue, int item);
int fnDelete(Queue *stQueue);

int main()
{

    int g[MAX][MAX];
    int visited[MAX];
    int number, starVert;

    printf("\nEnter the number vertex  ");
    scanf("%d", &number);

    printf("Enter the adjency matrix");
    for (int i = 0; i < number; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    printf("\n Enter the starting vertex...");
    scanf("%d", &starVert);

    fnBreadthSearch(starVert - 1, g, visited, number);
    for (int i = 0; i < number; i++)
    {
        if (visited[i])
        {
            printf("%d", i + 1);
        }
        printf("\n");
    }
}

int fnFull(Queue *stQueue)
{

    if (stQueue->rear = SIZE - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int fnEmpty(Queue *stQueue)
{
    if (stQueue->rear = stQueue->front - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void fnInser(Queue *stQueue, int item)
{

    if (fnFull)
    {
        printf("\n The stack overflow");
    }
    else
    {
        stQueue->rear++;
        stQueue->items[stQueue->rear] = item;
    }
}

int fnDelete(Queue *stQueue)
{

    if (fnEmpty)
    {
        printf("\nThe stack underflow");
    }
    else
    {
        int item = stQueue->items[stQueue->rear];
        stQueue->rear--;
        return item;
    }
}

int fnBreadthSearch(int vertex, int g[MAX][MAX], int visited[], int n)
{

    Queue stQueue;
    stQueue.front = 0;
    stQueue.rear = -1;
    int frontVertex, i;

    visited[vertex] = 1;
    fnInser(&stQueue, vertex);

    while (!fnEmpty(&stQueue))
    {
        /* code */
        frontVertex = fnDelete(&stQueue);

        for (i = 0; i < n; i++)
        {

            if (g[frontVertex][i] & !visited[i])
            {
                visited[i] = 1;
                fnInser(&stQueue, i);
            }
        }
    }
}