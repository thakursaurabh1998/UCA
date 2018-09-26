#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;

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

node *next(node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->data > x)
        next(root->left, x);
    else if (root->data < x)
        next(root->right, x);
}

void insert(node *root, int x)
{
    node *parent = next(root, x);
    parent = (node *)malloc(sizeof(node));
    parent->data = x;
}

node *delete (node *root, int x);

void rangeSearch(node *root, int x, int y);

int main()
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 5;
    head->left = (node *)malloc(sizeof(node));
    head->right = (node *)malloc(sizeof(node));
    head->left->data = 4;
    head->right->data = 6;
    // printf("%d", find(head, 2)->data);
    // recursiveInorder(head);
    printf("%d %d %d", head->left->data, head->data, head->right->data);
    return 0;
}