#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    // SSN, Name, Dept, Designation,
    //     Sal, PhNo

    char name[30], ssn[10], dept[20], desing[30];
    int sal, ph_num;
    struct node *nlink;
    struct node *plink;
};

typedef struct node *NODEPTR;

NODEPTR fnGetNode();
void fnFreNode(NODEPTR);
NODEPTR fnInsFront(NODEPTR);
NODEPTR fnDelFront(NODEPTR);
NODEPTR fnInsRear(NODEPTR);
NODEPTR fnDelRear(NODEPTR);
// void fnDisplay(NODEPTR);

void fnDisplay(NODEPTR);
int main()
{

    NODEPTR first = NULL;
    int num, iChoice;
    printf("\nEnter the number of Employeee");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {

        printf("\n Enter the data for the %d", i + 1);
        first = fnInsFront(first);
    }

    for (;;)
    {
        printf("\nDLL OPERATIONS\n");
        printf("====================");
        printf("\n1.Insert Rear\n2.Delete Front\n3.Insert Front\n4.Delete Rear\n5.Display\n6.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &iChoice);
        switch (iChoice)
        {
        case 1:
            first = fnInsRear(first);
            break;
        case 2:
            first = fnDelFront(first);
            break;
        case 3:
            first = fnInsFront(first);
            break;
        case 4:
            first = fnDelRear(first);
            break;
        case 5:
            fnDisplay(first);
            break;
        case 6:
            exit(0);
        }
    }
    return 0;
}
NODEPTR fnGetNode()
{
    NODEPTR newborn;

    newborn = (NODEPTR)malloc(sizeof(struct node));

    printf("\nEnter the name : ");
    scanf("%s", newborn->name);
    printf("\nEnter the SSN : ");
    scanf("%s", newborn->ssn);
    printf("\nEnter the Department : ");
    scanf("%s", newborn->dept);
    printf("\nEnter the Designation : ");
    scanf("%s", newborn->desing);

    printf("\nEnter the Salary : ");
    scanf("%d", &newborn->sal);
    printf("\nEnter the phone number : ");
    scanf("%d", &newborn->ph_num);
}
void fnFreNode(NODEPTR x)

{

    free(x);
}

NODEPTR fnInsFront(NODEPTR first)
{

    NODEPTR temp, cur;
    temp = fnGetNode();
    cur = first;
    temp->plink = temp->nlink = NULL;

    temp->nlink = first;
    first = temp;
    return first;
}

NODEPTR fnDelFront(NODEPTR first)
{

    NODEPTR temp;

    if (first == NULL)
    {
        printf("\nThe  double ll is empty ");
        return first;
    }

    if (first->nlink == NULL)
    {
        printf("\nThe deleted element is %s ", first->name);
        fnFreNode(first);
        return NULL;
    }

    temp = first;
    first = first->nlink;
    first->plink = NULL;

    printf("\n The deleted element is %s ", temp->name);
    fnFreNode(temp);
    return first;
}

NODEPTR fnInsRear(NODEPTR first)
{

    NODEPTR temp, cur;

    temp = fnGetNode();

    temp->nlink = temp->plink = NULL;
    cur = first;

    while (cur != NULL)
    {
        cur = cur->nlink;
    }

    cur->nlink = temp;

    return first;
}

NODEPTR fnDelRear(NODEPTR first)
{
    NODEPTR temp, prev, cur;
    if (first == NULL)
    {

        printf("\nThe DLL is empty ");
        return first;
    }

    if (first->nlink == NULL)
    {
        printf("\n The deleted nodes %s ", first->name);
        return NULL;
    }

    cur = first;
    temp = first;
    prev = NULL;
    while (cur != NULL)
    {
        prev = cur;
        cur = cur->nlink;
    }
    cur->plink = NULL;
    prev->nlink = NULL;

    printf("\nThe deleted element is %s ", cur->name);

    return first;
}
void fnDisplay(NODEPTR first)
{

    NODEPTR curr;
    curr = first;
    printf("\nDLL contents goes here ");
    printf("\nSSN\tName\tDept\tDesignation\tSalary\t\tPhone No");
    while (curr != NULL)
    {

        printf("\n%-5d\t%s\t%s\t%s\t\t%-7d\t\t%-11s", curr->ssn, curr->name, curr->dept, curr->desing, curr->sal, curr->ph_num);
        curr = curr->nlink;
    }
}