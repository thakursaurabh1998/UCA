#include <stdio.h>
#include "ll.h"

node *rotateRight(node *head, int n)
{
    int count = 0;
    node *h = head;
    if(n==0)
        return head;
    while (h)
    {
        count++;
        h = h->next;
    }
    n = n%count;
    if(n==0)
        return head;
    h = head;
    n = count - n - 1;
    while (n--)
    {
        h = h->next;
    }
    node *temp = h;
    while (h->next)
        h = h->next;
    // printf("%d %d\n", temp->data, h->data);
    node* temp1 = temp->next;
    temp->next = NULL;
    h->next = head;
    // node *temp = h->next;
    // h->next = NULL;
    // temp->next = head;

    return temp1;
}

int main(void)
{
    node *h = NULL;
    addAtBeg(&h, 6);
    addAtBeg(&h, 5);
    addAtBeg(&h, 4);
    addAtBeg(&h, 3);
    addAtBeg(&h, 2);
    addAtBeg(&h, 1);

    listPrint(h);

    h = rotateRight(h, 6);
    listPrint(h);

    return 0;
}