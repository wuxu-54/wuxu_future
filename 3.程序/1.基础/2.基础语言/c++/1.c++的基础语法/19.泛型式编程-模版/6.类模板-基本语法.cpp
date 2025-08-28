/**
 * 在不知道具体类型时，设定模版
 * 
 * 与函数模版区别
 * 1.不支持自动类型推导，必须显示指定类型
 * 2.类模版参数列表可以有默认值，函数模版不允许
*/

#include<iostream>
using namespace std;
#include<string>

//不知道name、age两个变量的具体参数，就指定了模版类型, 类模板可以指定默认参数 如ageType = int，默认int类型
template<class nameType,class ageType = int>
class Person{
 public:
    Person(nameType name,ageType age):name(name),age(age){}
    nameType name;
    ageType age;
};

void showCase(){
    // Person<string,int> p("111",12);
    Person p("1",2);//报错，不支持自动类型推导
    cout<<"name:"<<p.name<<",age:"<<p.age<<endl;
}

int main(){
    showCase();
}