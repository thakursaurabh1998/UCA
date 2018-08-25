#include <stdio.h>
#include <stdlib.h>

static int aux[10];

int intCmp(int *x, int *y)
{
    printf("%d %d\n", *x, *y);
    return *(x) < *(y);
}

void merge(int *arr, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
        if (intCmp(arr+i,arr+j))
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    while (j <= r)
        aux[k++] = arr[j++];
    while (i <= mid)
        aux[k++] = arr[i++];
    for (i = 0; i < k; i++)
        arr[l + i] = aux[i];
}

void mergeSort(int *arr, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    // int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    // mergeSort(arr, 0, 9);
    int arr[] = {5,2,1,4,3};
    mergeSort(arr,0,4);
    int i;
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}
