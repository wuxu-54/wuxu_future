/**
 * 类模板的友元函数用法
 *  * 类内实现
 *      1. 直接按普通类方式实现即可
 *  * 类外实现
 *      1. 需要增加模版空参数列表<>，表示这是个函数模版的声明
 *      2. 函数模版的特殊性，所有类外函数模版的实现必须在类模版上面（编译器顺序编译），否则报错找不到函数实现
*/
#include<iostream>
using namespace std;

template <class T>
class Person;//告诉编译器，这个类我声明了，别报错

//这里就可以访问Person类模版的所有数据
//必须在类模版上面，否则编译器从上到下顺序调用时找不到此函数模版
//Person 类也得提前声明
template <class T>
void fun2(Person<T> p){
}


template <class T>
class Person{
    //1.类内实现，直接按普通类友元写
    friend void fun(){
        cout<<"这是友元-类内实现"<<endl;
    }

    //2.类外实现,增加模版空参数列表<>，表示这是函数模版的方法声明，如果不加那就是普通函数的声明了。
    friend void fun2<>(Person<T> p);
};


int main(){

}