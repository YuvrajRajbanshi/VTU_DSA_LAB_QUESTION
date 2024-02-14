#include <stdio.h>
#define MAX 4
int fnPush(int stk[], int pushElem, int *top);
int fnPop(int stk[], int *top);

int main()
{
    int top = -1;
    int pushElem;
    int stkArray[MAX];

    printf("Enter the element for push onto the stack \n");
    scanf("%d", &pushElem);
    // here I can call both of the function okay
    printf("Hello my dear frind this is yuvraj who is learing DSA\n");
    fnPush(stkArray[MAX], pushElem, &top);
    fnPop(stkArray[MAX], top);
}

int fnPush(int stk[], int pushElem, int *top)
{

    *top = *top + 1;
    stk[*top] = pushElem;
}

int fnPop(int stk[], int *top)
{
    int popedElm;
    popedElm = stk[*top];
    *top = *top - 1;
    printf("the poped element is %d\n", popedElm);
    // stk[*top]
}