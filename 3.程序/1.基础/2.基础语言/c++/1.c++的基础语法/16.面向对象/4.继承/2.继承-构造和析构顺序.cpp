/**
 * 构造与析构顺序为 ：
 * 
 * 基类构造->子类构造->子类析构->基类析构
 * 
 * （析构与构造 的顺序永远是反向的）
*/
#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout<<"基类构造"<<endl;
    }

    ~Base(){
        cout<<"基类析构"<<endl;
    }
};



class Child:public Base{
    public:
    Child(){
        cout<<"派生类构造"<<endl;
    }

    ~Child(){
        cout<<"派生类析构"<<endl;
    }
};

void test(){
 Child child;
}

int main(){
   test();
   /**
    * 日志输出：
        基类构造
        派生类构造
        派生类析构
        基类析构
   */
} 
