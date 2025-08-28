/**
 * queue容器
 * 数据结构: 先进先出
*/
#include <iostream>
#include <queue>
using namespace std;

/**
 * 构造
*/
void fun(){
    queue<int> que;//默认
    queue<int> a(que);//拷贝构造
}

/**
 * 赋值
 */ 
void fun1(){
     queue<int> que;
      queue<int> que2 = que;
}

/**
 * 数据存取
*/
void fun2(){
    queue<int> que;

    que.push(1);//队尾插入
    que.pop();//队头移除，先进先出，所以从头移除，从尾插入

    int i = que.back();//返回队列最后一个元素
    int j = que.front();//返回队列第一个元素
}

/**
 * 大小
*/
void fun2(){
    queue<int> que;

    que.empty();//是否为空
    que.size();//队列长度

}