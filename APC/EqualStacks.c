#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX(X, Y, Z) ((X > Y) ? ((X > Z) ? 0 : 2) : ((Y > Z) ? 1 : 2))

int equalStacks(int n1, int *h1, int n2, int *h2, int n3, int *h3)
{
    int i;
    int sum[3] = {0};
    for (i = 0; i < n1; i++)
        sum[0] += h1[i];
    for (i = 0; i < n2; i++)
        sum[1] += h2[i];
    for (i = 0; i < n3; i++)
        sum[2] += h3[i];
    int p1, p2, p3;
    p1 = p2 = p3 = 0;
    while (!(sum[0] == sum[1]) || !(sum[1] == sum[2]))
    {
        int max = MAX(sum[0], sum[1], sum[2]);
        // printf("%d\n", max);
        if (max == 0)
            sum[0] -= h1[p1++];
        if (max == 1)
            sum[1] -= h2[p2++];
        if (max == 2)
            sum[2] -= h3[p3++];
        // for (i = 0; i < 3; i++)
        //     printf("%d\t", sum[i]);
        // printf("\n");
    }
    return sum[0];
}

int main()
{
    int n1 = 5, n2 = 3, n3 = 4;
    int arr1[5] = {3, 2, 1, 1, 1};
    int arr2[3] = {4, 3, 2};
    int arr3[4] = {1, 1, 4, 1};
    printf("%d", equalStacks(n1, arr1, n2, arr2, n3, arr3));
    return 0;
}
