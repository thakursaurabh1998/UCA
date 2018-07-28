#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

node *createNode()
{
    node *nn = (node *)malloc(sizeof(node));
    return nn;
}

void addAtBeg(node **h, char d)
{
    node *nn = createNode();
    nn->data = d;
    nn->next = *h;
    *h = nn;
}

char removeAtBeg(node **h)
{
    node *temp = *h;
    *h = temp->next;
    char number = temp->data;
    free(temp);
    return number;
}

char push(node **h, char d)
{
    addAtBeg(h, d);
    return d;
}

char pop(node **h)
{
    return removeAtBeg(h);
}

char peek(node **h)
{
    return (*h)->data;
}

int main()
{
    node *h = NULL;
    char brackets[] = {'[', ']', '(', ')', '<', '>', '{', '}'};
    char input[50];
    scanf("%s", input);
    int len = strlen(input);
    int i,j,flag=1;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 8; j += 2)
        {
            if (input[i] == brackets[j])
            {
                flag=0;
                break;
            }
            else if(input[i]==brackets[j+1])
            {
                flag=1;
                break;
            }
        }
        switch(flag){
            case 0:
                push(&h,brackets[j]);
                break;
            case 1:
                if(peek(&h)==brackets[j])
                    pop(&h);
                else
                    printf("Invalid\n");
                    return 0;
                break;
        }
    }

    printf("VALID\n");

    return 0;
}