#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int info;
    struct node *lbranch;
    struct node *rbranch;
};

typedef struct node *NODEPTR;

NODEPTR fnGetNode();
void fnGetFree(NODEPTR x);
NODEPTR fnGetInsNode(NODEPTR first, int item);

void fnInsOrder(NODEPTR);
void fnPreOrder(NODEPTR);
void fnPostOrder(NODEPTR);

int fnBST(NODEPTR root, int item);

int main()
{
    NODEPTR root = NULL;
    int choice;
    int number, item;
    printf("\nEnter the number of nodes ..");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++)
    {
        printf("\nEnter the each node ...");
        scanf("%d", &item);
        root = fnGetInsNode(root, item);
    }

    for (;;)
    {
        printf("\n1.Inorder traversal\n2.Preorder traversal");
        printf("\n3.Postorder traversal\n4.Search\n5.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                printf("\nTree is Emptyn");
            }
            else
            {
                printf("\nInorder Traversal is :\n");
                fnInOrder(root);
                printf("\n");
            }
            break;
        case 2:
            if (root == NULL)
            {
                printf("\nTree is Empty\n");
            }
            else
            {
                printf("\nPreorder Traversal is :\n");
                fnPreOrder(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
            {
                printf("nTree is Emptyn");
            }
            else
            {
                printf("\nPostorder Traversal is :\n");
                fnPostOrder(root);
                printf("\n");
            }
            break;
        case 4:
            printf("\nEnter the element to be searched : ");
            scanf("%d", &item);
            fnSearchBST(root, item);
            break;

        case 5:
            exit(0);
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}

NODEPTR fnGetNode()
{

    NODEPTR newborn;
    newborn = (NODEPTR)malloc(sizeof(struct node));
    if (newborn == NULL)
    {
        printf("\nMemory allocation has failed ");
        exit(0);
    }

    return newborn;
}
void fnGetFree(NODEPTR x)
{
    free(x);
}

NODEPTR fnGetInsNode(NODEPTR root, int item)
{

    NODEPTR cur, prev, temp;

    temp = fnGetNode();
    temp->lbranch = temp->rbranch = NULL;
    temp->info = item;
    if (root == NULL)
    {
        printf("\nThe Node is empty ");
        return root;
    }
    cur = root;
    prev = NULL;

    while (cur != NULL)
    {
        prev = cur;
        if (item == cur->info)
        {
            printf("\nDuplicates element are not allowed ");
            fnGetFree(cur);
            return root;
        }

        cur = (item < cur->info) ? cur->lbranch : cur->rbranch;
    }

    if (prev->info > item)
    {
        prev->rbranch = temp;
    }
    else
    {
        prev->lbranch = temp;
    }
}

void fnInsOrder(NODEPTR root)
{

    if (root != NULL)
    {

        fnInsOrder(root->lbranch);
        printf("\n %d", root->info);
        fnInsOrder(root->rbranch);
    }
}
void fnPreOrder(NODEPTR root)
{

    if (root != NULL)
    {
        printf("\n %d", root->info);
        fnPreOrder(root->lbranch);
        fnPreOrder(root->rbranch);
    }
}
void fnPostOrder(NODEPTR root)
{
    if (root != NULL)
    {
        fnPostOrder(root->lbranch);
        fnPostOrder(root->rbranch);
        printf("\n %d", root->info);
    }
}

int fnBST(NODEPTR root, int item)
{
    // NODEPTR cur;

    if (root == NULL)
    {
        printf("\nThe node is empty");
        return root;
    }

    // cur = root;

    if (root != NULL)
    {
        if (root->info > item)
        {
            fnBST(root->lbranch, item);
        }
        else if (root->info < item)
        {
            fnBST(root->rbranch, item);
        }
        else
        {
            printf("\n The element not here ");
        }
    }
    else
    {
        printf("\nThe elemtn is not here");
    }
}