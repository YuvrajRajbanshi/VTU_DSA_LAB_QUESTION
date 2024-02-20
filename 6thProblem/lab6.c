
// Develop a menu driven Program in C for the following operations on Circular QUEUE of
// Characters (Array Implementation of Queue with maximum size MAX)
// a. Insert an Element on to Circular QUEUE
// b. Delete an Element from Circular QUEUE
// c. Demonstrate Overflow and Underflow situations on Circular QUEUE
// d. Display the status of Circular QUEUE
// e. Exit
// Support the program with appropriate functions for each of the above operations
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_SIZE 100
void fnInsertRear(char[], int *, int *, char);
char fnDeleteFront(char[], int *, int *);
void fnDisplay(char[], int, int);
bool fnQueueFull(int, int);
bool fnQueueEmpty(int, int);
int main()
{
    char myQueue[QUEUE_SIZE];
    int iFront = -1, iRear = -1;
    int iChoice;
    char cElem;

    for (;;)
    {
        printf("\nQueue Operations\n");
        printf("=====================");
        printf("\n1.Qinsertn2.Qdeleten3.Qdisplayn4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &iChoice);
        getchar(); // read trialing enter character
        switch (iChoice)
        {
        case 1:
            if (!fnQueueFull(iFront, iRear))
            {
                printf("\nEnter an element : ");
                scanf("%c", &cElem);
                fnInsertRear(myQueue, &iFront, &iRear, cElem);
            }
            else
            {
                printf("\nQueue is Full\n");
            }
            break;
        case 2:
            if (!fnQueueEmpty(iFront, iRear))
            {
                cElem = fnDeleteFront(myQueue, &iFront, &iRear);
                printf("\nDeleted element is %c\n", cElem);
            }
            else
            {
                printf("\nQueue is Empty\n");
            }
            break;
        case 3:
            if (!fnQueueEmpty(iFront, iRear))
            {
                printf("\nContents of the Queue is \n");
                fnDisplay(myQueue, iFront, iRear);
            }
            else
            {
                printf("\nQueue is Empty\n");
            }
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}
bool fnQueueFull(int f, int r)
{
    if ((r + 1) % QUEUE_SIZE == f)
        return true;
    else
        return false;
}
bool fnQueueEmpty(int f, int r)
{
    if (f == -1)
        return true;
    else
        return false;
}
void fnInsertRear(char queue[], int *f, int *r, char cVal)
{

    // why *f = *f +1
    // this condition says that the circular queues is empty
    if (*r == -1)
    {
        *f = *f + 1;

        *r = *r + 1;
    }
    else
    {
        *r = (*r + 1) % QUEUE_SIZE;
    }

    queue[*r] = cVal;
}
char fnDeleteFront(char queue[], int *f, int *r)
{
    char cElem;
    cElem = queue[*f];

    // this if condition stands for if queues has only one element
    // still we want to delete the element
    if (*f == *r)
    {
        *f = -1;
        *r = -1;
    }
    else
    {
        *f = (*f + 1) % QUEUE_SIZE;
    }
    return cElem;
}
void fnDisplay(char queue[], int f, int r)
{
    int i;
    if (f <= r)
    {
        for (i = f; i <= r; i++)
        {
            printf("%c\t", queue[i]);
        }
        printf("\n");
    }
    else
    {
        for (i = f; i <= QUEUE_SIZE - 1; i++)
        {
            printf("%c\t", queue[i]);
        }
        for (i = 0; i <= r; i++)
        {
            printf("%ct", queue[i]);
        }
        printf("n");
    }
}
