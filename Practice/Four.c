#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void fnPush(char[], int *, char);
char fnPop(char[], int *);
int fnPrecd(char);
int main()
{

    int top = -1;
    char infix[30], stack[30], postfix[30], symbol;
    int i = 0;
    int j = 0;

    printf("\nEnter the infix expression ");
    scanf("%s", infix);
    fnPush(stack, &top, '#');
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        if (isalnum(symbol))
        {
            postfix[j++] = symbol;
        }
        else if (symbol == '(')
        {
            fnPush(stack, &top, symbol);
        }

        else if (symbol == ' )')
        {
            while (stack[top] != '(')
            {
                        }
        }
    }
}

void fnPush(char Stack[], int *t, char elem)
{
    *t = *t + 1;
    Stack[*t] = elem;
}
char fnPop(char Stack[], int *t)
{
    char elem;
    elem = Stack[*t];
    *t = *t - 1;
    return elem;
}

int fnPrecd(char symbol)
{

    int precd;
    switch (precd)
    {
    case '#':
        precd = -1;
        return precd;
        break;

    case '(':
        precd = 0;
        return precd;
        break;
    case '+':
    case '-':
        precd = 1;
        return precd;
        break;

    case '%':
    case '*':
    case '/':
        precd = 2;
        return precd;
        break;

    case '^':
        precd = 3;
        return precd;
    }

    return precd;
}