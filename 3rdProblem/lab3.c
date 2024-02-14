
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4
void fnPush(int[], int, int *);
int fnPop(int[], int *);
void fnDisplay(int[], int);
bool fnStkFull(int);
bool fnStkEmpty(int);
int fnPeek(int[], int);
bool fnChkPalindrome(int);
int main(void)
{
    int stkArray[MAX];
    int top = -1;
    // top -1 because firtly the stack is empyt, if it is zero then one element is there
    // because it's follows the array indexing that's it
    int iElem, iChoice;
    for (;;)
    {
        printf("\nSTACK OPERATIONS\n");
        printf("====================");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Check Palindrome\n6.Demonstarte Overflow\n7.Demonstarte Underflow\n8.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d", &iChoice);
        switch (iChoice)
        {
        case 1:
            if (!fnStkFull(top))
            {
                printf("\nEnter element to be pushed onto the stack\n");
                scanf("%d", &iElem);
                fnPush(stkArray, iElem, &top);
            }
            else
            {
                printf("\nStack Overflown");
            }
            break;
        case 2:
            if (!fnStkEmpty(top))
            {
                // need  the scope of the variable
                iElem = fnPop(stkArray, &top);
                printf("\nPopped Element is %d\n", iElem);
            }
            else
            {
                printf("\nStack Underflow\n");
            }
            break;
        case 3:
            if (fnStkEmpty(top))
            {
                printf("\nStack Empty\n");
            }
            else
            {
                fnDisplay(stkArray, top);
            }
            break;
        case 4:
            if (!fnStkEmpty(top))
            {
                iElem = fnPeek(stkArray, top);
                printf("\nElement at the  top of the stack is %d\n", iElem);
            }
            else
                printf("\nEmpty Stack\n");
            break;
        case 5:
            printf("\nEnter number to be checked for a palindrome : ");
            scanf("%d", &iElem);
            if (fnChkPalindrome(iElem))
            {
                printf("\n%d is a palindrome\n", iElem);
            }
            else
            {
                printf("\n%d is not a palindrome\n", iElem);
            }
            break;
        case 6:
            if (!fnStkFull(top))
                printf("\nThere are currently %d elements in Stack\nPush %d elemnts for Stack to overflow", top + 1, MAX - (top + 1));
            while (!fnStkFull(top))
            {
                printf("\nEnter an element : ");
                scanf("%d", &iElem);
                fnPush(stkArray, iElem, &top);
            }
            printf("\nStack Overflow cannot push elements onto the stack\n");
            break;
        case 7:
            if (!fnStkEmpty(top))
                printf("\nThere are currently %d elements in Stack\nPop out %d elemnts for Stack to Underflow", top + 1, MAX - (top + 1));
            while (!fnStkEmpty(top))
            {
                iElem = fnPop(stkArray, &top);
                printf("nPopped Element is %dn", iElem);
            }
            printf("\nStack Underflow cannot pop elements from the stack\n");
            break;
        case 8:
            exit(1);
        default:
            printf("\nWrong choicen");
        }
    }
    return 0;
}

// seven derived function is here so i should understand every and each function

bool fnStkFull(int top)
{
    return ((top == MAX - 1) ? true : false);
}
bool fnStkEmpty(int t)
{
    return ((t == -1) ? true : false);
}
void fnPush(int stk[], int iElem, int *t)
{
    // why *t ( ask to mam)
    *t = *t + 1;
    stk[*t] = iElem;
}
int fnPop(int stk[], int *t)
{
    int iElem;
    iElem = stk[*t];
    *t = *t - 1;
    return iElem;
}
void fnDisplay(int stk[], int t)
{
    int i;
    printf("\nStack Contents are: \n");

    // ask to mam why this loop is ulta
    for (i = t; i > -1; --i)
    {
        printf("\t%d\n", stk[i]);
    }

    // why t + 1 (ask to mam )
    printf("Stack has %d elements\n", t + 1);
}
int fnPeek(int stk[], int t)
{
    return stk[t];
}

// not able to understand palindrom function ask to mam
bool fnChkPalindrome(int iVal)
{
    // here we declare array size is 10 what if I want to declare the array
    // is dynamically (ask to mam tomorrow )

    int palStk[10];
    // why t = -1 (ask to mam kindly)
    int t = -1, iDig, iRev = 0;
    int iCopy = iVal;
    while (iCopy != 0)
    {
        iDig = iCopy % 10;
        fnPush(palStk, iDig, &t);
        iCopy /= 10;
    }
    int p = 0;
    while (p <= t)
    {
        iDig = palStk[p];
        iRev = iRev * 10 + iDig;
        p++;
    }
    if (iRev == iVal)
        return true;
    else
        return false;
}
