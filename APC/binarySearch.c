#include <stdio.h>


// iterative
int binarySearch(int* arr, int n, int search)
{
    int left = 0;
    int right = n-1;
    int middle;
    while(left<right)
    {
        middle = (left+right)/2;
        if(arr[middle]==search)
            return 1;
        if(arr[middle]<search)
            left = middle+1;
        else
            right = middle;
    }
    return 0;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    printf("%d",binarySearch(arr,8,10));
    return 0;
}