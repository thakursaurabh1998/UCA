#include <stdio.h>
static int count = 0;
int power(int n, int p)
{
    if (n == 0)
        return 0;
    if (p == 0)
        return 1;
    if (p == 1)
        return n;
    int i = power(n, p - p / 2);
    count++;
    return ((i * i) % 100000007);
}

int main()
{
    printf("%d", power(-1, 3));
    printf("\ncount: %d\n", count);
    return 0;
}