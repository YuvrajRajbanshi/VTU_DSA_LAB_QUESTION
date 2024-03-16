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

    printf("\nEnter the number of students: ");
    scanf("%d", &students);

    for (int i = 0; i < students; i++)
    {
        printf("\nEnter the data for student %d\n", i + 1);
        first = fnInsRear(first);
    }

    while (1)
    {
        printf("\nEnter your choice:\n");
        printf("1. Insert at Front\n2. Delete from Front\n3. Insert at Rear\n4. Delete from Rear\n5. Display\n6. Exit\n");
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
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

NODEPTR fnGetNode()
{
    NODEPTR newborn = (NODEPTR)malloc(sizeof(struct node));
    if (newborn == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }

    printf("Enter the name: ");
    scanf("%s", newborn->Name);

    printf("Enter the USN: ");
    scanf("%s", newborn->USN);

    printf("Enter the Programme: ");
    scanf("%s", newborn->Programme);

    printf("Enter the Phone number: ");
    scanf("%d", &newborn->ph_no);

    printf("Enter the Sem: ");
    scanf("%d", &newborn->sem);

    newborn->link = NULL;
    return newborn;
}

NODEPTR fnFreeNode(NODEPTR x)
{
    free(x);
    return NULL;
}

NODEPTR fnInsFront(NODEPTR first)
{
    NODEPTR temp = fnGetNode();
    temp->link = first;
    return temp;
}

NODEPTR fnDelFront(NODEPTR first)
{
    if (first == NULL)
    {
        printf("\nSLL is empty, deletion cannot be completed.\n");
        return first;
    }

    NODEPTR temp = first;
    first = first->link;

    printf("\nThe deleted node is %s\n", temp->Name);
    fnFreeNode(temp);
    return first;
}

NODEPTR fnInsRear(NODEPTR first)
{
    NODEPTR temp = fnGetNode();

    if (first == NULL)
        return temp;

    NODEPTR cur = first;
    while (cur->link != NULL)
        cur = cur->link;

    cur->link = temp;
    return first;
}

NODEPTR fnDelRear(NODEPTR first)
{
    if (first == NULL)
    {
        printf("\nSLL is empty, nothing to delete.\n");
        return first;
    }

    NODEPTR cur = first, prev = NULL;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    if (prev == NULL)
        first = NULL;
    else
        prev->link = NULL;

    printf("\nThe deleted node is %s\n", cur->Name);
    fnFreeNode(cur);
    return first;
}

void fnDisplay(NODEPTR first)
{
    if (first == NULL)
    {
        printf("\nThe SLL is empty.\n");
        return;
    }

    NODEPTR curr = first;
    printf("\nSLL contents:\n");
    printf("USN\tName\tProgram\tSem\tPhone num\n");

    while (curr != NULL)
    {
        printf("%s\t%s\t%s\t%d\t%d\n", curr->USN, curr->Name, curr->Programme, curr->sem, curr->ph_no);
        curr = curr->link;
    }
}
