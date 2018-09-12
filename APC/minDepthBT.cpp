#include <iostream>
#include "BinaryTree.h"

using namespace std;

#define MIN(X, Y) ((X < Y) ? X : Y)

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

int minDepth(Btree *root)
{
    if (root->left == NULL && root->right == NULL)
        return 1;
    int lside = INT_MAX;
    int rside = INT_MAX;
    if (root->left)
        lside = minDepth(root->left);
    if (root->right)
        rside = minDepth(root->right);

    return 1 + MIN(lside, rside);
}

int main()
{
    Btree *bt = new Btree();
    bt->data = 1;
    insertLeft(bt, 2);
    insertRight(bt, 3);
    insertLeft(bt->right, 4);
    insertRight(bt->right->left, 5);
    // insertLeft(bt, 2);
    // insertRight(bt, 3);
    // insertLeft(bt->left, 4);
    // insertRight(bt->left, 5);
    // insertLeft(bt->right, 7);
    // insertLeft(bt->left->left, 6);
    // insertRight(bt->left->left, 5);
    // insertRight(bt->right->left, 8);
    // insertRight(bt->right->left->right, 9);
    // insertLeft(bt->right->left->right->right, 10);
    // insertLeft(bt->right->left->right->right->left, 11);
    // insertLeft(bt->right->left->right->right->left->left, 12);
    // insertLeft(bt->right->left->right->right->left->left->left, 13);
    // insertLeft(bt->right->left->right->right->left->left->left->left, 14);
    // insertLeft(bt->right->left->right->right->left->left->left->left->left, 15);
    iterativeLevel(bt);

    int ans = minDepth(bt);

    cout << endl
         << ans << endl;

    return 0;
}