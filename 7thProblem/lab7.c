// Develop a menu driven Program in C for the following operations on Singly Linked List
// (SLL)
// of Student Data with the fields : USN, Name, Programme, Sem, PhNo a.Create a SLL of N Students Data by using front insertion.b.Display the status of SLL and count the number of nodes in it c.Perform Insertion / Deletion at End of SLL d.Perform Insertion / Deletion at Front of SLL(Demonstration of stack) e.Exit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// human made data type is struct
struct node
{
    char cUSN[11], cName[40], cProgram[4];
    int iSem;
    char cPhNo[11];
    // connctes the next link
    struct node *link;
    // link will store the address new node node
};

// here *NODEPTR WILL  store the address head (first node of head suppose that 1000 )
// typed --> basically typedef used for alternation of struct ;
//  we can't write everytime ' struct node ' that's why we are using typedef
typedef struct node *NODEPTR;
NODEPTR fnGetNode(void);
// here why we are using NODEPTR ?
//  ********************explaination***********************
// -> as we know the definition of the structure, it says the structure is the user defined
// data types, so it's mean like (int , float , char etc);
// and we write the in every function return type, like int, void float;
// so same like them we are using NODEPTR Return type

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
    printf("\nEnter the number of Students  : ");
    scanf("%d", &iNum);
    for (i = 1; i <= iNum; i++)
    {
        printf("\nEnter Data for Node %d :\n", i);
        first = fnInsFront(first);
    }
    for (;;)
    {
        printf("\nQUEUE OPERATIONS\\n");
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
        printf("\nMemory Overflow");
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
    scanf("%d", newborn->cPhNo);
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
    // temp->link is created new node and initialize as NULL
    temp->link = NULL;

    // cur equal to head of the node

    // here checks the first == null checks the ll is empty or ot
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    return first;
}

NODEPTR fnDelFront(NODEPTR first)
{
    NODEPTR temp;
    if (first == NULL)
    {
        printf("\nSLL is empty cannot deleten");
        return first;
    }
    temp = first;
    first = first->link;
    printf("\nNode deleted is %sn", temp->cName);
    fnFreeNode(temp);
    return first;
}
void fnDisplay(NODEPTR first)
{
    NODEPTR curr;
    int count = 0;
    if (first == NULL)
    {
        printf("\nSLL is emptyn");
        return;
    }
    printf("\nThe contents of SLL are :\n");
    curr = first;
    //	printf("n");
    printf("\nUSNttNametProgramtSemtPhone num");
    while (curr != NULL)
    {
        printf("\n%10s\t%s\t%s\t%d\t%d", curr->cUSN, curr->cName, curr->cProgram, curr->iSem, curr->cPhNo);
        curr = curr->link;
        count++;
    }
    printf("\nnSLL has %d nodes\n", count);
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
    prev->link = cur->link;
    printf("\nNode deleted for %s\n", cur->cName);
    fnFreeNode(cur);
    return first;
}