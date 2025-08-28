/**
 * 类中对象变量的初始化顺序
 * 
 * 构造：类中对象成员先初始化，然后类初始化
 * 析构：与构造相反顺序，类先析构，其对象成员再析构
 * 
*/
#include<iostream>
using namespace std;

class Phone{
    int p;
    public: Phone(int p):p(p){
        cout<<"Phone init"<<endl;
    }
    ~Phone(){
        cout<<"Phone release"<<endl;
    }
};

class T{
    public:
    int a;
    Phone b;

    
    //显示构造 ： Phone b = intB; 相当于 Phone b = Phone(intB); 直接对变量b进行初始化
    T(int a,int intB):a(a),b(intB){
        cout<<"T init"<<endl;
    }

    //这里会报错，提示：类 "Phone" 不存在默认构造函数，也就是全局变量b必须优先T初始化
    // 因为隐式的 Phone b; 会调用默认构造函数，而Phone没有默认构造函数

    // T(int a,int intB){
    //     this->a = a;
    //     b=Phone(intB);
    //     cout<<"T init"<<endl;
    // }

    ~T(){
           cout<<"T release"<<endl;
    }
};

int main(){
    T t(12,144);
}