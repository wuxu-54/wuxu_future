/**
 * 类模板实例化的对象，作为函数参数传递
 * 
 * 三种传入方式：
 * 1.指定传入类型， 直接显式的指明需要的类型
 * 2.将对象参数模版化，对象中的参数变为模版进行传递
 * 3.将整个类模版化，整个对象变为一个模版传递。
*/

#include<iostream>
using namespace std;

template <class T,class K>
class Person{
    public :
    T a;
    K k;

    void test(){
        cout<<a<<k<<endl;
    }

};

//传入方式1，指定类型
void fun1(Person<int,float> p){
    cout<<p.a<<endl;
}

//传入方式2，对象参数模板化
template <class T1,class T2>
void fun2(Person<T1,T2> p){
    cout<<p.a<<endl;

    cout<<typeid(T1).name()<<endl;//可以看到模版类型中的具体数据类型
}

//传入方式3，对象模版化
template<class T>
void fun3(T p){
    p.test();//函数模版，编译时不知道具体类型，可以直接调用未知方法，只有调用时才会确定是否合法
}

int main(){
    Person<int ,int> p;
    p.a = 1;
    p.k = 2;
    fun3(p);
}