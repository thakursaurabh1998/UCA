#include <stdio.h>

int squareroot(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    int left = 0;
    int right = n;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if(mid*mid>n)
        {
            right = mid;
        }
        else
        {
            if(left==mid)
                break;
            left = mid;
        }
    }

    return left;
}

int main()
{
    // int n;
    // scanf("%d",&n);
    printf("%d", squareroot(4));
    return 0;
}