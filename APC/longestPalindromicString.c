#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


// dynamic Solution
char *longestPalindromeSubstring(char *str)
{
    int n = strlen(str);
    short int **table = (short int **)malloc(sizeof(short int *) * n);
    int i, j, x, y, inc = 0;
    for (i = 0; i < n; i++)
        table[i] = (short int *)malloc(sizeof(short int) * n);
    for (i = 0; i < n; i++)
    {
        x = 0;
        y = inc;
        while (y < n)
        {
            if (str[x] == str[y])
            {
                if (x == y)
                    table[x][y] = 1;
                else if (table[x + 1][y - 1] == 1)
                    table[x][y] = 1;
                else if (table[x][y - 1] == 1 && y == x + 1)
                    table[x][y] = 1;
                else
                    table[x][y] = 0;
            }
            else
                table[x][y] = 0;
            x++;
            y++;
        }
        inc++;
    }
    for (i = 0; i < n; i++)
        printf("%c ", str[i]);

    printf("\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (j < i)
                printf("0 ");
            else
                printf("%d ", table[i][j]);
        printf("\n");
    }
    int p = 0, q = 0, max = 1;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (table[i][j] == 1)
            {
                // printf("%d ", table[i][j]);
                if (max < j - i + 1)
                {
                    max = j - i + 1;
                    p = i;
                    q = j;
                }
                if (table[i + 1][j] != 1)
                    j++;
                // break;
            }
        }
    }
    char *palindrome = (char *)malloc(sizeof(char) * (max + 1));
    j = 0;
    for (i = p; i <= q; i++)
        palindrome[j++] = str[i];
    palindrome[j] = '\0';
    printf("\nmax: %d p: %d q: %d %s ", max, p, q, palindrome);
    return palindrome;
}

int main()
{
    printf("\n%s\n", longestPalindromeSubstring("abbcccbbbcaaccbababcbcabca"));
    // printf("%d\n", longestPalindromeSubstring("1221"));

    return 0;
}