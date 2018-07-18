#include<stdio.h>

int func1(int x, int y, int (*arr)[x][y]){
    int i,j;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            printf("%d", *(*(*arr+i)+j));
    printf("\n");
}

int func2(int x, int y, int (*arr)[3]){
    int i,j;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
            printf("%d", *(*(arr+i)+j));
    printf("\n");
}

int func3(int x, int y, int *arr){
    int i,j;
    for(i=0;i<x*y;i++)
        printf("%d", *(arr+i));
    printf("\n");
}

int main(){
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    func1(3,3,&arr);
    func2(3,3,arr);
    func3(3,3,*arr);
    return 0;
}
