/**
 * 1.普通类成员函数编译时就已经创建
 * 2.类模板成员函数调用时才创建，因为只有调用时编译器才知道具体类型
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
void fun2(Person<int,int> p){
    p.test();
    // p.fun();//这里编译器直接会提示方法不存在，说明编译时就已经创建检测合法性了。
}

template<class T>
void fun3(T p){
    p.test();//函数模版，编译时不知道具体类型，可以直接调用未知方法，只有调用时才会确定是否合法
    p.fun();//fun() 根本不存在，但是编译时不报错，只有调用到此时才会确定此函数不合法
}

int main(){
    Person<int ,int> p;
    p.a = 1;
    p.k = 2;
    fun3(p);
}