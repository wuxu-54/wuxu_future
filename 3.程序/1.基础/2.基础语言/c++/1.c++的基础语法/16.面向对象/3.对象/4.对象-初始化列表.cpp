/**
 * C++ 类变量初始化的独特方式
*/

#include<iostream>
using namespace std;

class T{
    public:
    int a;
    int b;
    int c;
    /*传统初始化方式*/
    // T(int a,int b,int c){}

    /*C++ 独特的方式（显示构造）,对比上方，比较灵活*/
    // T():a(10),b(1),c(2){}
    T(int a,int b,int c):a(a),b(b),c(c){}
};

int main(){
    
}


/**
 补充说明：
 传统初始化方式，构造函数的编译在各个变量默认构造执行之后，
 而“显示构造” 是显示的对各个变量进行构造处理，这样就不会有下一章节里Phone默认构造报错的问题
 */