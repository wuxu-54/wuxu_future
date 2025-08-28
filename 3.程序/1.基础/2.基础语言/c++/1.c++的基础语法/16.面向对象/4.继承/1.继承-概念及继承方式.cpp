/**
 * 面向对象设计特性之一 继承
 * 
 * 类可以让另一个类继承，被继承的类就是 父类又叫超类、基类，继承的类叫子类也叫派生类
 * 
 * 1.子类可以访问父类私有权限外的其他所有内容。
 * 2.子类可以重写父类函数（注意这个是重写，是子类实现了一个与父类中完全相同的函数；不是重载）
 * 3.子类有三种继承方式：公共继承、保护继承、私有继承。 子类会依据继承方式重新设定父类的参数权限。
 * 4.c++继承支持多继承，也就是可以有多个基类
 * 
 * 继承的好处：
 *          重复的、相同逻辑的代码 可以抽取成一个基类，避免重复代码。
 * 
 * 定义方式：子类:继承方式 父类{}
 * 
 * 
 * 补充：
 * 1.学习视频看到 ，【vs开发人员命令提示工具】可以用 【cl /d1 reportSingleClassLayout】命令查看类结构及大小
 * 2.子类继承父类时，子类会将父类所有非静态成员都继承下来包括私有，所以子类在计算大小 sizeof 时会算进去。编译器是将父类私有属性对子类访问隐藏，不是没有。
 * 3.子类继承父类，就是把父类的东西完全copy一份。包括虚函数表，虚函数指针，虚基类指针，虚基类表
*/


#include<iostream>

using namespace std;
class Parent{
    private:
    int a = 1;
    void fun1(){}

    public:
    int b =2;
    void fun2(){}

    protected:
    int c = 1;
    void fun3(){}
};

/**
 * 公共继承
 * 父类变量在子类中保持原访问权限
 * 
 * protected:
 *  int c = 1;
 * public:
    int b =2;
*/
class Child:public Parent{
    public:
    void funC(){
        cout<<b<<c<<endl;//可以访问父类非私有属性
    }
};


/**
 * 保护继承
 * 父类公共参数在子类中变为保护权限
 * 
 * protected:
 *  int c = 1;
    int b =2;
*/
class Child1:protected Parent{
  void funC(){
        cout<<b<<c<<endl;//可以访问父类非私有属性
    }
};



/**
 * 私有继承
 * 父类参数在子类中变为私有
 * 
 * private:
 *  int c = 1;
    int b =2;
*/
class Child2:private Parent{
    void funC(){
        cout<<b<<c<<endl;//可以访问父类非私有属性
    }
};

int main(){
    Child child;
    child.b;
    // child.c; //protected 不可被访问
    Child1 child1;
    // child1.b;//child1 是保护继承， 父类的变量在子类中，由public变为protected了，无法访问
    Child2 child2;
    // child2.b;//child1 是私有继承， 父类的变量在子类中，由public变为private了，无法访问


}