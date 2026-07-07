
/**
 * 引用返回值
 * 
 * 1. 不要返回局部变量的引用。 为什么？ 局部变量在函数返回时会被销毁，返回它的引用会变成一个悬挂引用（Dangling Reference），后续访问将导致未定义行为（UB）。
 *  正确做法：
            返回静态变量的引用（生命周期贯穿程序）
            返回成员变量的引用（对象生命周期内有效）
            返回函数参数传入的引用（由调用者保证生命周期）
 * 
 * 2. 如果函数返回值是非const引用，那么可以作为左值，进行赋值。 
 */
#include<iostream>
using namespace std;


/**
 * 这里返回引用
*/
int& fun1(){
    int a = 10;//局部变量，栈区

    return a;
}

int& fun2(){
    static int a = 10;//不用管static，这是个示例
    return a;
}

int main(){

   int& a = fun1();

   cout<<a<<endl;//第一次正常，因为编译器保留，没有立刻移除a
   cout<<a<<endl;//此次异常了，因为内存被释放了

   fun2() = 111;//static int a 被赋值为111
}