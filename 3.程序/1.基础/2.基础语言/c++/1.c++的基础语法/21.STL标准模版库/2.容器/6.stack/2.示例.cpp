/**
 * stack
 * 数据结构：栈结构，先进后出
 *
 */

#include <iostream>
#include <stack>
using namespace std;

/**
 * 构造
 */
void stack_struct()
{
    stack<int> _stack;          // 默认
    stack<int> _stack2(_stack); // 拷贝构造
}

/**
 * 赋值  =
 */
void fun()
{
    stack<int> _stack; // 默认
    stack<int> _stack2;
    _stack2 = _stack;
}

/**
 * 存取
 */
void fun()
{
    stack<int> _stack;
    _stack.push(1); // 入栈
    _stack.top();   // 获取栈顶元素
    _stack.pop();   // 移除栈顶元素
}


/**
 * 大小
*/
void size(){
    stack<int> _stack;
    _stack.push(1);

  bool isEmpty =  _stack.empty();//是否为空
  _stack.size();//元素个数
}
int main()
{
}