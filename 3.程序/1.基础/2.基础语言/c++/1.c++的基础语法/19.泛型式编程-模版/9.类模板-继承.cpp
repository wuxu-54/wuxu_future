/**
 * 类模板继承时需要注意：
 * 1.子类继承的父类是个类模板时，子类需要声明父类模版的类型
 * 2.如果子类不明确父类模版的类型，编译器无法给子类分配内存，因为编译器不知道继承的类型具体是啥。
 * 3.如果想灵活指定父类模版的类型，子类也可声明为类模板
*/

#include<iostream>
using namespace std;

template <class T,class K>
class Person{
    public:
    T a;
};

// class Son:Person{}//错误，编译器必须知道父类模版的具体类型，才能给子类分配内存。

//1.子类明确指定父类模版的类型
class Son : Person<int,float>{};

//2.如果想灵活指定类型，可以使用模版
template <class T>
class Son2:Person<T,int>{};

int main(){}