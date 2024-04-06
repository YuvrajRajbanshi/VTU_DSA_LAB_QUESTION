#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 5

void fnPush(int myArray[], int *top, int elem);
int fnPop(int myArray[], int *top);
int fnEmpty(int top);
int fnFull(int top);
int fnPeek(int myArray[], int top);
void fnDisplay(int myArray[], int top);

int main()
{

    int top = 1;
    int myArray[MAX], choice;
    int elem;

    int pElem;
    printf("\nHere we are in Stack");

    for (;;)
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Display \n5.Peek \n6.Exit");
        printf("\nEnter your choice ..");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (fnFull)
            {
                printf("\nEnter the elemetn for push...");
                scanf("%d", &elem);
                fnPush(myArray, &top, elem);
            }
            else
            {
                printf("\nStack is already full my boi");
            }
            break;

        case 2:
            if (fnEmpty)
            {
                int iElem = fnPop(myArray, &top);
                printf("\nThe Popped element is %d", iElem);
            }
            else
            {
                printf("\nThe stack is empty re baba");
            }
            break;
        case 3:
            fnDisplay(myArray, top);
            break;
        case 4:
            pElem = fnPeek(myArray, top);
            printf("\nThe top most element is %d", pElem);
            break;

        case 5:
            exit(0);
        default:
            printf("You have made the wrong choice like mine ");
        }
    }
}
int fnEmpty(int top)
{

    return (top == -1) ? true : false;
}
int fnFull(int top)
{
    return (top == MAX - 1) ? true : false;
}

void fnPush(int myArray[], int *top, int elem)
{

    *top = *top + 1;

    myArray[*top] = elem;
}
int fnPop(int myArray[], int *top)
{

    int elem;
    elem = myArray[*top];
    *top = *top - 1;
    return elem;
}
int fnPeek(int myArray[], int top)
{

    if (top == -1)
    {
        printf("\nStack is empty ");
    }
    return myArray[top];
}

void fnDisplay(int myArray[], int top)
{
    printf("\nStack content are here");

    for (int i = 0; i > top; i--)
    {
        printf("%d\n", myArray[i]);
    }
}