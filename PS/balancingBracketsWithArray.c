#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *isBalanced(char *input)
{
    char brackets[] = {'[', ']', '(', ')', '<', '>', '{', '}'};
    int len = strlen(input);
    int i, j, flag = 1;
    char *stack = (char *)malloc(sizeof(char) * len);
    int sv = 0;
    // if (len % 2 != 0)
    //     return "NO";
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < 8; j += 2)
        {
            if (input[i] == brackets[j])
            {
                flag = 0;
                break;
            }
            else if (input[i] == brackets[j + 1])
            {
                flag = 1;
                break;
            }
        }
        switch (flag)
        {
        case 0:
            stack[sv++] = brackets[j];
            // printf("%c ", stack[sv-1]);s
            // i++;
            break;
        case 1:
            // printf("%c ",stack[i-1]);s
            if (stack[sv - 1] == brackets[j])
                sv--;
            else
                return "NO";
            break;
        }
        // for(j=0;j<len;j++)
        //     printf("%c\t",stack[j]);
    }
    if(sv>0)
        return "NO";
    return "YES";
}

int main()
{
    printf("%s", isBalanced("{{}}"));

    return 0;
}