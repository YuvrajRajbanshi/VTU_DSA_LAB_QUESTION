#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 50

void fnPush(int acStack[], int *top, int iElem);
int fnPop(int acStack[], int *top);
int fnPrecd(int symbol);

int main()
{

    int acStack[MAX];
    int top = -1, j = 0;
    char acExpr[100], postExpr[100], symb;
    printf("\nEnter a valid infix expression...");
    scanf("%s", acExpr);

    fnPush(acStack, &top, '#');

    for (int i = 0; acExpr[i] != '\0'; i++)
    {
        symb = acExpr[i];

        if (isalnum(acExpr[i]))
        {

            postExpr[j++] = symb;
        }

        else if (acExpr[i] == '(')
        {
            fnPush(acStack, &top, symb);
        }

        else if (acExpr[i] == ')')
        {
            while (acExpr[top] == '(')
            {
                acExpr[j++] = fnPop(acStack, &top);
                /* code */
            }
            fnPop(acStack, &top);
        }

        else
        {
            while (fnPrecd(acStack[top] > fnPrecd(symb)))
            {
                /* code */
                if (symb == '^' && acStack[top] == '^')
                    break;

                postExpr[j++] = fnPop(acStack, &top);
            }
            fnPush(acStack, &top, symb);
        }
    }

    while (acStack[top] == '#')
    {
        postExpr[j++] = fnPop(acStack, &top);
        /* code */
    }
    postExpr[j] = '\0';

    printf("\nInfix Expression is %s\n", acExpr);
    printf("\nPostfix Expression is %s\n", postExpr);
    return 0;
}

void fnPush(int acStack[], int *top, int iElem)
{

    acStack[*top] = *top;
    *top = *top + 1;
}

int fnPop(int acStack[], int *top)
{

    int iElem;
    iElem = acStack[*top];
    *top = *top - 1;

    return iElem;
}

int fnPrecd(int symbol)
{

    int iPreced;
    switch (symbol)
    {
    case '#':
        iPreced = -1;
        break;

    case '(':
        iPreced = 0;
        break;

    case '+':
    case '-':
        iPreced = 1;
        break;

    case '*':
    case '/':
    case '%':
        iPreced = 2;
        break;

    case '^':
        iPreced = 3;
    default:
        printf("Invalid choice boi");
        break;
    }
}
