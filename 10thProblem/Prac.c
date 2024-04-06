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
void fnFreeNode(NODEPTR);

NODEPTR fnInsNode(NODEPTR root, int item);

int fnInOrder(NODEPTR);
int fnPreOrder(NODEPTR);
int fnPostOrder(NODEPTR);
int fnSearchBST(int item, NODEPTR root);

int main()
{
    NODEPTR root = NULL;
    int item, choice, number;
    printf("\nCreate the BST number okay fine");
    printf("\nEnter total count number : ");
    scanf("%d", &number);
    printf("\nEnter all item number of BST : ");
    for (int i = 0; i < number; i++)
    {
        scanf("%d", &item);
        root = fnInsNode(root, item);
    }

    for (;;)
    {

        printf("\n1.Inorder \n2.Preorder \n3.Postorder \n4.Display \n5.Exit");

        printf("\nEnter your choices... :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (root == NULL)
            {
                printf("\n Inorder cannot possible my boi");
            }
            else
            {
                printf("\n\t The Inorder Process ");
                fnInOrder(root);
                printf("\n");
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
                fnSearchBST(item, root);
                break;

            case 5:
                exit(0);
            default:
                printf("Wrong choice\n");
                break;
            }
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
void fnFreeNode(NODEPTR x)
{

    free(x);
}

NODEPTR fnInsNode(NODEPTR root, int item)
{

    NODEPTR temp, prev, cur;

    temp = fnGetNode();

    temp->info = item;
    temp->lbranch = NULL;
    temp->rbranch = NULL;

    if (root == NULL)
    {
        return temp;
    }

    prev = NULL;
    cur = root;

    while (cur != NULL)
    {

        prev = cur;

        if (cur->info == item)
        {

            printf("\nDuplicate are not allowed");
            return root;
        }
        cur = (cur->info > item) ? cur->lbranch : cur->rbranch;
    }
    if (item < prev->info)
    {
        prev->lbranch = temp;
    }
    else
    {
        prev->rbranch = temp;
    }

    return root;
}

int fnInOrder(NODEPTR root)
{
    if (root != NULL)
    {
        fnInOrder(root->lbranch);
        printf("%d\t", root->info);
        fnInOrder(root->rbranch);
    }
}

int fnPreOrder(NODEPTR root)
{
    if (root != NULL)
    {

        printf("%d\t", root->info);
        fnPreOrder(root->lbranch);
        fnPreOrder(root->rbranch);
    }
}
int fnPostOrder(NODEPTR root)
{
    if (root != NULL)
    {
        fnPostOrder(root->lbranch);
        fnPostOrder(root->rbranch);
        printf("%d\t", root->info);
    }
}

int fnSearchBST(int item, NODEPTR root)
{

    if (root != NULL)
    {

        if (item < root->info)
        {
            fnSearchBST(item, root->lbranch);
        }
        else if (item > root->info)
        {
            fnSearchBST(item, root->rbranch);
        }
        else
        {
            printf("\n The element not here anymore my boi");
        }
    }

    else
    {
        printf("\nThe element is not here like your kurush");
    }
}