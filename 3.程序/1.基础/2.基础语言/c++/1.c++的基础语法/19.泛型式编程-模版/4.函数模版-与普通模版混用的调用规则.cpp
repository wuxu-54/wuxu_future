/**
 * 函数模版与普通函数混用调用规则（开发时尽量不同时出现）
 * 1.函数模版可以与普通函数完全相同，此时优先普通函数
 * 2.可以通过空模版参数强制调用函数模版。 显示指定空参数
 * 3.函数模版可以发生重载
 * 4.当函数模版匹配程度高于普通函数时，优先函数模版
*/

#include<iostream>
using namespace std;

void fun(int i , int j){
    cout<<"fun"<<endl;
}

template <typename T>
void fun(T i,T j){
    cout<<"template fun"<<endl;
}

template <typename T>
void fun(T i,T j,T k){//函数模版可以重载
    cout<<"template overload fun"<<endl;
}




int main(){
    fun(1,2);//规则1

    fun<>(1,2);//规则2

    fun(1,2,3);//规则3
    fun('1','2');//规则4 ，这里普通函数也适用，但是匹配度函数模版更高，T直接推导出为char类型，无需隐式类型转换。
}