#include <stdio.h>

/**
 * 变量：可以被重新赋值
*/

int c  =1 ;//这是全局变量，声明在全局静态区

int main(){
    int i = 1; //函数内的是局部变量，声明在栈区，作用域不同   
    printf("a size is %lu \n",sizeof(i));
}