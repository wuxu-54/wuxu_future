/**
 * 普通类成员函数的类外实现
 * 返回类型 作用域类名::函数名(参数列表){}
 * 
 * 类模板的成员函数类外实现
 * 1.需要成员函数增加类相同的模版声明
 * 2.在作用域类名后或是::前，写上模版类型参数; 类模版声明 返回类型 作用域类名<模版参数列表>::函数名(参数列表){}
 * 
 * 类模板的成员函数类外实现，其实原理与类模板继承没啥区别，如果不指明模版类型，编译器就无法根据类型分配内存。
*/

#include<iostream>
using namespace std;
class PersonNor{
    public:
    void fun();
};
// 普通类成员函数类外实现
void PersonNor::fun(){}

template <typename T>
class Person{
    public:
    void fun();
};
//类模板成员函数类外实现：类模版声明 返回类型 作用域类名<模版参数列表>::函数名(参数列表){}
template <typename T>
void Person<T>::fun(){}//T 是类模板中的类型，类模板成员函数必须指明，这样才是完整的作用域

int main(){}