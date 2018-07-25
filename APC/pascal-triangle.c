#include <stdio.h>
#include <stdlib.h>

int **solve(int A, int *len1, int *len2)
{
    int i, j;
    len1 = (int*)malloc(sizeof(int));
    *len1 = A;
    len2 = (int *)malloc(sizeof(int) * A);
    int **arr = (int **)malloc(sizeof(int *) * A);
    for (i = 0; i < A; i++)
    {
        len2[i] = i + 1;
        arr[i] = (int *)malloc(sizeof(int) * len2[i]);
        for (j = 0; j < len2[i]; j++)
        {
            if (i == j || j == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    for (i = 0; i < A; i++)
    {
        for (j = 0; j < len2[i]; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return arr;
}

int main()
{
    int *a, *b;
    solve(5, a, b);

    return 0;
}