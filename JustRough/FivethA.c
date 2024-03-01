#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void fnPush(int myStack[], int *top, int iElem);
int fnPop(int myStack[], int *top);

int main()
{

    int myStack[50], iOptr1, iOptr2, iRes;
    int top = -1;
    char acExpr[100], symb;

    printf(" \nEnter the valid suffix expression... ");
    scanf("%s", acExpr);
    fnPush(myStack, &top, symb - '0');

    for (int i = 0; i < strlen(acExpr); i++)
    {

        symb = acExpr[i];
        if (isdigit(symb))
        {
            fnPush(myStack, &top, symb - '0');
        }

        else
        {
            iOptr1 = fnPop(myStack, &top);
            iOptr2 = fnPop(myStack, &top);

            switch (symb)
            {
            case '+':
                iRes = iOptr1 + iOptr2;
                break;
            case '-':
                iRes = iOptr1 - iOptr2;
                break;
            case '*':
                iRes = iOptr1 * iOptr2;
                break;
            case '%':
                iRes = iOptr1 % iOptr2;
                break;
            case '/':
                iRes = iOptr1 / iOptr2;
                break;
            case '^':
                iRes = (int)pow(iOptr1, iOptr2);
                break;
            }
            fnPush(myStack, &top, iRes);
        }
    }

    printf("\nThe problem is about to finished...");
    iRes = fnPop(myStack, &top);

    printf("\n The suffix expression %s is and value is %d", acExpr, iRes);
}

void fnPush(int myStack[], int *top, int iElem)
{

    *top = *top + 1;
    myStack[*top] = iElem;
}
int fnPop(int myStack[], int *top)
{

    int iElem;
    iElem = myStack[*top];
    *top = *top - 1;
    return iElem;
}
