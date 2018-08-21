#include <stdio.h>
#include "ll.h"
#include <stdbool.h>

node* partition(node *head, int n)
{
    node* h = head;
    if(head->next == NULL || head->data == n)
        return head;
    while (head->next!=NULL && head->next->data < n)
        head = head->next;
    if(head->next == NULL)
        return h;
    node* start = head;
    node* temp;
    while(head && head->next)
    {
        // printf("start: %d\n",start->data);
        // printf("%d\n",head->data);
        if(head->next->data < n)
        {
            temp = head->next;
            head->next = head->next->next;
            temp->next = start->next;
            start->next = temp;
            start = start->next;
        }
        else
            head = head->next;
    }
    temp = h;
    node* rvar = h;
    if(h->data == n)
    {
        temp = h;
        h = h->next;
        rvar = h;
        while(h->next->data < n)
        {
            h = h->next;
        }
        temp->next = h->next;
        h->next = temp;
    }

    return rvar;
}
int main(void)
{
    node *h = NULL;
    addAtBeg(&h, 4);
    addAtBeg(&h, 6);
    addAtBeg(&h, 7);
    addAtBeg(&h, 3);
    addAtBeg(&h, 2);
    addAtBeg(&h, 7);
    addAtBeg(&h, 4);
    addAtBeg(&h, 3);
    addAtBeg(&h, 2);
    addAtBeg(&h, 1);

    listPrint(h);

    // h = reverseR(NULL, h);
    h = partition(h, 5);
    listPrint(h);

    return 0;
}