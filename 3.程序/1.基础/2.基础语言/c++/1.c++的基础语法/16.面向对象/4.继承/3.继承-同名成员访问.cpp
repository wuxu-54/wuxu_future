/**
 *
 * 继承对于同名成员（命名、参数完全相同）的处理
 *
 * 出现同名成员时，编译器会隐藏父类成员
 *
 * 1.类名.成员名 调用的是子类成员
 * 2.如果访问父类成员,需要明确【作用域】。通过对象访问方式：对象名.父类名::成员名； 父类名:: 指父类作用域下的成员
 * 3.静态同名成员，比对象访问方式，多一个类名访问方式：类名::父类名::静态成员名；  第一个是::指通过类名访问  第二个::指父类作用域下
 */

#include <iostream>

using namespace std;

class Base
{
public:
    int a;
    void fun()
    {
        cout << "base" << endl;
    }
    static int b;
};

int Base::b = 200;


class Child : public Base
{
public:
    int a;
    void fun()
    {
        cout << "child" << endl;

        // 调用父方法
        Base::fun();
    }

     static int b;
};

int Child::b = 200;

int main()
{
    Child child;

    // 访问Child类的
    child.a = 1;
    child.fun();

    // 外部访问父类的成员 child.Base 表示父类作用域
    child.Base::a = 2;
    child.Base::fun();

    //静态成员
    // 方式1 对象的方式
    cout<<"base b = "<< child.Base::b<<endl;
    // 方式2 类名方式  第一个是::指通过类名访问  第二个::指父类作用域下的成员b
     cout<<"base b = "<< Child::Base::b<<endl;
}