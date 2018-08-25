#include <stdio.h>
#include <stdlib.h>

void swapF(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int comparator(int *i, int *j)
{
    return *i > *j;
}

void quickSort(void *arr, int l, int r, int (*cmp)(void *, void *), void (*swap)(void *, int, int), size_t size)
{
    if (l == r)
        return;
    int i, j;
    int random = (rand() % (r - l)) + l;
    swap(arr, l, random);
    arr = (char *)arr;
    int pivot = l;
    int val = l;
    for (i = l; i < r; i++)
        if (cmp(arr + l * size, arr + i * size))
            swap(arr, i, ++pivot);

    swap(arr, l, pivot);
    quickSort(arr, l, pivot, cmp, swap, size);
    quickSort(arr, pivot + 1, r, cmp, swap, size);
}

int main()
{
    int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    // char arr[] = {'v','d','h','c','a','w','q','x','m','l'};
    // quickSort(arr, 0, 10, comparator, swapF, sizeof(char));
    quickSort(arr, 0, 10, comparator, swapF, sizeof(int));
    int i;
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}