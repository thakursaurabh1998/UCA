unsigned int reverse(unsigned int A)
{
    unsigned int b = 0x80000000;
    unsigned int c = 0;
    while (A)
    {
        if ((A & 1) == 1)
        {
            c |= b;
        }
        A >>= 1;
        b >>= 1;
    }
    return c;
}