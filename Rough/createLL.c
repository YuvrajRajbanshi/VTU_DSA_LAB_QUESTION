#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

void traverseSl(struct Node *ptr)
{

    while (ptr != NULL)
    {
        /* code */
        printf("The element is %d\n", ptr->data);
        printf("%d\n", &ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // creating memory for this

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    // link the first and the second node
    head->data = 10;
    head->next = second;

    // link the second and third node
    second->data = 20;
    second->next = third;

    // Terminate the with the third node
    third->data = 30;
    third->next = NULL;

    traverseSl(head);
}