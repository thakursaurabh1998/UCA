#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void recursiveInorder(node *root)
{
    if (root == NULL)
        return;
    recursiveInorder(root->left);
    printf("%d ", root->data);
    recursiveInorder(root->right);
}

node *find(node *root, int x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
        return root;
    else if (root->data > x)
        find(root->left, x);
    else if (root->data < x)
        find(root->right, x);
}

node **next(node **root, int x)
{
    if (*root == NULL)
        return root;
    if ((*root)->data > x)
        next(&((*root)->left), x);
    else if ((*root)->data < x)
        next(&((*root)->right), x);
}

node *findNextBiggest(node *tofind)
{
    tofind = tofind->right;
    while (tofind->left)
        tofind = tofind->left;
    return tofind;
}

void insert(node **root, int x)
{
    if (*root == NULL)
    {
        *root = (node *)malloc(sizeof(node));
        (*root)->data = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        node **parent = next(root, x);
        *parent = createNode(x);
    }
}

node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;
    if (root->data < key)
        root->right = deleteNode(root->right, key);
    else if (root->data > key)
        root->left = deleteNode(root->left, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = findNextBiggest(root);
        root->data = temp->data;
        deleteNode(root->right, root->data);
    }
    return root;
}

void rangeSearch(node *root, int x, int y);

int main()
{
    node *head = NULL;
    insert(&head, 2);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 1);
    recursiveInorder(head);
    printf("\n");
    deleteNode(head, 2);
    recursiveInorder(head);
    return 0;
}