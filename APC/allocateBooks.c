#include <stdio.h>

int check(int *arr, int n, int m, int maxpages)
{
    int count=0, sum=0, i;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>maxpages)
        {
            printf("sum: %d count: %d max: %d\n",sum, count, maxpages);
            count++;
            sum=arr[i];
        }
        if(arr[i]>maxpages)
            return 0;
        if(count==m && i!=n)
            return 0;
    }
    // if(count<m)
        return 1;
    // else return 0;
}

int allocateBooks(int *arr, int n, int m)
{
    int sum=0,i;
    for(i=0;i<n;i++)
        sum+=arr[i];
    int left=0, right=sum;
    int mid;
    while(left<right)
    {
        mid = (left+right)/2;
        if(check(arr,n,m,mid)==1)
            right=mid;
        else
            left=mid+1;
    }

    return right;
}

int main()
{
    int arr[] = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24};
    int m = 26;
    printf("%d",allocateBooks(arr,27,m));
    // int arr[] = {90,67,34,12};
    // int m=2;
    // printf("%d",allocateBooks(arr,4,m));

    return 0;
}

//answer 97