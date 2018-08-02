#include <stdio.h>

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
            left = middle+1;
    }
    return left;
}

int upperBound(int *arr, int n, int num)
{
    int left = 0;
    int right = n;
    int middle;
    while(left < right)
    {
        middle = (left+right)/2;
        if(num>=arr[middle])
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

int main()
{
    int arr[] = {1,1,2,2,2,3,3,3,5,5,5,6,6,6};
    printf("%d",upperBound(arr,14,6));
}