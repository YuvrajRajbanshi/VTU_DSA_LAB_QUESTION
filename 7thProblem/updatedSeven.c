
/*Develop a menu driven Program in C for the following
operations on Singly Linked List
(SLL) of Student Data with the fields: USN, Name,
Programme, Sem,
PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes
in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL
(Demonstration of stack)
e. Exit*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char cUSN[11], cName[40], cProgram[4];
    int iSem, iPhNo;
    struct node *link;
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

    // first is the head of the link list which contain NULL value
    NODEPTR first = NULL;
    int iChoice, iNum, i;
    printf("\nEnter the number of Students N : ");
    scanf("%d", &iNum);
    for (i = 0; i < iNum; i++)
    {
        printf("\nEnter Data for Node %d :\n", i + 1);
        first = fnInsFront(first);
    }
    for (;;)
    {
        printf("\nQUEUE OPERATIONS\n");
        printf("====================");
        printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete  Rear\n5.Display\n6.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &iChoice);
        switch (iChoice)
        {
        case 1:
            first = fnInsFront(first);
            break;
        case 2:
            first = fnInsRear(first);
            break;
        case 3:
            first = fnDelFront(first);
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
        printf("nMemory Overflow");
        exit(0);
    }
    printf("\nEnter USN : ");
    scanf("%s", newborn->cUSN);
    printf("\nEnter name : ");
    scanf("%s", newborn->cName);
    printf("\nEnter Program name : ");
    scanf("%s", newborn->cProgram);
    printf("\nEnter semester : ");
    scanf("%d", &newborn->iSem);
    printf("\nEnter Phone no : ");
    scanf("%d", &newborn->iPhNo);
    return newborn;
}
void fnFreeNode(NODEPTR x)
{
    free(x);
}
// in this function we are passing first as head of the Linked list "cool yaar"

// insert mean end of the sll it will add one node
NODEPTR fnInsRear(NODEPTR first)
{
    NODEPTR temp, cur;
    temp = fnGetNode();
    temp->link = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp; // this line establish the relation between new node existing node
    return first;
    // finally this function i understand. (Dilasha de raha hoon yaar)
}

NODEPTR fnDelFront(NODEPTR first)
{
    NODEPTR temp;
    if (first == NULL)
    {
        printf("\nSLL is empty cannot delete\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("\nNode deleted is %s\n", temp->cName);
    fnFreeNode(temp);
    return first;
}
void fnDisplay(NODEPTR first)
{
    NODEPTR curr;
    int count = 0;
    if (first == NULL)
    {
        printf("\nSLL is empty\n");
        return;
    }
    printf("\nThe contents of SLL are :\n");
    curr = first;
    //	printf("n");
    printf("\nUSN\tName\tProgram\tSem\tPhone num");
    while (curr != NULL)
    {
        printf("\n%s\t%s\t%s\t%d\t%d", curr->cUSN, curr->cName, curr->cProgram, curr->iSem, curr->iPhNo);
        curr = curr->link;
        count++;
    }
    printf("\n\nSLL has %d nodes\n", count);
}
NODEPTR fnInsFront(NODEPTR first)
{
    NODEPTR temp;
    temp = fnGetNode();
    temp->link = NULL;
    temp->link = first;
    first = temp;
    return first;
}
NODEPTR fnDelRear(NODEPTR first)
{
    NODEPTR cur, prev;
    if (first == NULL)
    {
        printf("\nSLL is empty cannot delete\n");
        return first;
    }
    prev = NULL;
    cur = first;

    // ask to mam how this if condition  comes
    if (cur->link == NULL)
    {
        printf("\nNode deleted for %s\n", cur->cName);
        fnFreeNode(cur);
        return NULL;
    }
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }

    // here cur->link point to the null
    prev->link = cur->link;
    printf("\nNode deleted for %s\n", cur->cName);
    fnFreeNode(cur);
    return first;
}
