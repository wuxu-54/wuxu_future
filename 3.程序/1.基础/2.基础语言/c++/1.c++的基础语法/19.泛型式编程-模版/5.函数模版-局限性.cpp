/**
 * 函数模版不是万能的，有些情况下无法进行处理。比如 一个对象进行 == 操作，除非操作符重载否则编译器无法处理
 * 
 * 以上情况怎么处理？
 * 
 * 使用函数模版具体化，将模版方法具体化，针对性逻辑处理。
 * 
*/

#include<iostream>
using namespace std;

class Person{
    public:
    int a;
    Person(){}
};

template <typename T>
bool fun(T i,T j){
    cout<<i == j<<endl;
}

//模版具体化，针对Person类，进行逻辑具体化处理。这样运行时会走这个方法，从而不会报错；
template<> bool fun(Person p1,Person p2){
    return p1.a == p2.a;
}


int main(){
Person  p;
Person  p2;
fun(p,p2);//编译时不会报错，运行时报错。无法运算 Person  == Person 
}