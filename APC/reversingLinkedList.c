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

node *reverseByIndices(node *head, int i, int j)
{
    int index = 1;
    node *pi;
    node *pj;
    node *temp = head;

    while (index <= j)
    {
        if (index == i - 1)
            pi = temp;
        else if (index == j - 1)
            pj = temp;
        temp = temp->next;
        index++;
    }

    printf("%d %d\n", pi->next->data, pj->next->data);

    node *iN = pi->next;
    node *jN = pj->next->next;
    
    pi->next = pj->next;
    pi->next->next = iN->next;
    pj->next = iN;
    iN->next = jN;

    return head;
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

    // h = reverseR(NULL, h);
    h = reverseByIndices(h, 2, 3);
    listPrint(h);

    return 0;
}