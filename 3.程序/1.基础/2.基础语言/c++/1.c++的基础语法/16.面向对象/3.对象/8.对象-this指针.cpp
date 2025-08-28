/**
 * 非静态成员函数在方法区内存，与类不是同一个内存区，且是唯一的，多个同类型对象会共用一块代码，为了区分谁调用的这个函数，c++使用this 标明作用对象
 * 
 * this 指针：指向调用成员函数的对象。this指针是个 【指针常量】 相当于 P * const this;
 * 
 * 常用于：链式调用，return this；
*/

#include<iostream>
using namespace std;

class P{
    public :
    int a;
    void fun(){
        this->a = 1;
    }

    P fun2(){
        return *this;
    }
    P fun3(){
        return *this;
    }
    P fun4(){
        return *this;
    }
};

int main(){
    P p1;
    p1.fun();//fun 函数是p1对象调用，那么this指针 指向p1对象

    p1.fun2().fun3().fun4().fun();//使用this 做链式调用
}