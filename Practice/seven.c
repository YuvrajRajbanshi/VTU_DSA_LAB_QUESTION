#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODEPTR;

int main()
{
    NODEPTR node1 = (NODEPTR)malloc(sizeof(struct node));
    node1->data = 13;
    node1->link = NULL;

    NODEPTR node2 = (NODEPTR)malloc(sizeof(struct node));
    node2->data = 12;
    node2->link = node1;

    printf("%d", node2->link->data);
}