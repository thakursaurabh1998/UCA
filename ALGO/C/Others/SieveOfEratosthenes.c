#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int n)
{
    int i;
    if (n == 1 || n == 0)
        return 0;
    for (i = 2; i <= pow(n, 0.5); i++)
        if (n % i == 0)
            return 0;
    return 1;
}

void sieveOfEratosthenes(int n)
{
    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    int i, j;
    for (i = 0; i <= n; i++)
    {
        if (arr[i] == 1)
            continue;
        if (prime(i))
        {
            arr[i] = 0;
            for (j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
        else
            arr[i] = 1;
    }
    for (i = 0; i <= n; i++)
        printf("%d : %d\n", i, arr[i]);
    free(arr);
    arr = NULL;
}

int main()
{
    int n;
    scanf("%d", &n);
    sieveOfEratosthenes(n);
    return 0;
}