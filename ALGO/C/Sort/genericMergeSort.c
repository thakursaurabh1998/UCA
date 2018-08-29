#include <stdio.h>
#include <stdlib.h>

int intCmp(int *x, int *y)
{
    return *(x) < *(y);
}

void merge(void *arr, void *aux, int l, int mid, int r, int (*cmp)(void *, void *), size_t size)
{
    int i = l;
    int j = mid + 1;
    int k = 0;
    int temp;
    arr = (char *)arr;
    while (i <= mid && j <= r)
    {
        temp = k * size;
        if (cmp(arr + i * size, arr + j * size))
            memcpy(aux + (k++) * size, arr + (i++) * size, size);
        else
            memcpy(aux + (k++) * size, arr + (j++) * size, size);
    }
    while (j <= r)
        memcpy(aux + (k++) * size, arr + (j++) * size, size);
    while (i <= mid)
        memcpy(aux + (k++) * size, arr + (i++) * size, size);
    for (i = 0; i < k; i++)
        memcpy(arr + (l + i) * size, aux + i * size, size);
}

void mergeSort(void *arr, void *aux, int l, int r, int (*cmp)(void *, void *), size_t size)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, aux, l, mid, cmp, size);
    mergeSort(arr, aux, mid + 1, r, cmp, size);
    merge(arr, aux, l, mid, r, cmp, size);
}

int main()
{
    int n = 10;
    int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    // int n = 5;
    // int arr[] = {5, 2, 1, 4, 3};
    int *aux = (int *)malloc(sizeof(int) * n);
    // mergeSort(arr, aux, 0, 4, intCmp, sizeof(int));
    mergeSort(arr, aux, 0, 9, intCmp, sizeof(int));
    int i;
    printf("\n");
    free(aux);
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}
