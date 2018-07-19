#include <stdio.h>

int main(){
    float x = 5.3f;
    unsigned c  har* c = (char*)&x;
    int i;
    // scanf("%d",i);
    printf("%d\n",i);
    for(i=0;i<4;i++)
        printf("%d\n",*(c+i));

    return 0;
}