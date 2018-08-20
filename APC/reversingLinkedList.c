#include <stdio.h>
#include "ll.h"

// reversing linked list iterative solution
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

// reversing a linked list upto a given position K
node *reverseList(node *A, int K)
{
    node *curr = A;
    node *start = A;
    node *temp = A;
    K--;
    while (K--)
    {
        temp = start;
        start = curr->next;
        curr->next = curr->next->next;
        start->next = temp;
    }
    return start;
}

// reversing linked list from a given point to a given point
node *reverseListInRange(node *A, int J, int K)
{
    int counter = 1;
    node *h = A;
    while (J > 1 && counter != J - 1)
    {
        A = A->next;
        counter++;
    }
    node *ok = A;
    if (J != 1)
        A = A->next;
    // printf("%d\n",A->data);
    node *curr = A;
    node *start = A;
    node *temp = A;
    K = K - J;
    while (K--)
    {
        temp = start;
        start = curr->next;
        ok->next = start;
        curr->next = curr->next->next;
        start->next = temp;
    }
    if (J == 1)
        return start;
    return h;
}

// reversing a linked list recursive solution
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

node *swapByIndices(node *head, int i, int j)
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

    node *jN = pj->next;
    if (i == 1)
    {
        pi->next = head;
        head = jN;
    }
    node *iN = pi->next;
    if (pj == iN)
        pj = pi;

    pj->next = pj->next->next;
    pi->next = pi->next->next;
    iN->next = pj->next;
    pj->next = iN;
    jN->next = pi->next;
    pi->next = jN;

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
    h = reverseListInRange(h, 5, 10);
    listPrint(h);

    return 0;
}