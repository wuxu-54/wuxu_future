#include <stdio.h>

/**
 * 基本数据类型
 * char、short、int、long、float、double
 * 
 * c中没有字符串类型，都是用char数组来表示
 * 
*/
int main(){
    char c = 'c';
    short s = 123;
    int i = 12;
    long l = 12l;
    float f = 12.9f;
    double d = 12.4;
  

    //!字符串
    //C语言没有对象，使用char[] 表示字符串
    char arr1[] = {'1','2','a','n'};
    printf("string %s\n",arr1);

    //C语言使用 \0 表示结束
    char arr2[] = {'1','2','a','n','\0'};
    printf("string2 %s\n",arr2);

    //常用字符串表示方式：
    char arr3[]= "adfdsa";//注意：字符串是双引号，字符型char是单引号
    printf("string3 %s\n",arr3);

    //第四种表达方式，与上方数组相同，这里是指针，表示数组所在内存地址
    char* arr4 = "addfds";
    printf("string4 %s\n",arr4);
    //!end
   
}