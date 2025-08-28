
/**
 * 二者区别
 * 
 *  函数模版
 *      1.隐式类型推导 无法发生隐式类型转换
 *      2.主动指定类型 可以发生隐式类型转换
 * 
 *  普通函数
 *      1.可以发生隐式类型转换
*/
#include<iostream>
using namespace std;

void fun(int i,int j){
    cout<<i+j<<endl;
}

template <class T>//class T 是与typename完全相同的另一种写法
void fun2(T i,T j){
    cout<<i+j<<endl;
}

int main(){
    int i=1;
    int j = 2;
    char k = 'a';
    fun(i,k);//这里发生隐式类型转换，char变为 ASCII码对应值 成为int类型

    // fun2(i,k);//报错，函数模版隐式类型推导，无法发生隐式类型转换
    fun2<int>(i,k);//函数模版显示指定类型，可以发生隐式类型转换
}   