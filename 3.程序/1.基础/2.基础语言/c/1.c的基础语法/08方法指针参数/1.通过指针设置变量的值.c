#include <stdio.h>

/*
    函数参数是一个指针，局部变量持有原 main函数中的变量内存地址。所以此方法操作指针，可通过修改main中变量数据
*/
int getData(int *i,int *j){
    *i = 1;
    *j=456;
}

int main(){
    int i;
    int j;
    getData(&i,&j);

    printf("i=%d,j=%d\n",i,j);
}