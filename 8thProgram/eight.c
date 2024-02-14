// Develop a menu driven Program in C for the following operations on Doubly Linked List
// (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation,
// Sal, PhNo
// a. Create a DLL of N Employees Data by using end insertion.
// b. Display the status of DLL and count the number of nodes in it
// c. Perform Insertion and Deletion at End of DLL
// d. Perform Insertion and Deletion at Front of DLL
// e. Demonstrate how this DLL can be used as Double Ended Queue.
// f. Exit
// //program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int iSSN;
    char cName[30], cDept[4], cDesignation[30], cPhNo[11];
    int iSalary;
    struct node *plink;
    struct node *nlink;
};
typedef struct node *NODEPTR;
NODEPTR fnGetNode(void);
void fnFreeNode(NODEPTR);
NODEPTR fnInsRear(NODEPTR);
NODEPTR fnDelFront(NODEPTR);
NODEPTR fnInsFront(NODEPTR);
NODEPTR fnDelRear(NODEPTR);
void fnDisplay(NODEPTR);
int main()
{
    NODEPTR first = NULL;
    int iChoice, iNum, i;
    printf("\nEnter the number of Employees N : ");
    scanf("%d", &iNum);
    for (i = 0; i < iNum; i++)
    {
        printf("\nEnter Data for Node %d :\n", i + 1);
        first = fnInsRear(first);
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
    if (newborn == NULL)
    {
        printf("\nMemory Overflow");
        exit(0);
    }
    printf("\nEnter SSN : ");
    scanf("%d", &newborn->iSSN);
    printf("\nEnter name : ");
    scanf("%s", newborn->cName);
    printf("\nEnter Department : ");
    scanf("%s", newborn->cDept);
    printf("\nEnter Designation : ");
    scanf("%s", newborn->cDesignation);
    printf("\nEnter Salary : ");
    scanf("%d", &newborn->iSalary);
    printf("\nEnter Phone no : ");
    scanf("%s", newborn->cPhNo);
    return newborn;
}
void fnFreeNode(NODEPTR x)
{
    free(x);
}
NODEPTR fnInsRear(NODEPTR first)
{
    NODEPTR temp, cur;
    temp = fnGetNode();
    temp->plink = temp->nlink = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->nlink != NULL)
    {
        cur = cur->nlink;
    }
    cur->nlink = temp;
    temp->plink = cur;
    return first;
}
NODEPTR fnInsFront(NODEPTR first)
{
    NODEPTR temp;
    temp = fnGetNode();
    temp->plink = temp->nlink = NULL;
    temp->nlink = first;
    first = temp;
    return first;
}
NODEPTR fnDelRear(NODEPTR first)
{
    NODEPTR cur, prev;
    if (first == NULL)
    {
        printf("\nDLL is empty\n");
        return first;
    }
    cur = first;
    if (cur->nlink == NULL)
    {
        printf("\nNode deleted for %s\n", cur->cName);
        fnFreeNode(cur);
        return NULL;
    }
    while (cur->nlink != NULL)
    {
        cur = cur->nlink;
    }
    prev = cur->plink;
    prev->nlink = NULL;
    printf("\nNode deleted for %s\n", cur->cName);
    fnFreeNode(cur);
    return first;
}
NODEPTR fnDelFront(NODEPTR first)
{
    NODEPTR temp;
    if (first == NULL)
    {
        printf("\nDLL is empty\n");
        return first;
    }
    if (first->nlink == NULL)
    {
        printf("\nNode deleted for %s\n", first->cName);
        fnFreeNode(first);
        return NULL;
    }
    temp = first;
    first = first->nlink;
    first->plink = NULL;
    printf("\nNode deleted for %s\n", temp->cName);
    fnFreeNode(temp);
    return first;
}
void fnDisplay(NODEPTR first)
{
    NODEPTR curr;
    int count = 0;
    if (first == NULL)
    {
        printf("\nDLL is empty\n");
        return;
    }
    printf("\nThe contents of DLL are :\n");
    curr = first;
    //	printf("n");
    printf("\nSSN\tName\tDept\tDesignation\tSalary\t\tPhone No");
    while (curr != NULL)
    {
        printf("\n%-5d\t%s\t%s\t%s\t\t%-7d\t\t%-11s", curr->iSSN, curr->cName, curr->cDept, curr->cDesignation, curr->iSalary, curr->cPhNo);
        curr = curr->nlink;
        count++;
    }
    printf("\n\nDLL has %d nodes\n", count);
}
/*CPP*/
