int check(int *arr, int n, int m, int maxpages)
{
    int count=0, sum=0, i;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>maxpages)
        {
            count++;
            sum=arr[i];
        }
        if(arr[i]>maxpages)
            return 0;
        if(count==m && i!=n)
            return 0;
    }
    return 1;
}
 
int paint(int m, int T, int* arr, int n) {
    int sum=0,i;
    for(i=0;i<n;i++)
        sum+=arr[i];
    long long left=0, right=sum;
    long long mid;
    while(left<right)
    {
        mid = (left+right)/2;
        if(check(arr,n,m,mid))
            right=mid;
        else
            left=mid+1;
    }

    return (right*T)%10000003;
}