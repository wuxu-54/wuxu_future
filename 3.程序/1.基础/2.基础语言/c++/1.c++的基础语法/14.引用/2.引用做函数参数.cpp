#include<iostream>
using namespace std;

/**
 * 引用形参
 * 
 * 引用作为形参，因为其是引用类型所以不会在栈中开辟新地址承接。
 * &a 是指向实参的别名，所以引用类型形参可以操作实参
*/
void fun(int &a,int &b){

}

int main(){
    int a = 1;
    int b =2;

    //这里形参是引用类型承接，所以形参可以操作实参。
    fun(a,b);
}