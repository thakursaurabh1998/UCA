#include <stdio.h>

int strstrs(char *str, char *cmp)
{
    int i=0;
    int j=0;
    int index=-1;
    int flag = 1;
    while(str[i] && cmp[j])
    {
        // printf("%c %c\n",str[i],cmp[j]);
        if(flag)
            index = i;
        if(str[i]==cmp[j])
        {
            j++;
            flag = 0;
        }
        else
        {
            i=index;
            flag=1;
            j=0;
        }
        i++;
    }
    if(cmp[j] != 0)
        return -1;
    return index;
}

int main()
{
    char *str = "abcab";
    printf("%d", strstrs(str, "kasdjfld"));

    return 0;
}