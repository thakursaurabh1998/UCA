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

int push(node **h, int d)
{
    addAtBeg(h, d);
    return d;
}

int pop(node **h)
{
    return removeAtBeg(h);
}

int peek(node **h)
{
    return (*h)->data;
}

int removeAtBeg(node **h)
{
    node *temp = *h;
    *h = temp->next;
    int number = temp->data;
    free(temp);
    return number;
}

int main()
{
    node *h = NULL;
    push(&h, 1);
    printf("%d\n", h->data);
    push(&h, 2);
    printf("%d\n",peek(&h));
    printf("%d\n", h->data);
    pop(&h);
    printf("%d\n", h->data);
    // removeAtLast(&h);
    return 0;
}
