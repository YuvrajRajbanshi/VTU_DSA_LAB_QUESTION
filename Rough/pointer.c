#include <stdio.h>
int main()
{

    int x, y, a;
    int *c, *d;

    c = &x;
    y = *c;
    // y = &a;
    // printf("The address of the a is ...%d\n", &a);
    printf("The address of the a is ...%d\n", c);
    printf("The address of the a is ...%d\n", &x);
    printf("the value of c is .... %d\n", y);
}