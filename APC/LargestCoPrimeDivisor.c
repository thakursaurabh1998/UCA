#include <stdio.h>

int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}

int largestCoprime(int a, int b)
{
    int x = a;
    int temp = gcd(x,b);
    while(temp!=1)
    {
        x/=temp;
        temp = gcd(x,b);
    }
    return x;
}

int main()
{
    printf("%d",largestCoprime(48,8));
    // printf("%d",gcd(48,8));
    return 0;
}