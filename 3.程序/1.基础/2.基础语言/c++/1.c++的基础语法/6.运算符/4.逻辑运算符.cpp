#include <iostream>
using namespace std;

/**
 * 逻辑运算符内容简单，不多赘述
 *
 *  逻辑运算符结果返回真或假  非0：真 0：假
 *  
 *  !a  逻辑非    a为假那么!a为真，a为真那么!a为假
 *  a&&b 逻辑与   a、b有一假结果为假；从左到右判断，a为假那么不会判断b直接返回结果
 *  a||b 逻辑或   a、b有一真结果为真；从左到右判断，a为真那么不会判断b直接返回结果
 */

int main()
{
    
    int a = 13;
    int b = 0;

    cout<<!a<<endl;
    cout<<(a&&b)<<endl;
    cout<<(a||b)<<endl;
    
}