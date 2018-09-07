#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *zValueArray(char *str, char *cmp)
{
    int x = strlen(str);
    int y = strlen(str);
    strcat(cmp, "$");
    printf("%s", cmp);
    // temp = strcat(temp, str);
    // int n = strlen(temp);
    // int* arr = (int*)malloc(sizeof(char)*n);
    int i, l, r;
    // printf("%d %d %d",x,y,n);
    // for(i=1;i<n;i++)
    // {
    //     if(i>r)
    //     {
    //         i = l = r;
    //         while(r<)
    //     }
    // }
    // return arr;
}
// void search(string text, string pattern)
// {
//     // Create concatenated string "P$T"
//     string concat = pattern + "$" + text;
//     int l = concat.length();

//     // Construct Z array
//     int Z[l];
//     getZarr(concat, Z);

//     // now looping through Z array for matching condition
//     for (int i = 0; i < l; ++i)
//     {
//         // if Z[i] (matched region) is equal to pattern
//         // length we got the pattern
//         if (Z[i] == pattern.length())
//             cout << "Pattern found at index "
//                  << i - pattern.length() - 1 << endl;
//     }
// }

// Fills Z array for given string str[]
void getZarr(char* str, int Z[])
{
    int n = strlen(str);
    int L, R, k;
    int i;
    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (i = 1; i < n; ++i)
    {
        // if i>R nothing matches so we will calculate.
        // Z[i] using naive way.
        if (i > R)
        {
            L = R = i;
 
            // R-L = 0 in starting, so it will start
            // checking from 0'th index. For example,
            // for "ababab" and i = 1, the value of R
            // remains 0 and Z[i] becomes 0. For string
            // "aaaaaa" and i = 1, Z[i] and R become 5
            while (R<n && str[R-L] == str[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {
            // k = i-L so k corresponds to number which
            // matches in [L,R] interval.
            k = i-L;
 
            // if Z[k] is less than remaining interval
            // then Z[i] will be equal to Z[k].
            // For example, str = "ababab", i = 3, R = 5
            // and L = 2
            if (Z[k] < R-i+1)
                Z[i] = Z[k];
 
            // For example str = "aaaaaa" and i = 2, R is 5,
            // L is 0
            else
            {
                // else start from R and check manually
                L = i;
                while (R<n && str[R-L] == str[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

int main()
{
    char *str = "aaabcxyaaaabczaaczabbaaaaaabc";
    int n = strlen(str);
    int z[30];
    getZarr(str,z);
    int i;
    for(i=0;i<30;i++)
    {
        printf("%d ",z[i]);
    }
    // int *arr = zValueArray(str, "aaabc");
    // for (i = 0; i < n; i++)
    //     printf("%d\n", arr);
    return 0;
}