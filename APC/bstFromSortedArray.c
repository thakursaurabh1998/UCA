#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    return temp;
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

node *createBST(int *arr, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    node *temp = createNode(arr[mid]);
    temp->left = createBST(arr, l, mid - 1);
    temp->right = createBST(arr, mid + 1, r);

    return temp;
}

int main()
{
    // int arr[] = {1, 5, 6, 7, 9, 13, 17, 19, 45, 54, 78, 98};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[] = {1};
    int n = sizeof(arr) / sizeof(int);
    // printf("%d\n", n);
    node *temp = createBST(arr, 0, n - 1);
    printf("%d", temp->data);
    // inorder(temp);

    return 0;
}