#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNewNode(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->right = NULL;
    temp->left = NULL;
    temp->data = data;
    return temp;
}

node* insert(node* x, int key)
{
    if(x==NULL)
        return createNewNode(key);
    if(x->data < key)
        x->right = insert(x->right, key);
    else if(x->data > key)
        x->left = insert(x->left, key);
    return x;
}

void inorder(node* root, int* arr, int *i)
{
    if(root == NULL)
        return;
    arr[*i] = root->data;
    (*i) += 1;
    inorder(root->left, arr, i);
    inorder(root->right, arr, i);
}

int check(int* arr, int* arr1, int n)
{
    int i;
    for(i=1;i<n;i++)
        if(arr[i] != arr1[i])
            return 0;
    return 1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int num;
        node* tree = NULL;
        int nn = n;
        int p=0;
        int* arr2 = (int*)malloc(sizeof(int)*nn);
        while(n--)
        {
            scanf("%d",&num);
            arr2[p++] = num;
            tree = insert(tree, num);
        }
        int i=0;
        int* arr = (int*)malloc(sizeof(int)*nn);
        inorder(tree, arr, &i);
        int t = check(arr, arr2, nn);
        // printf("t:%d ",t);
        if(t)
            printf("YES\n");
        else
            printf("NO\n");
            
    }
    return 0;
}