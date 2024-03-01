#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct day
{
    char *name;
    int date;
    char *activity;
};

typedef struct day weeks;

weeks *create()
{

    // weeks *calendar;
    weeks *calendar = (weeks *)malloc(7 * sizeof(struct day));
    if (calendar == NULL)
    {
        printf("\nMemory allocation has failed");
    }

    return calendar;
}

void read(weeks *calendar)
{
    char buffer[100];

    for (int i = 0; i < 7; i++)
    {
        printf("\nEnter the  name of the day.. %d", i + 1);
        scanf("%s", buffer);

        calendar[i].name = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

        if (calendar[i].name == NULL)
        {
            printf("\nMemory allocation failed");
        }

        strcpy(calendar[i].name, buffer);

        printf("\nEnter the date.. %d", i + 1);
        scanf("%d", &calendar[i].date);

        printf("Enter the activity of the day... %d", i + 1);
        scanf("%s", buffer);

        calendar[i].activity = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (calendar[i].activity == NULL)
        {
            printf("\nMemory allocation has failed");
        }

        strcpy(calendar[i].activity, buffer);
    }
}

void display(weeks *calendar)
{

    printf("\nEntire weeks activity is here only");

    for (int i = 0; i < 7; i++)
    {
        printf("\n\t\t%s \t %d \t%s", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

// main function goes here

int main()
{

    weeks *calendar = create();

    read(calendar);
    display(calendar);
    free(calendar);
    return 0;
}