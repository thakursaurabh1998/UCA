#include <stdio.h>
#include <stdlib.h>

int (*funptr)(int *, int *);

int intCmp(int *x, int *y)
{
    printf("%d %d\n",*x,*y);
    return *(x) < *(y);
}

void merge(void *arr[], void *aux[], int l, int mid, int r, int (*cmp)(void *, void *))
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    // arr = (int *)arr;
    // aux = (int *)aux;
    while (i <= mid && j <= r)
        if (intCmp((arr + i), (arr + j)))
            *(aux + k++) = *(arr + i++);
        else
            *(aux + k++) = *(arr + j++);
    while (j <= r)
        *(aux + k++) = *(arr + j++);
    while (i <= mid)
        *(aux + k++) = *(arr + i++);
    for (i = 0; i < k; i++)
        *(arr + l + i ) = *(aux + i);
}

void mergeSort(void *arr[], void *aux[], int l, int r, int (*cmp)(void *, void *))
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, aux, l, mid, cmp);
    mergeSort(arr, aux, mid + 1, r, cmp);
    merge(arr, aux, l, mid, r, cmp);
}

int main()
{
    int n = 10;
    int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    int *aux = (int *)malloc(sizeof(int) * n);
    funptr = intCmp;
    mergeSort(arr, aux, 0, 9, funptr);
    // int arr[] = {5,7,2,6,1};
    // mergeSort(arr,0,4);
    int i;
    printf("\n");
    free(aux);
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}
