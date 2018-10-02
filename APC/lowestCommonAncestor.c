typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

/* 
    Provide 2 nodes of whom you want to find Lowest Common Ancestor
    @root : root of the tree
    @v1 : node 1
    @v2 : node 2
 */

node *lca(struct node *root, int v1, int v2)
{
    if (v2 < v1)
    {
        int temp = v1;
        v1 = v2;
        v2 = temp;
    }
    while (!(root->data >= v1 && root->data <= v2))
    {
        if (root->data > v1)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}