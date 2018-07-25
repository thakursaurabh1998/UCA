#include<stdio.h>

int getByte(int x, int n){
    return ((x>>8*n)&255);
}

int main(){
    printf("%d",getByte(512,1));
    printf("\n%d",~1);
    return 0;
}