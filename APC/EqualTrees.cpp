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

void inorder(Btree *t1, string *s1)
{
    if (t1 == NULL)
        return;
    inorder(t1->left, s1);
    char temp = '0' + t1->data;
    *s1 = *s1 + temp;
    inorder(t1->right, s1);
}

void preorder(Btree *t1, string *s1)
{
    if (t1 == NULL)
        return;
    char temp = '0' + t1->data;
    *s1 = *s1 + temp;
    preorder(t1->left, s1);
    preorder(t1->right, s1);
}

int equalTrees(Btree *t1, Btree *t2)
{
    string s1 = "";
    string s2 = "";
    inorder(t1, &s1);
    inorder(t2, &s2);
    // cout << s1 << " " << s2;
    if (s1 == s2)
    {
        s1 = "";
        s2 = "";
        // cout << s1 << " " << s2;
        preorder(t1, &s1);
        preorder(t2, &s2);
        if (s1 == s2)
            return 1;
    }
    return 0;
}

int main()
{
    Btree *bt1 = new Btree();
    bt1->data = 5;
    // insertLeft(bt1, 2);
    // insertRight(bt1, 3);
    // insertRight(bt1->left, 4);
    // insertLeft(bt1->right, 5);
    // insertLeft(bt1->right->left, 7);
    // insertRight(bt1->right, 6);

    Btree *bt2 = new Btree();
    bt2->data = 1;
    insertLeft(bt2, 10);
    // insertRight(bt2, 3);
    // insertRight(bt2->left, 4);
    // insertLeft(bt2->right, 5);
    // insertLeft(bt2->right->left, 7);
    // insertRight(bt2->right, 6);

    cout << equalTrees(bt1, bt2);
    

    return 0;
}