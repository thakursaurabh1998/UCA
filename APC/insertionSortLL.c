#include <stdio.h>
#include "ll.h"

node *shift(node *head, node *prev)
{
    node *curr = prev->next;
    node *h = head;
    if (head->data > prev->next->data)
    {
        prev->next = curr->next;
        curr->next = head;
        head = curr;
    }
    else
    {
        while (h->next->data < prev->next->data)
            h = h->next;
        prev->next = curr->next;
        curr->next = h->next;
        h->next = curr;
    }

    return head;
}

node *insertionSort(node *h)
{
    node *temp = h;
    node *prev = h;
    node *curr;
    while (prev->next)
    {
        curr = prev->next;
        if (prev->data > curr->data)
        {
            h = shift(h, prev);
        }
        else
            prev = prev->next;
    }

    return h;
}

int main(void)
{
    node *h = NULL;
    // addAtBeg(&h, 10);
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());
    addAtBeg(&h, rand());

    listPrint(h);

    h = insertionSort(h);
    listPrint(h);

    return 0;
}
