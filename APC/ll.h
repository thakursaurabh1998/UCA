#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *createNode()
{
    node *nn = (node *)malloc(sizeof(node));
    return nn;
}

void addAtBeg(node **h, int d)
{
    node *nn = createNode();
    nn->data = d;
    nn->next = *h;
    *h = nn;
}

int removeAtBeg(node **h)
{
    node *temp = *h;
    *h = temp->next;
    int number = temp->data;
    free(temp);
    return number;
}

void addAtLast(node **h, int d)
{
    node *nn = createNode();
    nn->data = d;
    nn->next = NULL;
    if (*h == NULL)
        *h = nn;
    else
    {
        node *curr = *h;
        while (curr->next)
            curr = curr->next;
        curr->next = nn;
    }
}

void removeAtLast(node **h)
{
    node *curr = *h;
    if (curr->next == NULL)
        curr = NULL;
    else
    {
        while (curr && curr->next && curr->next->next)
            curr = curr->next;
        free(curr->next);
        curr->next = NULL;
    }
}

void addAt(node **h, int d, int pos)
{
    if (pos <= 1)
        addAtBeg(h, d);
    else
    {
        node *curr = *h;
        int p = 1;
        while (curr && p++ < pos - 1)
            curr = curr->next;
        if (curr == NULL)
        {
            printf("Position doesn't exist\n");
            return;
        }
        node *nn = createNode();
        nn->next = curr->next;
        nn->data = d;
        curr->next = nn;
    }
}

int removeAt(node **h, int pos)
{
    int number;
    if (pos <= 1)
        number = removeAtBeg(h);
    else
    {
        node *curr = *h;
        int p = 1;
        while (curr && p++ < pos - 1)
            curr = curr->next;
        if (curr == NULL || curr->next == NULL)
        {
            printf("Position doesn't exist");
            return -1;
        }
        node *temp = curr->next;
        curr->next = temp->next;
        number = temp->data;
        temp->next = NULL;
        free(temp);
    }
    return number;
}

void listPrint(node *h)
{
    node *curr = h;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void test()
{
    node *h = NULL;
    addAtBeg(&h, 1);
    assert(h->data == 1);

    addAtLast(&h, 1);
}
