/**
 * 运算符重载
 * 
 * operator()()函数调用运算符重载，因用法与函数相同，此类的对象叫函数对象，也叫仿函数
 * 
 * 谓词
 * 仿函数，并且返回值是bool类型。形参只有一个叫一元谓词，形参两个叫二元谓词
*/
#include <iostream>
using namespace std;


class P{
    public :
    int count;
    void operator()(int i,int j){
        //函数调用操作符重载，所在类的对象叫函数对象，也叫仿函数，用法和函数一样
        count++;
        cout<<i<<j<<endl;
    }

    bool operator()(int i){}//一元谓词

    bool operator()(int i,float j){}//二元谓词
};

int main(){

    //仿函数，函数对象
    P p;
    p(1,2);//函数对象调用和方法一样
}
