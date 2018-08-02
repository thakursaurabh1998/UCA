#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

int reverse(node **h, node *r)
{
    if (r == NULL)
        return 1;
    else
    {
        int y = reverse(h, r->next);
        if (y == 1)
        {
            if ((*h)->data == r->data)
            {
                (*h) = (*h)->next;
                return 1;
            }
            else return 0;
        }
    }
    reverse(h, r-next);
    printf("%d", (*h)->data);
}

int main()
{
    node *h = NULL;
    addAtBeg(&h, 1);
    addAtBeg(&h, 0);
    addAtBeg(&h, 1);
    addAtBeg(&h, 0);
    addAtBeg(&h, 7);
    // node *slowPtr = h;
    // node *fastPtr = h;
    // while (fastPtr && fastPtr->next)
    // {
    //     fastPtr = fastPtr->next->next;
    //     slowPtr = slowPtr->next;
    // }
    reverse(&h, h);
    return 0;
}