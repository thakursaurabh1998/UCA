#include <stdio.h>
#include <assert.h>

int lowerBound(int *arr, int n, int num)
{
    int left = 0;
    int right = n;
    int middle;
    while (left < right)
    {
        middle = (left + right) / 2;
        if (num <= arr[middle])
            right = middle;
        else
            left = middle + 1;
    }
    return left;
}

int upperBound(int *arr, int n, int num)
{
    int left = 0;
    int right = n;
    int middle;
    while (left < right)
    {
        middle = (left + right) / 2;
        if (num >= arr[middle])
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

void test(int *arr)
{
    assert(lowerBound(arr, 14, 3) == 5);
    assert(lowerBound(arr, 14, 0) == 0);
    assert(lowerBound(arr, 14, 5) == 8);
    assert(lowerBound(arr, 14, 8) == 14);
    assert(upperBound(arr, 14, 3) == 8);
    assert(upperBound(arr, 14, 0) == 0);
    assert(upperBound(arr, 14, 5) == 11);
    assert(upperBound(arr, 14, 8) == 14);
    printf("Assertion Passed!");
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 3, 5, 5, 5, 6, 6, 6};
    test(arr);
    printf("%d\n",upperBound(arr,14,4));

    return 0;
}