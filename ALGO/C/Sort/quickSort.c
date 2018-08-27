#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void quickSort(int *arr, int l, int r)
{
    if (l == r)
        return;
    int i, j, temp;
    int random = (rand() % (r - l)) + l;
    swap(arr, l, random);
    int pivot = l;
    int val = arr[l];
    // we will shift our pivot point virtually
    // without swapping the original values
    for (i = l; i < r; i++)
        if (val > arr[i])
            swap(arr, i, ++pivot);

    swap(arr, l, pivot);
    quickSort(arr, l, pivot);
    quickSort(arr, pivot + 1, r);
}

int main()
{
    int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    quickSort(arr, 0, 10);
    // int arr[] = {5, 7, 2, 6, 1};
    // quickSort(arr, 0, 5);
    int i;
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

void jk(int arr[])
{
    int i;
    int a[5] = {5, 65, 45, 2, 25};
    for (i = 1; i < 4; i++)
        a[i] = a[i - 1] – a[i] + a[i + 1];
}