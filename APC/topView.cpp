#include <iostream>
#include <queue>

using namespace std;

#define MAX(X, Y) ((X > Y) ? X : Y)

typedef struct Btree
{
    int data;
    int displacement;
    Btree *left;
    Btree *right;
} Btree;

void insertLeft(Btree *node, int data)
{
    node->left = new Btree();
    node->displacement = 0;
    node = node->left;
    node->data = data;
}

void insertRight(Btree *node, int data)
{
    node->right = new Btree();
    node->displacement = 0;
    node = node->right;
    node->data = data;
}

int height(Btree *root)
{
    if (root == NULL)
        return 0;
    return 1 + MAX(height(root->left), height(root->right));
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
        // cout << "data: " << node->data << " displacement: " << node->displacement << endl;
        cout << node->data << " ";
    }
}

void topView(Btree *root)
{
    queue<Btree *> q;
    q.push(root);
    int h = height(root);
    int *arr = new int[2 * h];
    int i, j;
    for (i = 0; i < 2 * h; i++)
        arr[i] = -1;
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        if (root->left)
        {
            root->left->displacement = root->displacement - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->displacement = root->displacement + 1;
            q.push(root->right);
        }
        if (arr[root->displacement + h] == -1)
            arr[root->displacement + h] = root->data;
    }

    for (i = 0; i < 2 * h; i++)
        if (arr[i] != -1)
            cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    Btree *bt = new Btree();
    bt->data = 1;
    insertLeft(bt, 2);
    insertRight(bt, 3);
    insertLeft(bt->left, 4);
    insertLeft(bt->right, 7);
    insertLeft(bt->left->left, 6);
    insertRight(bt->left->left, 5);
    insertRight(bt->right->left, 8);
    insertRight(bt->right->left->right, 9);
    insertLeft(bt->right->left->right->right, 10);
    insertLeft(bt->right->left->right->right->left, 11);
    insertLeft(bt->right->left->right->right->left->left, 12);
    insertLeft(bt->right->left->right->right->left->left->left, 13);
    insertLeft(bt->right->left->right->right->left->left->left->left, 14);
    insertLeft(bt->right->left->right->right->left->left->left->left->left, 15);

    topView(bt);
    iterativeLevel(bt);

    return 0;
}