/**
 * （c++特有）
 * 如何在堆区开辟空间
 * 
 * 使用关键字 new
 * 释放：delete
 * 
 * 补充: 
 * 在指定内存地址开辟空间如何写？
 * 答：  用 placement new . placement new 是 C++ 中一个非常特殊且强大的内存操作工具。它允许你在已经分配好的原始内存上构造对象，而不是在堆上重新分配内存。
 *      写法： new(指定内存地址) 数据类型()  
*/
#include<iostream>
using namespace std;

int main(){
    int *a = new int(10);//这里内存就在堆中，同时堆区的局部变量可以传递到外部

    delete a;//释放变量

    int *arr = new int[10];//创建数组
    delete []arr;//释放数组时需要有[]


    new(a) int(11); // placement new  指定内存地址创建. 解释：  1. 不分配内存 2. 直接在地址 a 上构造对象 3. 返回 a（类型已转换）
}