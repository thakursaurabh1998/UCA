#include <assert.h>

int logicalShift(int x, int n)
{
    return (x >> (n << 3)) & 0xff;
}

// void test()
// {
//     assert(getByte(1,4) == 1);
//     assert(getByte(1,2) == 0);
//     assert(getByte(257,4) == 1);
// }

int main()
{
    // test();
    printf("%d",getByte(255,4));
    return 0;
}