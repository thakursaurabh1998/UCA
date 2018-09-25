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

void findSum(Btree *root, int sum, int n, int* flag)
{
    if (root == NULL)
        return;
    if (n + root->data == sum && root->left == NULL && root->right == NULL)
        *flag = 1;
    findSum(root->left, sum, n + root->data, flag);
    findSum(root->right, sum, n + root->data, flag);
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
    cout << endl;

    int flag = 0;

    findSum(bt, 4, 0, &flag);
    cout << flag;

    return 0;
}