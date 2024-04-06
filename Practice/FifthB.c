#include <stdio.h>

void towers(int num, char a, char b, char c);
int main()
{
    int num;
    printf("\nEnter the number of disks");
    scanf("%d", &num);

    printf("\nDisk activity starts from here only");
    towers(num, 'A', 'C', 'B');
    printf("\n");
    return 0;
}

void towers(int num, char from, char top, char aux)
{
    if (num == 1)
    {
        printf("\nThe disk 1 has changed  %c to %c  ", from, top);
        return;
    }

    towers(num - 1, from, aux, top);
    printf("\nThe disk %d has changed  %c to %c  ", num, from, top);
    towers(num - 1, aux, top, from);
}