#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{

    char Name[30], SSN[20], Dept[20], Design[30];
    int Salary, Ph_no;

    struct node *nlink;
    struct node *plink;
};

typedef struct node *NODEPTR;

NODEPTR fnGetNode();
int fnFree(NODEPTR);
NODEPTR fnInsFront(NODEPTR);
NODEPTR fnDelFront(NODEPTR);
NODEPTR fnInsRear(NODEPTR);
NODEPTR fnDelRear(NODEPTR);
void display(NODEPTR);
int main()
{

    NODEPTR first = NULL;
    printf("hello world");
}

NODEPTR fnGetNode()
{

    NODEPTR newborn;
    newborn = (NODEPTR)malloc(sizeof(struct node));

    if (newborn == NULL)
    {
        printf("\nMemory allocation has failed totally ");
        exit(1);
    }
    //    char Name[30], SSN[20], Dept[20], Design[30];
    //     int Salary, Ph_no;

    //     struct node *nlink;
    //     struct node *plink;
    printf("\nEnter the name : ");
    scanf("%[^\n]", newborn->Name);

    printf("\nEnter the SSN : ");
    scanf("%[^\n]", newborn->SSN);

    printf("\nEnter the Dept : ");
    scanf("%[^\n]", newborn->Dept);

    printf("\nEnter the Designation : ");
    scanf("%[^\n]", newborn->Design);

    printf("\nEnter the Salary :  ");
    scanf("%d", &newborn->Salary);

    printf("\nEnter the Phone number :  ");
    scanf("%d", &newborn->Ph_no);

    return newborn;
}

int fnFree(NODEPTR x)
{

    free(x);
}

NODEPTR fnInsFront(NODEPTR first)
{
    NODEPTR temp, cur;

    temp = fnGetNode();
    temp->nlink = temp->plink = NULL;

    temp->nlink = first;
    first = temp;
    return first;
}

NODEPTR fnDelFront(NODEPTR first)
{

    NODEPTR temp;

    if (first == NULL)
    {
        printf("\nThe DLL is empty is so we can delete anything ");
        return first;
    }

    if (first->nlink == NULL)
    {
        printf("\nThe nodes has deleted %s", first->Name);
        return NULL;
    }

    temp = first;
    first = first->nlink;
    first->plink = NULL;

    printf("\nThe node has deleted yar %s ", temp->Name);
}

NODEPTR fnInsRear(NODEPTR first)
{

    NODEPTR temp, cur;
    temp = fnGetNode();
    temp->nlink = temp->plink = 0;

    if (first == NULL)
    {
        return temp;
    }

    cur = first;

    while (cur->nlink != NULL)
    {
        cur = cur->nlink;
    }

    cur->nlink = temp;
    temp->plink = NULL;

    return 0;
}

NODEPTR fnDelRear(NODEPTR first)
{

    NODEPTR temp, prev, cur;

    if (first == NULL)
    {
        printf("\n The sll is emtpy");
    }

    cur = first;

    if (first->nlink == NULL)
    {
        printf("\nThe  node one has deleted %s", first->Name);
        return NULL;
    }

    while (cur->nlink != NULL)
    {

        cur = cur->nlink;
    }
    prev = cur->plink;

    prev->nlink = NULL;
    printf("\nNode deleted for %s\n", cur->Name);
    fnFreeNode(cur);
    return first;
}