
/**
 * 空指针可以访问成员函数，但是前提是成员函数没有对象的使用
*/
#include<iostream>
using namespace std;

class P{
    public :
    int a=1;
    void fun(){
        cout<<"123"<<endl;
    }

    void fun2(){
        cout << "111"<<a<<endl;//a 等于 this->a
    }
};

int main(){
    P *p = NULL;
    p->fun();//正常运行！因为此方法虽然是空指针调用，但其没有使用this,也就是没使用具体对象
    p->fun2();//报错，因为方法访问对象属性，但调用是空指针，不指向真正的对象。所以会报错
}