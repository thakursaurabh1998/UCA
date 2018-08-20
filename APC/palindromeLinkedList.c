#include <stdio.h>
#include <stdlib.h>
#include "ll.h"

// node *deleteDuplicate(node *h)
// {
//     node *temp = h;
//     while (h && h->next)
//     {
//         if (h->data == h->next->data)
//         {
//             h->next = h->next->next;
//         }
//         else
//             h = h->next;
//     }

//     return temp;
// }

// node *removeDuplicate(node *h)
// {
//     node *temp = h;
//     node *start = NULL;
//     int val = h->data - 1;
//     int flag = 0;
//     while (h && h->next)
//     {
//         if(h->data != h->next->data)
//             start = h;
//         if(h->data == val)
//             continue;
//         if(h->data == h->next->data)
//         {
//             val = h->data;
//         }
//         // if (h->data == h->next->data)
//         // {
//         //     flag = 1;
//         //     val = h->data;
//         // }
//         // if(flag && val==h->next->data)
//         // {
//         //     h->next = h->next->next;
//         // }
//         // else if(flag && val!=h->next->data)
//         // {
//         //     flag = 0;
//         // }

//         h = h->next;
//     }

//     return temp;
// }

static int flag = 0;

node *palindrome(node *h, node *r)
{
    if (h == NULL)
        return r;
    node *last = palindrome(h->next, r);
    if (last == NULL)
        return NULL;
    printf("last: %d front: %d\n", last->data, h->data);
    if (last->data == h->data)
        return last->next;
    else
    {
        flag = 1;
        return NULL;
    }
}

int check(node *h)
{
    palindrome(h, h);
    if (flag == 1)
        return 0;
    else
        return 1;
}

int main()
{
    node *h = NULL;
    addAtBeg(&h, 1);
    addAtBeg(&h, 0);
    addAtBeg(&h, 1);
    addAtBeg(&h, 4);
    addAtBeg(&h, 1);
    addAtBeg(&h, 3);
    addAtBeg(&h, 1);
    addAtBeg(&h, 0);
    addAtBeg(&h, 1);
    int ans = check(h);
    printf("%d\n", ans);
    listPrint(h);
    return 0;
}