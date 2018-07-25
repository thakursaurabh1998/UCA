#include <stdio.h>
#include <stdlib.h>

int *spiralOrder(const int **A, int m, int n, int *len1)
{
    int dir = 0;
    // A = (int**)malloc(sizeof(int*)*m);
    int p = m;
    int q = n;
    // int A[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *arr = (int *)malloc(sizeof(int) * m * n);
    int pmin = 0, qmin = 0, x = 0, y = 0;
    int i;
    for (i = 0; i < m * n; i++)
    {
        if (x >= m || y >= n)
        {
            printf("OOB");
            printf("\nx: %d y: %d", x, y);
        }
        else
        {
            printf("%d x:%d y:%d", A[x][y], x, y);
            arr[i] = A[x][y];
        }
        switch (dir)
        {
        case 0:
            y++;
            break;
        case 1:
            x++;
            break;
        case 2:
            y--;
            printf("\nq:%d qmin:%d p:%d pmin:%d", q, qmin, p, pmin);
            break;
        case 3:
            x--;
            break;
        }
        if (x == pmin && y == q)
        {
            dir = 1;
            pmin++;
            y--;
            x++;
        }
        else if (x == p && y == q - 1)
        {
            dir = 2;
            q--;
            y--;
            x--;
        }
        else if (x + 1 == p && y == qmin)
        {
            dir = 3;
            p = p - 1;
            x = x - 1;
        }
        else if (x == pmin && y == qmin && x != 0)
        {
            dir = 0;
            qmin++;
            x = qmin;
        }
        printf("\n dir %d\n", dir);
    }
    *len1 = m * n;
    return arr;
}

int main(int argc, char const *argv[])
{
    int *a;
    const int **arr;
    
    spiralOrder(arr, 3, 3, a);
    return 0;
}
