/**
 * 类中的静态成员可分为：静态变量、静态函数
 * 
 * 静态成员：
 * 1.所有对象共享同一静态成员，也就是静态成员内存是唯一的
 * 2.方法1： 对象访问；方法2： 类名::静态成员 
 * 3.封装特性，私有静态无法外部调用
 * 4.静态函数只能访问静态变量（因为是全局静态区，所以静态函数使用的数据必须是同为静态的）
*/
#include<iostream>
using namespace std;

class T{
    public:
    int m_a;
    static int m_b ;//静态成员变量
    static void fun(){//静态成员函数
        // m_a=1;//无法访问非静态成员变量，因为非静态成员变量可以属于多个对象，编译器无法识别具体哪个才是需要用的。

        if (m_b == 0)
        {
           m_b = 2;
        }
        

        cout<<"b = "<<m_b<<endl;
    }

    private:
    static void private_fun(){
        static int privateB = 1;
        cout<<"private_fun = "<<privateB<<endl;
        privateB++;
    }
};
int T::m_b = 1;// 静态成员变量初始化赋值

int main(){
    T t = T();
    t.fun();
    // T::fun();//类名::静态成员 调用
//   T::private_fun();//私用静态，外部无法访问
}