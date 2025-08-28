#include<iostream>
using namespace std;


struct Name{
    int a = 1;
};

void fun(struct Name name){
    cout<<name.a<<endl;
}

/*
*当数据在栈中时，变量传入时，会复制一份，这样浪费内存，可以使用指针.
* 为防止数据被乱改，可以使用 常量的指针，const定义。
*/

void fun1(const struct Name *name){
    // name->a = 1;//这里会报错，因为是指向常量的指针，name是常量，所以无法修改其内部值
    cout<<name->a<<endl;
}
int main(){
    struct Name name ={2};
    fun(name);
}