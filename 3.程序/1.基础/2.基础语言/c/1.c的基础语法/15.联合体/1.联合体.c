/**
 * 联合体：变量共用同一块内存
*/

#include<stdio.h>

union test
{
    short i;
    int j;
};


int main(){
    union test t;
    t.i = 1;
    t.j =12;

    printf("i== %d,j==%d\n",t.i,t.j);

    printf("%d\n",sizeof(union test));
}