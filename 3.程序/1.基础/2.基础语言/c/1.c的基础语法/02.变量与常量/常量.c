#include <stdio.h>

/**
 * 常量：无法重新赋值
 * 
 * 常量有两种定义方式：
 * 1.宏定义 #define 常量名 常量值
 * 2.const修饰 const 数据类型 常量名 = 常量值
*/
#define A 2
int main(){
    const int a =1;// a 无法重新赋值
    printf("a size is %lu \n",sizeof(a));
    printf("A size is %lu \n",sizeof(A));
}