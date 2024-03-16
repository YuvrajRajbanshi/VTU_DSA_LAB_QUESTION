#include <stdio.h>

void towers(int, char, char, char);

int main()
{
    int num;
    printf("\nEnter the number of disks");
    scanf("%d", &num);
    towers(num, 'A', 'B', 'C');
    printf("\n");
    return 0;
}

void towers(int num, char from, char top, char aux)
{

    if (num == 1)
    {
        printf("The disk %d move from %s  to the top %s", num, from, top);
        return;
    }
    towers(num - 1, from, aux, top);

    printf("The disk %d move from %s to the top %s", num, from, top);

    towers(num - 1, aux, top, from);
}