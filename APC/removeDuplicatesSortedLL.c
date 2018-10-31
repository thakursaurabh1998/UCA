#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode(int d)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = d;
    temp->next = NULL;
    return temp;
}

node *add(node *root, int d)
{
    if (root == NULL)
        return createNode(d);
    root->next = add(root->next, d);
    return root;
}

void print(node *root)
{
    while (root)
    {
        printf("%d -> ", root->data);
        root = root->next;
    }
}

node *removeDuplicate(node *root)
{
    node *head = root;
    node *curr = root;
    node *prev = root;
    int flag = 0;
    if (root->next && root->data == root->next->data)
        flag = 1;
    while (curr)
    {
        if (curr->next && curr->data == curr->next->data)
        {
            node *temp = curr;
            while (curr && temp->data == curr->data)
                curr = curr->next;
            prev->next = curr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if (flag)
        head = head->next;
    return head;
}

int main()
{
    node *ll = NULL;
    ll = add(ll, 1);
    ll = add(ll, 1);
    ll = add(ll, 1);
    ll = add(ll, 2);
    ll = add(ll, 2);
    ll = add(ll, 3);
    ll = add(ll, 3);
    ll = add(ll, 3);
    ll = add(ll, 4);
    // ll = add(ll, 4);
    ll = add(ll, 5);
    ll = add(ll, 5);
    ll = add(ll, 5);
    print(ll);
    ll = removeDuplicate(ll);
    printf("\n");
    print(ll);

    return 0;
}