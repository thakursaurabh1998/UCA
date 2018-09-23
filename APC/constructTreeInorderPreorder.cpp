#include <iostream>
#include "BinaryTree.h"

int find(int num, int *ino, int left, int right)
{
    for (int i = left; i <= right; i++)
        if (ino[i] == num)
            return i;
    return -1;
}

void constructTree(int *pre, int *ino, int left, int right, Btree **root, int *index)
{
    // cout << left << " " << right << " " << *pre << endl;
    int mid = find(pre[*index], ino, left, right);
    // cout << "MID: " << mid << endl;
    // cout << left << " " << right << " " << mid << endl;
    if (mid == -1)
    {
        // cout << "PRE" << *pre << endl;
        *root = NULL;
        // return;
    }
    else
    {
        (*root)->data = pre[*index];
        (*root)->left = new Btree();
        (*root)->right = new Btree();
        *index += 1;
        // cout << "data: " << (*root)->data << endl;
        constructTree(pre, ino, left, mid - 1, &((*root)->left), index);
        // cout << "MIDA: " << mid << endl;
        constructTree(pre, ino, mid + 1, right, &((*root)->right), index);
    }
}

int main()
{
    int pre[] = {1, 2, 4, 3, 5, 7, 6};
    int ino[] = {2, 4, 1, 7, 5, 3, 6};

    Btree *root = new Btree();
    int index = 0;
    constructTree(pre, ino, 0, 6, &root, &index);
    recursiveInorder(root);
    cout << endl;
    recursivePreorder(root);
    cout << endl;
    recursivePostorder(root);
    // cout << endl << root->data << root->left->data << root->left->right->data;
    // root = root->left;
    // cout << root->data << endl;
    // root = root->left;
    return 0;
}