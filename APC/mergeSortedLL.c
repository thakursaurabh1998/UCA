#include <stdio.h>
#include "ll.h"

node* mergeLists(node* head1, node* head2) {
    
    node* temp;
    
    if(head1->data > head2->data){
        temp = head1;
        head1 = head2;
        head2 = temp;
    }
    node* merged = head1;
    
    while(head1 || head2)
    {
        if(head1->next == NULL)
        {
            head1->next = head2;
            break;
        }
        if(head2==NULL)
            break;
        if(head2->data >= head1->data && head2->data < head1->next->data)
        {
            temp = head2;
            head2 = head2->next;
            temp->next = head1->next;
            head1->next = temp;
        }
        head1 = head1->next;
    }
    return merged;
}

int main(void)
{
    node *h1 = NULL;
    node *h2 = NULL;
    addAtBeg(&h1, 39);
    addAtBeg(&h1, 11);
    addAtBeg(&h1, 4);
    addAtBeg(&h2,24);
    addAtBeg(&h2, 15);
    addAtBeg(&h2, 9);
    addAtBeg(&h2, 9);
    addAtBeg(&h2, 5);

    listPrint(mergeLists(h2,h1));

    return 0;
}