#include <iostream>
#include "BinaryTree.h"

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

Btree* mirrorImage(Btree* root)
{
    if(root == NULL)
        return NULL;
    Btree* left = mirrorImage(root->left);
    Btree* right = mirrorImage(root->right);
    root->right = left;
    root->left = right;
    return root;
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
    recursivePreorder(bt);
    cout << endl;
    bt = mirrorImage(bt);
    recursiveInorder(bt);

    return 0;
}