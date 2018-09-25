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
    int mid = find(pre[*index], ino, left, right);
    if (mid == -1)
    {
        *root = NULL;
    }
    else
    {
        (*root)->data = pre[*index];
        (*root)->left = new Btree();
        (*root)->right = new Btree();
        *index += 1;
        constructTree(pre, ino, left, mid - 1, &((*root)->left), index);
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
    return 0;
}