#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char USN[10], Name[20], Programme[30];
    int ph_no, sem;
    struct node *link;
};

typedef struct node *NODEPTR;

NODEPTR fnGetNode();
NODEPTR fnFreeNode(NODEPTR);
NODEPTR fnInsFront(NODEPTR);
NODEPTR fnDelFront(NODEPTR);
NODEPTR fnInsRear(NODEPTR);
NODEPTR fnDelRear(NODEPTR);
void fnDisplay(NODEPTR);

int main()
{

    NODEPTR first = NULL;
    int choice, students;

    printf("\nEnter the number of student.. : ");
    scanf("%d", &students);

    for (int i = 0; i < students; i++)
    {

        printf("\nEnter the data for %d", i + 1);
        first = fnInsFront(first);
    }

    for (;;)
    {

        printf("\nEnter you choices \n");
        printf("\n 1.InsFront \n2.DelFront \n3.InsRear \n4.DelRear \n5.Display \n6.Exit");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            first = fnInsFront(first);
            break;

        case 2:
            first = fnDelFront(first);
            break;
        case 3:
            first = fnInsRear(first);
            break;

        case 4:
            first = fnDelRear(first);
            break;

        case 5:
            fnDisplay(first);
            break;

        case 6:
            exit(0);

        default:
            printf("\nHello uncale kaam ki batein pe aatein hai ");
        }
    }
}

NODEPTR fnGetNode()
{

    NODEPTR newborn;
    newborn = (NODEPTR)malloc(sizeof(struct node));

    if (newborn == NULL)
    {
        printf("\n memory allocation failed");
    }

    printf("\nEnter the name : ");
    scanf("%s", newborn->Name);

    printf("\nEnter the USN : ");
    scanf("%s", newborn->USN);

    printf("\nEnter the Programme : ");
    scanf("%s", newborn->Programme);

    printf("\nEnter the Phone number :");
    scanf("%d", &newborn->ph_no);

    printf("\nEnter the Sem : ");
    scanf("%d", &newborn->sem);

    return newborn;
}

NODEPTR fnFreeNode(NODEPTR x)
{
    free(x);
}

NODEPTR fnInsFront(NODEPTR first)
{

    NODEPTR cur, temp;

    temp = fnGetNode();
    temp->link = NULL;
    temp->link = first;
    first = temp;
}

NODEPTR fnDelFront(NODEPTR first)
{

    NODEPTR temp, cur;

    if (first == NULL)
    {
        printf("\nSLL is empty deletion cannot complete ");
        return first;
    }

    temp = first;
    first = first->link;

    printf("\nThe deleted node is %s ", temp->Name);
    fnFreeNode(temp);
    return first;
}

NODEPTR fnInsRear(NODEPTR first)
{
    NODEPTR temp, cur;

    if (first == NULL)
    {
        return temp;
    }
    temp = fnGetNode();
    temp->link = NULL;

    cur = first;

    while (cur->link != NULL)
    {

        cur = cur->link;
    }

    cur->link = temp;
    return first;
}

NODEPTR fnDelRear(NODEPTR first)
{

    NODEPTR cur, prev;

    if (first == NULL)
    {
        printf("\nSLL is empty so it not going to delete anything ");
        return first;
    }

    cur = first;

    while (cur->link != NULL)
    {
        cur = prev;
        cur = cur->link;
    }

    printf("\nThe node has deleted %s", prev->Name);
    fnFreeNode(prev);

    return first;
}

void fnDisplay(NODEPTR first)
{

    NODEPTR curr;
    int count = 0;

    if (first == NULL)
    {
        printf("\nThe SLL is empty try again");
        return;
    }

    curr = first;

    printf("\nThe SLL contents are here.. ");

    printf("\nUSN\tName\tProgram  \tSem\tPhone num");

    printf("\nUSN\tName\tProgram\tSem\tPhone num");
    // while (curr != NULL)
    // {
    //     printf("\n%s\t%s\t%s\t%d\t%d", curr->USN, curr->Name, curr->Programme, curr->sem, curr->ph_no);
    //     curr = curr->link;
    //     count++;
    // }

    while (curr != NULL)
    {

        printf("\n %s \t%s \t%s  \t%d \t%d", curr->USN, curr->Name, curr->Programme, curr->sem, curr->ph_no);
        curr = curr->link;
        count++;
    }

    printf("\nTotal nodes are %d", count);
}
