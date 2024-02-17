// 1.Develop a Program in C for the following:
// a) Declare a calendar as an array of 7 elements (A dynamically Created array) to represent
// 7 days of a week. Each Element of the array is a structure having three fields. The first
// field is the name of the Day (A dynamically allocated String), The second field is the
// date of the Day (A integer), the third field is the description of the activity for a
// particular day (A dynamically allocated String).
// b) Write functions create(), read() and display(); to create the calendar, to read the data
// from the keyboard and to print weeks activity details report on screen.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a day
struct day
{
    char *name;     // Name of the day
    int date;       // Date of the day
    char *activity; // Activity for the day
};

// Define a function to create a calendar as an array of 7 days
struct day *create()
{
    // Allocate memory for 7 days
    struct day *calendar = (struct day *)malloc(7 * sizeof(struct day));
    // Check if memory allocation is successful
    if (calendar == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Return the pointer to the calendar
    return calendar;
}

// Define a function to read the data from the keyboard
void read(struct day *calendar)
{
    // Declare a buffer to store the input
    char buffer[100];
    // Loop through the 7 days
    for (int i = 0; i < 7; i++)
    {
        // Prompt the user to enter the name of the day
        printf("Enter the name of day %d: ", i + 1);
        // Read the input and store it in the buffer
        scanf("%s", buffer);
        // Allocate memory for the name of the day
        calendar[i].name = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        // Check if memory allocation is successful
        if (calendar[i].name == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        // Copy the buffer to the name of the day
        strcpy(calendar[i].name, buffer);
        // Prompt the user to enter the date of the day
        printf("Enter the date of day %d: ", i + 1);
        // Read the input and store it in the date of the day
        scanf("%d", &calendar[i].date);
        // Prompt the user to enter the activity for the day
        printf("Enter the activity for day %d: ", i + 1);
        // Read the input and store it in the buffer
        scanf("%s", buffer);
        // Allocate memory for the activity for the day
        calendar[i].activity = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        // Check if memory allocation is successful
        if (calendar[i].activity == NULL)
        {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        // Copy the buffer to the activity for the day
        strcpy(calendar[i].activity, buffer);
    }
}

// Define a function to display the calendar
void display(struct day *calendar)
{
    // Print a header
    printf("Week's Activity Details Report\n");
    printf("------------------------------\n");
    // Loop through the 7 days
    for (int i = 0; i < 7; i++)
    {
        // Print the name, date, and activity for each day
        printf("%s, %d: %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}

// Define the main function
int main()
{
    // Create a calendar
    struct day *calendar = create();
    // Read the data from the keyboard
    read(calendar);
    // Display the calendar
    display(calendar);
    // Free the memory allocated for the calendar
    free(calendar);
    // Return 0 to indicate success
    return 0;
}