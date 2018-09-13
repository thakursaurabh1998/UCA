#include <stdio.h>
#include <stdlib.h>
#include "StackArray.h"

int largestRectangle(int *hist, int n)
{
    Stack stak;
    Stack* stk =&stak;
    initialize(stk, n);
    int maxArea = 0;
    int areaTop, top;
    int i = 0;
    while (i < n)
    {
        if (isEmpty(stk) || hist[peek(stk)] <= hist[i])
            push(stk, i++);
        else
        {
            top = pop(stk);
            areaTop = hist[top] * (isEmpty(stk) ? i : (i - peek(stk) - 1));
            if (maxArea < areaTop)
                maxArea = areaTop;
        }
    }
    while (!isEmpty(stk))
    {
        top = pop(stk);
        areaTop = hist[top] * (isEmpty(stk) ? i : (i - peek(stk) - 1));
        if (maxArea < areaTop)
            maxArea = areaTop;
    }

    return maxArea;
}

int main()
{
    int histogram[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;
    int ans = largestRectangle(histogram, n);
    printf("%d", ans);

    return 0;
}