/**
 * （c++特有）
 * 如何在堆区开辟空间
 * 
 * 使用关键字 new
 * 释放：delete
 * 
 * 补充: 
 * 在指定内存地址开辟空间如何写？
 * 答：  用 placement new 
 *      写法： new(指定内存地址) 数据类型()  
*/
#include<iostream>
using namespace std;

int main(){
    int *a = new int(10);//这里内存就在堆中，同时堆区的局部变量可以传递到外部

    delete a;//释放变量

    int *arr = new int[10];//创建数组
    delete []arr;//释放数组时需要有[]


    new(a) int(11); // placement new  指定内存地址创建
}