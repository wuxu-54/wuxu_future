/**
 * 运算符重载
 * 
 * 关键字 operator
 * 定义：operator 加上 [运算符] ： operator*
 * 
 * 定义方式：P p3 = p1+p2;
 * 方式1.成员函数操作符重载 
 *  P operator+(P &p2)
 * 方式2.全局函数操作符重载
 *  P operator+(P &p1,P&p2)   
 * 
 * 补充：运算符重载本质就是【函数调用】，所以其支持【函数重载】
 * 
 * 支持操作符重载的运算符:
 * 
 * << >> ++ -- == > < () 等等其他不列出来了
 * 
 * operator<<()  
 * operator++()前置++  
 * operator++(int)后置++ 
 * operator==() 
 * operator()()函数调用运算符重载，因用法与函数相同，此类的对象叫函数对象，也叫仿函数
*/
#include <iostream>
using namespace std;

class P{
    public :
    int a;

    //成员函数操作符重载，参数是一个
    P operator+(P &p1){
       P temp;
       temp.a = this->a + p1.a;
      return temp;
    }
};


//全局函数操作符重载，参数是两个，没有this
// P operator+(P &p,P &p1){
//     P temp;
//     temp.a = p.a + p1.a;
//     return temp;
// }

int main(){
    P p1;
    p1.a =1;

    P p2;
    p2.a = 2;

    //全局函数操作符重载，本质如下，就是一全局函数调用
    // P p3 = operator+(p1,p2);

    //成员函数操作符重载，本质如下，也是一成员函数的调用
    // P p3 = p1.operator+(p2);

    //以上俩都可以简写为下面方式。当同时存在全局函数、成员函数 相同操作符重载，会报错，提示有多个，产生二义性
    P p3 = p1+p2;
}
