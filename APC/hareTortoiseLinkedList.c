#include <stdio.h>
#include <stdlib.h>

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

void addAtLast(node **h, int d, node *middle)
{
    node *nn = createNode();
    nn->data = d;
    nn->next = middle;
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

void listPrint(node *h)
{
    node *curr = h;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    node *h = NULL;
    addAtBeg(&h, 10);
    addAtBeg(&h, 9);
    addAtBeg(&h, 8);
    addAtBeg(&h, 7);
    addAtBeg(&h, 6);
    addAtBeg(&h, 5);
    addAtBeg(&h, 4);
    addAtBeg(&h, 3);
    addAtBeg(&h, 2);
    addAtBeg(&h, 1);
    node *slowPtr = h;
    node *fastPtr = h;
    while (fastPtr && fastPtr->next)
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }
    // listPrint(h);

    // printf("%d %d",slowPtr->data, fastPtr->data);

    addAtLast(&h, 11, slowPtr);
    fastPtr = h;
    slowPtr = h;
    do
    {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    } while(fastPtr!=slowPtr && fastPtr && fastPtr->next);

    printf("%d %d", slowPtr->data, fastPtr->data);
    // listPrint(h);

    return 0;
}
