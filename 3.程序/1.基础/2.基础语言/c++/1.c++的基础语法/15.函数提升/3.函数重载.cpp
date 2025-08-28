/**
 * 函数重载条件：
 *  同一作用域下
 *  同名函数
 *  形参类型或形参类型顺序或形参个数 不同
 *
 * 注意：返回值不是重载条件
 * 
 * 补充说明：
 * 1.引用作为形参，const可以作为重载条件，表示形参类型不同
 * 2.默认参数重载，会有二义性，编译器不知道调用谁。为避免这种情况函数如果重载尽量不设置默认参数
 */
#include <iostream>
using namespace std;

void function(int a, float b)
{
    cout << "function(int a,float b)" << endl;
}
void function(float b, int a)
{
    cout << "function(float b,int a)" << endl;
}
void function(float b)
{
    cout << "function(float b)" << endl;
}
// int function(float b){}// 报错，不属于重载


/*----------引用形参重载，可以用const标识类型不同-------------*/

void function2(int &a){}
void function2(const int &a){}

/*-----------默认参数重载------------*/
void function3(int a){}
void function3(int a,int b = 2){}

int main()
{
    int a = 1;
    float b = 1.4;

    ::function(a, b);//:: 作用域解析运算符，指定所属作用域。用于类、静态变量、命名空间 ; 符号 . 用于非静态成员
    ::function(b);

    function2(10);//内存地址不合法，所以与function2(int &a) 不匹配，而function2(const int &a)合法，所以没有二义性用于走带const的函数

    function2(a);//因为内存地址合法，直接走function2(int &a)

    // function3(1);//报错，产生二义性，编译器不知道匹配谁
    function3(1,2);//匹配function3(int a,int b = 2)
}