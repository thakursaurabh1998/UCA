#include <stdio.h>
#include "BinaryTree.h"
Btree *findPredecessor(Btree *root)
{
    Btree *parent = root;
    root = root->left;
    if (!root)
        return NULL;
    while (root->right && root->right != parent)
        root = root->right;
    return root;
}

void morisonInorder(Btree *root)
{
    Btree *curr = root;
    Btree *predecessor = root;
    while (curr)
    {
        if (!(curr->left))
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            predecessor = findPredecessor(curr);
            if (!(predecessor->right))
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else if (predecessor->right == curr)
            {
                cout << curr->data << " ";
                curr = curr->right;
                predecessor->right = NULL;
            }
        }
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
