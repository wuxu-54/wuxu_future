#include <iostream>
using namespace std;

/**
 *
 * switch(n){
 * case 1: break;
 * case 2: break;
 * case 3:
 * case 4: break;
 * default: break;
 * }
 *
 * switch 与if else差不多，都是通过判断是否符合条件，选择进行内容调用
 * 区别：switch 是判断的 【值】 是否符合条件（相等），然后进入某个流程。而if是判断表达式结果
 *
 * break: 退出当前流程语句
 * continue：继续执行当前流程语句
 * return： 结束整个函数
 * goto ： 回到某个流程位置
 *
 */
int main()
{
    int a = 5;
    int b = 1;

    if (a > 10)
    {
        cout << "进入a if内" << endl;
    }
    else if (a < 4)
    {
        cout << "进入a else-if内" << endl;
    }
    else
    {
        cout << "进入a else内" << endl;
        // 嵌套if-else
        if (b)
        {
            cout << "进入b if内" << endl;
        }
        else
        {
            cout << "进入b else内" << endl;
        }
    }

    switch (a)
    {
    case 1:
        cout << "进入 case a==1" << endl;
        break;
    case 2:
        cout << "进入 case a==2" << endl;
        break;
    case 5:
        cout << "进入 case a==5" << endl;
        break;
    default:
        cout << "以上条件都不符合，进入默认流程" << endl;
        break;
    }
}