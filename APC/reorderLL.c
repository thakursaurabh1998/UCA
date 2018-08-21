#include <stdio.h>
#include "ll.h"

node *reorderList(node *head, node *tail)
{
    if (tail->next == NULL)
        return head;
    node *temp = reorderList(head, tail->next);
    if (temp == NULL || temp->next == NULL || temp->next->next == NULL)
        return NULL;
    printf("%d %d\n", tail->data, temp->data);
    tail->next->next = temp->next;
    temp->next = tail->next;
    tail->next = NULL;
    listPrint(head);
    if (temp->next)
        return temp->next->next;
    else
        return NULL;
}

int main(void)
{
    node *h = NULL;
    // addAtBeg(&h, 10);
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
    reorderList(h, h);
    listPrint(h);

    return 0;
}