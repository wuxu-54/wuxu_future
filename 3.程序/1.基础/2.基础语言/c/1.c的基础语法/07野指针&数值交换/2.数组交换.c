#include <stdio.h>

/**
 * 参考： https://www.bilibili.com/video/BV1BK4y1j7AW?p=8
 * 
 * int值:
 * 变量在栈中持有具体值，交换具体数值，但如果使用方法，会在地址中重新申请块内存，所以普通值只会影响到局部方法参数
 * 
 * 引用:
 * 变量持有的是内存地址，内存地址指向堆内存中的具体数值，所以方法内交换数值，外部也会跟着交换。
 * 
 * 指针：
 * 变量持有的是内存地址，内存地址指向原变量所在内存地址的具体数值，所以方法内交换数值，外部也会跟着交换。
*/



void swap(int i,int j);

void swapPoint(int* i,int* j);

struct Student{
   int age; 
};

void swapStruct(struct Student st1 ,struct Student *st2);


void swapStruct(struct Student st1 ,struct Student *st2){
    printf("%d,%d",st1.age,st2->age);
}

int main(){
    int i = 1;
    int j = 2;
     printf("old i = %d,j=%d",i,j);
    // int temp = i;
    // i = j;
    // j = temp;
    // printf("swap i = %d,j=%d",i,j);
}
