#include <stdio.h>
#include "ll.h"
#include <stdlib.h>

node *listnode_new(int val)
{
    node *nnode = (node *)malloc(sizeof(node));
    nnode->data = val;
    nnode->next = NULL;
    return nnode;
}

node *addBeg(node *h, int val)
{
    node *temp = listnode_new(val);
    temp->next = h;
    return temp;
}

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

node* removeZ(node* h)
{
    while(h->data==0)
    {
        h = h->next;
    }
    return h;
}

node *addNumbers(node *h1, node *h2)
{
    node *res = NULL;
    int data, carry = 0, flag;
    while (h1 || h2)
    {
        if (h1 && h2)
        {
            data = h1->data + h2->data + carry;
            h1 = h1->next;
            h2 = h2->next;
        }
        else if (h1)
        {
            data = h1->data + carry;
            h1 = h1->next;
        }
        else if (h2)
        {
            data = h2->data + carry;
            h2 = h2->next;
        }

        if (data >= 10)
        {
            data -= 10;
            flag = 1;
        }
        else
            flag = 0;
        res = addBeg(res, data);
        if (flag)
            carry = 1;
        else
            carry = 0;
    }
    if(carry)
    {
        res = addBeg(res, 1);
    }
    res = removeZ(res);
    res = reverse(res);

    return res;
}

int main(void)
{
    node *h1 = NULL;
    node *h2 = NULL;
    // addAtBeg(&h, 10);
    // addAtBeg(&h, 9);
    // addAtBeg(&h, 8);
    // addAtBeg(&h2, 1);
    addAtBeg(&h2, 0);
    addAtBeg(&h2, 0);
    addAtBeg(&h2, 7);
    addAtBeg(&h2, 9);
    addAtBeg(&h2, 6);
    addAtBeg(&h2, 9);
    addAtBeg(&h1, 9);
    addAtBeg(&h1, 3);
    addAtBeg(&h1, 4);
    addAtBeg(&h1, 2);

    listPrint(h1);
    listPrint(h2);

    listPrint(addNumbers(h1, h2));

    return 0;
}