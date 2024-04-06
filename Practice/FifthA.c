#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 4
void fnPush(int myArray[], int *top, int elem);
int fnPop(int myArray[], int *top);

int main()
{
    int myArray[MAX], top = -1;
    int iRes, iOpr1, iOpr2;
    char suffix[30];
    char symbol;
    printf("\nEnter the suffix expression... ");
    scanf("%s", suffix);

    // fnPush(myArray, &top, symbol - 'c');

    for (int i = 0; i < strlen(suffix); i++)
    {
        symbol = suffix[i];

        if (isdigit(symbol))
        {
            fnPush(myArray, &top, symbol - '0');
        }
        else
        {
            iOpr2 = fnPop(myArray, &top);
            iOpr1 = fnPop(myArray, &top);

            switch (symbol)
            {
            case '+':
                iRes = iOpr1 + iOpr2;
                break;
            case '-':
                iRes = iOpr1 - iOpr2;
                break;
            case '*':
                iRes = iOpr1 * iOpr2;
                break;
            case '/':
                iRes = iOpr1 / iOpr2;
                break;
            case '%':
                iRes = iOpr1 % iOpr2;
                break;
            }
            fnPush(myArray, &top, iRes);
        }
    }

    int result = fnPop(myArray, &top);

    printf("\nThe suffix expression is %s ", suffix);
    printf("\n The result ... %d", result);
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
