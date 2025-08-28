/**
 * 多态：父类函数，多个子类重写，但每个实现都不同。
 * 例如：动物行动，马可以跑，鸟可以飞。 这就是对同种行为，不同实现。
 * 
 * 多态类型:
 * 静态多态：普通函数重写、重载 和 运算符重载属于静态多态，复用函数名。也就是普通函数或重写
 * 动态多态：派生类和虚函数 实现运行时多态
 * 
 * 静态多态与动态多态区别：
 * 静态多态：函数地址早绑定，编译阶段确定函数地址
 * 动态多态：函数地址晚绑定，运行阶段确定函数地址
 * 
 * 多态满足条件：
 *  * 父类函数由普通函数变为虚函数（virtual修饰）
 *  * 子类重写父类虚函数
 * 
 * 多态使用条件：
 *  * 父类指针或引用，指向子类对象
 * 
 * 重写：函数返回值类型，函数名，参数列表 完全一致称为重写
*/

#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void aa() = 0;//纯虚函数，java中的抽象方法，子类必须重写
    virtual void run(){//虚函数
        cout<<"animal run."<<endl;
    }
    // void run(){
    //     cout<<"animal run."<<endl;
    // }

    virtual ~Animal(){}
};

class Cat:public Animal{
    public:
    void aa(){}
    void run(){
         cout<<"cat run."<<endl;
    }
};

class Dog:public Animal{
    public:
    void aa(){}
    void run(){
         cout<<"dog run."<<endl;
    }
};

void startRun(Animal &animal){
    animal.run();
}

void funTest(){
    Cat cat;
    //这里虽然传入的是cat，但是最终调用的是 animal 这个基类函数，这是为啥？
    //解：多态分为静态多态、动态多态。这种原因就是静态多态，普通函数在编译时就被编译器确定内存地址并设置好了。所以引用是基类类型，最终调用的就是基类方法

    //如何调用cat方法呢，使用动态多态。基类普通函数 设定为虚函数（virtual修饰）并且子类重写，编译器识别的是个指针变量，但无法确定具体内存地址，只有在真正运行时通过指针调用到方法。也就是最终调用到对象中的方法。
    startRun(cat);
}

int main(){

}