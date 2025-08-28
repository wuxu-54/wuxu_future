/**
 * const 修饰函数，此函数就是【常函数】
 *  定义：void fun () const
 * const 修饰对象，此对象就是 【常对象】
 *  定义： const T t;
 * 
 * 作用：使得this 指向的值 只可读，不能改
 *
 * 那如果常函数/常对象中仍然想要修改变量，那么此变量必须用 `mutable` 修饰，表示此变量可以修改。
 * 
 * 注意：
 * 1. 常对象只能调用常函数； 因为常对象不可以修改普通变量，普通函数可以修改普通变量
 * 2. mutable 修饰的变量才能在常函数或常对象中修改
*/

#include <iostream>
using namespace std;

class T{
    public:
    int a; 
    mutable int b;

    //常函数
    void fun () const{
        b = 1;//mutable 变量，可以在常函数中修改
        // a = 2;//报错，a等同于this->a, 此时a不能在常函数中修改
    }

    void fun2(){
        a = 1;
    }
};

int main(){
    const T t = T();
    // t.a = 1;//报错，常对象不能修改
    t.b = 2;//正常
    // t.fun2();//常对象，只能调用常函数，因为普通函数可以修改变量
}