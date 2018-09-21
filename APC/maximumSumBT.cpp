#include <iostream>
#include "BinaryTree.h"

#define MAX(X, Y) ((X > Y) ? X : Y)

void insertLeft(Btree *node, int data)
{
    node->left = new Btree();
    node = node->left;
    node->data = data;
}

void insertRight(Btree *node, int data)
{
    node->right = new Btree();
    node = node->right;
    node->data = data;
}

int maxSum(Btree *root)
{
    // cout << root->data << " ";
    if (root == NULL)
        return 0;

    int left, right;

    left = maxSum(root->left);
    right = maxSum(root->right);

    return root->data + MAX(left, right);
}

int main()
{
    Btree *bt = new Btree();
    bt->data = 1;
    insertLeft(bt, 2);
    insertRight(bt, 3);
    insertRight(bt->left, 4);
    insertLeft(bt->right, 5);
    insertLeft(bt->right->left, 7);
    insertRight(bt->right, 6);

    recursiveInorder(bt);

    cout << endl
         << maxSum(bt);

    return 0;
}