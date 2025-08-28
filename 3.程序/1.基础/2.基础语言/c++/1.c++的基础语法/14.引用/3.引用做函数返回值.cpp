
/**
 * 引用返回值
 * 
 * 1. 不要返回局部变量的引用
 * 2. 如果函数返回值是引用，那么可以作为左值，进行赋值。 
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