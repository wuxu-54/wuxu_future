/**
 * friend 关键字修饰
 * 
 * 友元：标记某个类是自己的好朋友，这个好朋友可以任意 访问自己的函数变量 即使是私有的。
 * 
 * 目的：封装把成员设定为私有、公共、子类可访问。但是有些情况下我们想要成员私有，特定的类又需要访问到，此时就有了友元的帮助，使得代码更灵活。
 *（这里不要觉得友元破坏了封装性，因为没有友元，结构设计上就太死板，无法到达上面的目的）

    友元全局函数：friend  + 函数声明； 实现此声明的全局函数就可以访问类
    友元类：friend + 类声明； 友元类就可以访问此类中所有成员
    友元成员函数：friend + 其他类::成员函数声明； 此其他类中的成员函数可以访问此类中所有成员
 */
#include<iostream>
using namespace std;


/**
 * 这里是类的前向声明（结构体也有），告诉编译器，我有一个类，叫T。
 * 
 * 前向声明类/结构体,其具体结构对于编译器来说是不明确的（编译器是顺序编译），所以使用时，只能作为指针对象或引用，而外部不能调用里面具体成员，否则出现：程序编译是出现"field has incomplete type"问题
 * 
 *"field has incomplete type"问题: https://blog.csdn.net/u010608296/article/details/102393543
*/
class T;
class S{
    public:
    void fun(T *t);
};

class T{
    private :
    int a = 1;

    //标记此声明的全局函数是友元函数
    friend void fun(T *t);

    //标记此声明的类是友元类，P类可以访问T类所有成员
    friend class P;


    //标记此声明的S类中的成员函数是友元函数
    friend void S::fun(T *t);
};

void S::fun(T *t){
     cout<< t->a<<endl;
}

class P{
    public:
    void fun1(T *t){
        cout<< t->a<<endl;
    }
};

//全局函数,作为T的友元函数实现，可以访问私有成员
void fun(T *t){
    t->a = 1;
}

int main(){
    P p = P();
    T t = T();

    p.fun1(&t);
}