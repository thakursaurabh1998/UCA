#include <iostream>
#include "BinaryTree.h"

int find(int num, int *ino, int left, int right)
{
    for (int i = left; i <= right; i++)
        if (ino[i] == num)
            return i;
    return -1;
}

void constructTree(int *post, int *ino, int left, int right, Btree **root, int *index)
{
    // cout << left << " " << right << " " << *post << endl;
    int mid = find(post[*index], ino, left, right);
    // cout << "MID: " << mid << endl;
    // cout << left << " " << right << " " << mid << " " << post[*index] << endl;
    if (mid == -1)
    {
        // cout << "PRE " << post[*index] << endl;
        *root = NULL;
        // return;
    }
    else
    {
        (*root)->data = post[*index];
        (*root)->left = new Btree();
        (*root)->right = new Btree();
        *index -= 1;
        // cout << "data: " << (*root)->data << endl;
        constructTree(post, ino, mid + 1, right, &((*root)->right), index);
        constructTree(post, ino, left, mid - 1, &((*root)->left), index);
        // cout << "MIDA: " << mid << endl;
    }
}

int main()
{
    int pre[] = {1, 2, 4, 3, 5, 7, 6};
    int ino[] = {2, 4, 1, 7, 5, 3, 6};
    int post[] = {4, 2, 7, 5, 6, 3, 1};
    Btree *root = new Btree();
    int index = 6;
    constructTree(post, ino, 0, 6, &root, &index);
    recursivePreorder(root);
    cout << endl;
    recursiveInorder(root);
    cout << endl;
    recursivePostorder(root);
    return 0;
}