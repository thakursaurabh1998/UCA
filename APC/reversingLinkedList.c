#include <stdio.h>
#include "ll.h"

node *reverse(node *h)
{
    node *curr = h;
    node *prev = NULL;
    node *nextNode = h->next;

    while (curr->next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        nextNode = curr->next;
    }
    curr->next = prev;
    h = curr;
    return h;
}

node *reverseR(node *first, node *second)
{
    if (second->next == NULL)
    {
        second->next = first;
        return second;
    }
    node *temp = reverseR(second, second->next);
    second->next = first;
    return temp;
}

int main(void)
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

    listPrint(h);

    h = reverseR(NULL, h);
    listPrint(h);

    return 0;
}