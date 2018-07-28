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
    if (pos == 1)
        addAtBeg(h, d);
//     else
//     {
//         while (/* condition */)
//         {
//             /* code */
//         }
//     }
}

int main()
{
    node *h = NULL;
    addAtBeg(&h, 1);
    printf("%d", h->data);
    addAtBeg(&h, 2);
    printf("%d", h->data);
    return 0;
}
