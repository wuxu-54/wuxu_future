
/**
 * 使用函数模版注意
 * 1.类型T 必须是相同的。
 * 2.编译器可以自动推导出具体的模版类型T ；分为隐式类型推导（编译器自动推导）、显示指定类型（主动告诉编译器具体类型）
*/
#include<istream>
using namespace std;


//1.定义
template <typename T> //告诉编译器 T 类型别报错
void swap(T a,T b){ //简单的数据交换模版函数
    T temp = a;
    a = b;
    b = temp;
}

//注意1.编译器可以推导出具体的模版类型T 
template <typename T> //告诉编译器 T 类型别报错
void fun(){ //简单的数据交换模版函数
}


//注意2.推导出的类型T 必须是相同的。
template <typename T> //告诉编译器 T 类型别报错
void fun2(T a,T b){ //简单的数据交换模版函数
    T temp = a;
    a = b;
    b = temp;
}
int main(){
    swap(1,2);
    swap('1','2');

    // fun();//报错。编译器无法推导出模版类型

    //自动推导
    fun2(1,2);//正确
    // fun2(1,'2');//报错。编译器推导出模版类型必须相同，这里有两种：int、char 

    fun2<int>(1,2);//主动类型推导，显示指定类型
}