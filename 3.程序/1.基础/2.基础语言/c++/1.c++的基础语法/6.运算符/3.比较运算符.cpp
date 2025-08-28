#include <iostream>
using namespace std;

/**
 * 比较运算符内容简单，不多赘述
 *
 *  比较运算符结果返回真或假  1真 0假
 * ==  相等于
 * !=  不等于
 * <  小于
 * >  大于
 * <=  小于或等于
 * >=  大于或等于
 * 
 * 实际使用不支持像java 1<a<2 写法，必须1<a && a<2。        -2024.7.12记
 */

int main()
{
    int a = 13, b = 10;

    
    cout<<(a==b)<<endl;//符号优先级，所以a==b 需要括号
    cout<<(a>b)<<endl;//符号优先级，所以a==b 需要括号
    cout<<(a<b)<<endl;//符号优先级，所以a==b 需要括号
    cout<<(a>=b)<<endl;//符号优先级，所以a==b 需要括号
    cout<<(a<=b)<<endl;//符号优先级，所以a==b 需要括号
    
}