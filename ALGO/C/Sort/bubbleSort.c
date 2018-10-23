#include <stdio.h>

void bubbleSort(int *arr, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)                 // for (i = 0; i < n -1; i++)
        for (j = 0; j < n - 1; j++)         //     for(j = 0; j < n - i - 1; j++)
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main()
{
    int arr[] = {56, 23, 45, 54, 76, 98, 34, 54, 12, 1};
    bubbleSort(arr, 10);
    int i;
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}
