#include <stdio.h>

int maxArr(int *A, int n1)
{
    int i, maxi, maxj;
    int max1=A[0]; //Aj+j
    int max2=A[0]; //Ai-i
    int min3=A[0]; //Ai+i
    int min4=A[0]; //Aj-j

    for(i=0;i<n1;i++){
        if(max1<A[i]+i)
            max1 = A[i]+i;
        if(max2<A[i]-i)
            max2 = A[i]-i;
        if(min3>A[i]+i)
            min3 = A[i]+i;
        if(min4>A[i]-i)
            min4 = A[i]-i;
    }
    int p = max1 - min3;
    int q = max2 - min4;

    return (p>q)?p:q;
}

int main()
{
    
}
