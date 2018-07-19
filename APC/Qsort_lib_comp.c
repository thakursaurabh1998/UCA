#include<stdio.h>
#include<stdlib.h>

int asc(const void *x, const void *y){
    return *((int*)x)-*((int*)y);
}

int desc(const void *x,const void *y){
    return *((int*)y)-*((int*)x);
}

int main()
{
    int i;
    int a[6] = {7,31,24,3,4,9};
    qsort(a,6,sizeof(int),asc);
    for(i=0;i<6;i++)
        printf("%d ",*(a+i));
    qsort(a,6,sizeof(int),desc);
    printf("\n");
    for(i=0;i<6;i++)
        printf("%d ",*(a+i));
    return 0;
}
