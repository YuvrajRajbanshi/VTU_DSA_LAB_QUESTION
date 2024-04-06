
}
void fnFreeNode(NODEPTR x)
{
    free(x);
}
NODEPTR fnInsertNode(int iItem, NODEPTR root)
{
    NODEPTR temp, prev, cur;
    temp = fnGetNode();
    temp->info = iItem;