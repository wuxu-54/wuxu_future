/**
 * 默认参数
 * 定义 ： 函数名（形参=默认值）{}
 * 
 * 注意事项：
 * 1.某个位置已有默认参数，从左到右 后面的形参都必须设置默认参数
 * 2.函数声明与函数实现 相同形参，只能有一个可以有默认参数
*/

#include<iostream>
using namespace std;

/**
 * 默认参数 ： 函数名（形参=默认值）{}
*/
void fun(int x = 555, int y=1, int z = 12){
    cout<<y<<endl;
}

/**
 * 1.某个位置已有默认参数，从左到右 后面的形参都必须设置默认参数
*/
//此函数有错误 error: missing default argument on parameter 'y'
// int fun1(int a,int b = 10 ,string c,int d){
//     return a+b+d;
// }

/**
 * 函数声明有默认参数，那么函数实现不能再有默认参数
*/

void fun2(int x,int y=2);
//报错redefinition of default argument，默认函数重新定义了
// void fun2(int x =10,int y=11){
//     cout<<y<<endl;
// }
//这个可以，与上述声明，相同形参只有一个默认值
void fun2(int x =10,int y){
    cout<<y<<endl;
}


int main(){
    // fun(1,2,3);

    fun2(1,3);
}