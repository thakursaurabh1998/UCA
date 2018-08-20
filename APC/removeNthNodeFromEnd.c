#include <stdio.h>
#include "ll.h"

static int counter = 0;
static int listcount = 0;


// recursive function to remove nth node from end
node *removeNthNode(node *h, int pos)
{
    if (h == NULL)
        return h;
    listcount++;
    node *temp = removeNthNode(h->next, pos);
    if (listcount < pos)
        return h->next;
    h->next = temp;
    if (pos == ++counter)
        return h->next;
    return h;
}

// iterative function to remove nth node from end
node *removeNthFromEnd(node *h, int pos)
{
    int counter = 0;
    node *temp = h;
    while (temp)
    {
        counter++;
        temp = temp->next;
    }
    if(pos >= counter)
        return h->next;
    temp = h;
    pos = counter - pos;
    int i = 1;
    while (i++ < pos)
    {
        temp = temp->next;
    }
    // printf("%d\n",temp->data);
    temp->next = temp->next->next;

    return h;
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
    // h = removeNthNode(h, 1);
    h = removeNthFromEnd(h, 11);
    listPrint(h);

    return 0;
}