#include <stdio.h>
#include <stdlib.h>

#define MAX(X, Y) (X > Y) ? X : Y

typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node *leftRotate(node *x)
{
    node *t = x->right;
    node *u = t->left;
    t->left = x;
    x->right = u;
}

node *rightRotate(node *x)
{
    node *t = x->left;
    node *u = t->right;
    t->right = x;
    x->left = u;
}

int height(node *root)
{
    if (root == NULL)
        return 0;
    return 1 + MAX(height(root->left), height(root->right));
}

int getBalance(node *root)
{
    return height(root->left) - height(root->right);
}

node *insert(node *root, int key)
{
    if (root == NULL)
        return createNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    root->height = MAX(height(root->left), height(root->right));
    int b = getBalance(root);
    if (b > 1)
    {
        if (getBalance(root->left) >= 0)
            return rightRotate(root);
        else
            root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (b < -1)
    {
        if (getBalance(root->right) >= 0)
            return leftRotate(root);
        else
            root->left = rightRotate(root->left);
        return rightRotate(root);
    }
}

void recursiveInorder(node *root)
{
    if (root == NULL)
        return;
    recursiveInorder(root->left);
    printf("%d ", root->data);
    recursiveInorder(root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    recursiveInorder(root);
    // root->left = createNode(3);
}