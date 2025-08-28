#include <stdio.h>

/**
 * 静态内存：系统在栈中自动分配的内存
 * 
 * 以下是为了对比静态内存的问题
 * 1.arr属于栈中，局部变量,方法fun1调用后会回收内存
 * 2.arr2同样属于栈中的局部变量，在fun1方法结束后因为内存回收，导致指针原来指向arr1位置，变为指向arr2
 */ 
int* fun1(){
    int arr1[3] = {1,2,3};
    return &arr1;
}

int* fun2(){
    int arr2[3] = {4,5,6};
    return &arr2;
}

int main(){
    int *p;
    p = fun1();
    printf("1>%d,%d,%d\n",*p,*(p+1),*(p+2));
    fun2();
    //fun2调用后，p指针指向的地址没变，但是输出的结果变为了arr2，因为栈中fun1方法出栈，fun2入栈，导致fun2中的变量使用原arr1内存地址。
    printf("2>%d,%d,%d\n",*p,*(p+1),*(p+2));
}