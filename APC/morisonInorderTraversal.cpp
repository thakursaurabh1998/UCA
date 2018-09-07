#include <stdio.h>
#include "BinaryTree.h"

void morisonInorder(Btree *root)
{
    Btree *curr = root;
    Btree *curr1 = root;
    while (curr1 && curr1->right)
    {
        if (curr->left)
        {
            curr1 = curr->left;
            while (curr1->right)
                curr1 = curr1->right;
            curr1->right = curr;
            curr1 = curr;
        }
        else
        {
            cout << curr->data << " ";
            curr1 = curr->right;
        }
        if (curr->right == curr1 && curr1 != NULL)
        {
            cout << curr1->data << " ";
            curr->right = NULL;
            curr = curr1->right;
        }
        else
            curr = curr->left;
    }
}

int main()
{
    Btree *bt = NULL;
    bt = putValue(bt, 1);
    bt = putValue(bt, 2);
    bt = putValue(bt, 3);
    bt = putValue(bt, 4);
    bt = putValue(bt, 5);
    bt = putValue(bt, 6);
    bt = putValue(bt, 7);
    recursiveInorder(bt);
    cout << endl;
    morisonInorder(bt);
    return 0;
}
