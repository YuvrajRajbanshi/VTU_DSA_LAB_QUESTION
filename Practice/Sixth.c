#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100

void fnInsRear(char myString[], int *r, int *f, char val);
char fnDelFront(char myString[], int *r, int *f);
int fnQueFull(int r, int f);
int fnQueEmpty(int r, int f);
int fnDisplay(char myString[], int r, int f);
int main()
{
    char myString[MAX];
    int f = -1;
    int r = -1;
    int choice;
    char string;

    for (;;)
    {

        printf("\nQueue operation are going here ");
        printf("\n1.QInsert \n2.QDelete \n3.QDisplay \n4.Exit");

        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (!fnQueFull(r, f))
            {
                printf("\nEnter the string you want.. ");
                scanf("%s", string);
                fnInsRear(myString, &r, &f, string);
            }
            else
            {
                printf("\nThe queue is full ");
            }
            break;

        case 2:
            if (!fnQueEmpty(r, f))
            {
                string = fnDelFront(myString, &r, &f);
                printf("The deleted elements are here ", string);
            }
            else
            {
                printf("\nThe queue is full");
            }
            break;

        case 3:
            fnDisplay(myString, r, f);
            break;

        case 5:
            exit(0);
        }
    }
}
int fnQueFull(int r, int f)
{
    return (r + 1) % MAX ? true : false;
}
int fnQueEmpty(int r, int f)
{
    return (r == -1) ? true : false;
}

void fnInsRear(char myString[], int *r, int *f, char val)
{
    if (*f == -1)
    {
        *r = *r + 1;
        *f = *f + 1;
    }
    else
    {
        *r = (*r + 1) % MAX;
    }
    myString[*r] = val;
}

char fnDelFront(char myString[], int *r, int *f)
{

    int elem = myString[*r];
    if (*r == *f)
    {
        *r = -1;
        *f = -1;
    }
    else
    {
        *f = (*f + 1) % MAX;
    }

    return elem;
}

int fnDisplay(char myString[], int r, int f)
{

    for (int i = 0; i < r; i++)
    {
        printf("%s", myString[i]);
    }
}