/**
 * 占位参数
 * 
 * 函数形参占位，调用时传入，函数体中不用
 * 定义：函数名（数据类型）{}
 * 作用：可以封装结构时用
 * 
 * 占位参数可以有默认参数
*/

#include<iostream>
using namespace std;

//这个int就是占位用的，外部调用必须传此类型的数据。函数体中是无法使用的。
void fun(int a ,int = 10){
    cout<<a<<endl;
}

int main(){
    fun(1,2);
}