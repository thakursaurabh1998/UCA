#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createTable(char *s, int *tab)
{
    int n = strlen(s);
    int i, count, j;
    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (s[i] == s[j])
                count++;
            else
                break;
        }
        tab[i] = count;
        i = j - 1;
    }
}

char *countAndSay(int A)
{
    char *result = "1";
    int i, j;
    char *newres = result;
    for (j = 0; j < A-1; j++)
    {
        int n = strlen(result);
        int *table = (int *)calloc(n, sizeof(int));
        createTable(result, table);
        // for (i = 0; i < n; i++)
        //     printf("%c ", result[i]);
        // printf("\n table: ");
        // for (i = 0; i < n; i++)
        //     printf("%d ", table[i]);
        // printf("\n");
        newres = (char *)malloc(2 * n * sizeof(char));
        int p = 0;
        for (i = 0; i < n; i++)
        {
            if (table[i] != 0)
            {
                newres[p++] = '0' + table[i];
                newres[p++] = result[i];
            }
        }
        newres[p++] = '\0';
        result = newres;
        // printf("newres: %s\n",newres);
    }
    return result;
}

int main()
{
    printf("%s\n", countAndSay(25));
    return 0;
}