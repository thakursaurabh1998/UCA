#include <stdio.h>
#include <stdlib.h>

selectionSort(int *arr, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

int main(int argc, char const *argv[])
{
    int i;
    int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    selectionSort(arr, 10);
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}
