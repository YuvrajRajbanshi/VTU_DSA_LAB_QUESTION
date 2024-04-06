#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct weeks
{
    char *day;
    int date;
    char *activity;
};
// typedef struct weeks Hello;

struct weeks *create()
{

    struct weeks *calendar = (struct weeks *)malloc(7 * sizeof(struct weeks));

    if (calendar == NULL)
    {
        printf("\nMemory allocation has failed");
        exit(1);
    }

    return calendar;
}

void read(struct weeks *calendar)
{
    char buffer[2000];

    for (int i = 0; i < 2; i++)
    {
        printf("\nEnter the day name.. ", i + 1);
        scanf("%s", buffer);

        calendar[i].day = (char *)malloc(strlen(buffer) + 1 * sizeof(char));

        if (calendar[i].day == NULL)
        {
            printf("\nMemory allocation has failed ");
            exit(1);
        }

        strcpy(calendar[i].day, buffer);

        printf("\nEnter the Date...", i + 1);
        scanf("%d", &calendar[i].date);

        printf("\nEntet the Activity... ", i + 1);
        scanf("%s", buffer);

        calendar[i].activity = (char *)malloc(strlen(buffer) + 1 * sizeof(char));

        if (calendar[i].activity == NULL)
        {
            printf("\nFailed memory alloction in activity");
            exit(1);
        }
        strcpy(calendar[i].activity, buffer);
    }
}

void display(struct weeks *calendar)
{
    printf("\nWeeks activity details report goes here \t\n");

    for (int i = 0; i < 2; i++)
    {
        printf("%s  %d  %s\n", calendar[i].day, calendar[i].date, calendar[i].activity);
    }
}
int main()
{

    struct weeks *calendar = create();

    read(calendar);
    display(calendar);
    free(calendar);
}
