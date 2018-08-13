
char *encode(char *input)
{
    char *s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";
    char *result = (char *)malloc(sizeof(char) * ((strlen(input) * 8 / 6) + 3));
    int i = 0;
    int p = 0;
    int r = 0;
    char carry;
    char temp;
    while (input[i])
    {
        if (p == 0)
        {
            temp = input[i] >> 2;
            carry = input[i] & 3;
        }
        else if (p == 1)
        {
            temp = input[i] >> 4;
            carry <<= 4;
            temp |= carry;
            carry = input[i] & 15;
        }
        else if (p == 2)
        {
            temp = input[i] >> 6;
            carry <<= 2;
            temp |= carry;
        }
        else if (p == 3)
        {
            temp = input[--i] & 63;
        }
        result[r++] = s[temp];
        i++;
        p = (p + 1) % 4;
    }
    if (p == 0)
    {
        temp = input[i] >> 2;
        carry = input[i] & 3;
    }
    else if (p == 1)
    {
        temp = input[i] >> 4;
        carry <<= 4;
        temp |= carry;
        carry = input[i] & 15;
    }
    else if (p == 2)
    {
        temp = input[i] >> 6;
        carry <<= 2;
        temp |= carry;
    }
    else if (p == 3)
    {
        temp = input[--i] & 63;
    }
    result[r++] = s[temp];
    if (strlen(input) % 3 == 2)
        result[r++] = '=';
    else if (strlen(input) % 3 == 1)
    {
        result[r++] = '=';
        result[r++] = '=';
    }
    return result;
}
