#include <stdio.h>
#include<stdlib.h>

/**
 * wuxu 学习
 * 输出
 */

void printBasic(){
    //> 1.基本数据类型以及格式符
    char c = 'c';
    short s = 123;
    int i = 12;
    long l = 12l;
    float f = 12.9f;
    double d = 12.4;

    //> 2.输出，格式替代符
    printf("char is %c \n", c);
    printf("short is %hd \n", s);//half d ,short 类型是hd
    printf("int is %d \n", i);
    printf("long is %ld \n", l);
    printf("float is %f \n", f);
    printf("double is %lf \n", d);


    //补充
    int x = 3241231;
     //%x 表示16进制
    printf("%x\n",x);
    // %#x 16进制前面增加0x前缀
    printf("%#x\n",x);

}


void printString(){
    //C语言没有对象，使用char[] 表示字符串
    char arr1[] = {'1','2','a','n'};
    printf("string %s\n",arr1);

    //C语言使用 \0 表示结束
    char arr2[] = {'1','2','a','n','\0'};
    printf("string2 %s\n",arr2);

    //常用方式：
    char arr3[]= "adfdsa";
    printf("string3 %s\n",arr3);
}

int main(){
    printBasic();
    
    printString();
   
}