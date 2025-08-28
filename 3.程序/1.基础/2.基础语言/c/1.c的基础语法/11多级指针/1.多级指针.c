#include<stdio.h>

int main(){
    int i = 123;
    int *p1 = &i;//一级指针
    int **p2 = &p1;//二级指针
    int ***p3 = &p2;//三级指针

    printf("%d\n",***p3);
}