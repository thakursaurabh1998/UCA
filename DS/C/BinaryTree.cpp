#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct Btree
{
    int data;
    Btree *left;
    Btree *right;
} Btree;

Btree *putValue(Btree *root, int data)
{
    Btree *nn = new Btree();
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    if (root == NULL)
        return nn;
    queue<Btree *> q;
    q.push(root);
    while (!q.empty())
    {
        Btree *node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        else
        {
            node->left = nn;
            return root;
        }
        if (node->right)
            q.push(node->right);
        else
        {
            node->right = nn;
            return root;
        }
    }
}

void recursiveInorder(Btree *root)
{
    if (root == NULL)
        return;
    recursiveInorder(root->left);
    cout << root->data << " ";
    recursiveInorder(root->right);
}

void recursivePreorder(Btree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    recursivePreorder(root->left);
    recursivePreorder(root->right);
}

void recursivePostorder(Btree *root)
{
    if (root == NULL)
        return;
    recursivePostorder(root->left);
    recursivePostorder(root->right);
    cout << root->data << " ";
}

void iterativeLevel(Btree *root)
{
    queue<Btree *> q;
    Btree *node;
    q.push(root);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        cout << node->data << " ";
    }
}

void iterativeInorder(Btree *root)
{
    stack<Btree *> stk;
    while (1)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
        if (stk.empty())
            return;
        Btree *node = stk.top();
        stk.pop();
        cout << node->data << " ";
        root = node->right;
    }
}

void iterativePreorder(Btree *root)
{
    stack<Btree *> stk;
    while (1)
    {
        while (root)
        {
            stk.push(root);
            cout << root->data << " ";
            root = root->left;
        }
        if (stk.empty())
            return;
        Btree *node = stk.top();
        stk.pop();
        root = node->right;
    }
}

// using single stack
void iterativePostorder(Btree *root)
{
    stack<Btree *> stk;
    int flag = 0;
    while (1)
    {
        if (flag == 0)
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
        if (stk.empty())
            return;
        Btree *node = stk.top();
        stk.pop();
        if (node->right)
        {
            stk.push(node);
            root = node->right;
            flag = 0;
        }
        else
        {
            cout << node->data << " ";
            flag = 1;
            while (!stk.empty() && stk.top()->right == node)
            {
                node = stk.top();
                stk.pop();
                cout << node->data << " ";
            }
        }
    }
}

// Using 2 stacks
void iterativePostorderAlt(Btree *root)
{
    stack<Btree *> stk1;
    stack<Btree *> stk2;
    stk1.push(root);
    while (!stk1.empty())
    {
        Btree *node = stk1.top();
        stk1.pop();
        stk2.push(node);
        if (node->left)
            stk1.push(node->left);
        if (node->right)
            stk1.push(node->right);
    }
    while (!stk2.empty())
    {
        cout << stk2.top()->data << " ";
        stk2.pop();
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

    iterativeLevel(bt);
    cout << " : Iterative Level" << endl;
    recursiveInorder(bt);
    cout << " : Recursive Inorder" << endl;
    iterativeInorder(bt);
    cout << " : Iterative Inorder" << endl;
    recursivePreorder(bt);
    cout << " : Recursive Preorder" << endl;
    iterativePreorder(bt);
    cout << " : Iterative Preorder" << endl;
    recursivePostorder(bt);
    cout << " : Recursive Postorder" << endl;
    iterativePostorder(bt);
    cout << " : Iterative Postorder" << endl;
    iterativePostorderAlt(bt);
    cout << " : Iterative Postorder 2 stacks" << endl;

    return 0;
}