#include <stdio.h>
#include "StackArray.h"

#define MIN(X, Y) ((X < Y) ? X : Y)

// Array style
int trapWaterArr(int *A, int n)
{
    int forward[n];
    int backward[n];
    int max = 0;
    int maxr = n - 1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] >= A[max])
        {
            forward[i] = i;
            max = i;
        }
        else
        {
            forward[i] = max;
        }
        if (A[n - i - 1] >= A[maxr])
        {
            backward[n - i - 1] = n - i - 1;
            maxr = n - i - 1;
        }
        else
        {
            backward[n - i - 1] = maxr;
        }
    }

    int sum = 0;

    for (i = 0; i < n; i++)
    {
        if (i == forward[i] || i == backward[i])
            continue;
        sum += MIN(A[forward[i]], A[backward[i]]) - A[i];
    }

    // for (i = 0; i < n; i++)
    //     printf("%d\t%d\t%d\n", forward[i], backward[i], A[i]);

    return sum;
}

int main()
{
    // int arr[] = {1, 0, 3, 0, 1, 3, 2, 1, 3, 0, 3};
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = 12;

    // printf("%d", waterTrapped(arr, 12));
    printf("%d", trapWaterArr(arr, n));

    return 0;
}