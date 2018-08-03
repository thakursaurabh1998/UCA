#include <stdio.h>
#include "ll.h"


// iterative
node *evenSwap(node *h)
{
    node *curr = h;
    node *nex = h->next;
    node *prev = NULL;
    h = h->next;

    while (curr && curr->next )
    {
        if(prev!=NULL)
            prev->next = nex;
        curr->next = nex->next;
        nex->next = curr;
        prev = curr;
        curr = curr->next;
        if(curr!=NULL)
            nex = curr->next;
    }

    return h;
}

// recursive
node* evenSwapR(node *curr)
{
    if(curr==NULL || curr->next==NULL)
        return curr;
    node* temp = evenSwapR(curr->next->next);
    node* e = curr->next;
    curr->next->next = curr;
    curr->next = temp;
    return e;

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

    h = evenSwapR(h);
    listPrint(h);

    return 0;
}