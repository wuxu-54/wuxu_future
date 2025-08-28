#include <iostream>
using namespace std;

/**
 * 赋值运算符内容简单，不多赘述
 *
 * =  赋值
 * +=  加等于
 * -=  减等于
 * *=  乘等于
 * /=  除等于
 * %=  摸等于
 */

int main()
{
    // =
    int a = 13, b = 10;

    a += 3;
    cout << a << endl;
    a -= 3;
    cout << a << endl;
    a *= 3;
    cout << a << endl;
    a /= 3;
    cout << a << endl;
    a %= 3;

    cout << a << endl;
}