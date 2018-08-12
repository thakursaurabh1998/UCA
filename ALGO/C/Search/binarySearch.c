#include <stdio.h>

// iterative
int binarySearch(int *arr, int n, int search)
{
    int left = 0;
    int right = n - 1;
    int middle;
    while (left < right)
    {
        middle = (left + right) / 2;
        if (arr[middle] == search)
            return 1;
        if (arr[middle] < search)
            left = middle + 1;
        else
            right = middle;
    }
    return 0;
}

// recursive
int binarySearchR(int *arr, int left, int right, int search)
{
    int middle = (right + left) / 2;
    if (search == arr[middle])
        return 1;
    if (left == right)
        return 0;
    if (arr[middle] < search)
        left = middle + 1;
    else
        right = middle;

    return binarySearchR(arr, left, right, search);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf("%d", binarySearchR(arr, 0, 7, 8));
    return 0;
}