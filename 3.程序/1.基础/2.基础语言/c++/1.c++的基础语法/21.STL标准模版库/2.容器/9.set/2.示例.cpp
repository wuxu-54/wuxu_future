/**
 * set、multiset集合容器
 * 数据结构：二叉树
 *
 * 特点：元素会在插入时自动升序排序（关联式容器）
 *
 * set 和 multiset区别
 *  * set不允许重复元素，multiset可以重复元素。其他都一样
 *  * set插入时会返回结果，表示是否成功。 multiset不会返回。
 */
#include <iostream>
#include <set>
using namespace std;

/**
 * 构造、赋值
 */
void fun()
{
    set<int> s1;
    set<int> s2(s1); // 拷贝构造

    set<int> s3 = s1; // = 操作符赋值
}

/**
 * 插入数据
 */
void insert()
{
    set<int> s1;
    s1.insert(1); // 只有这一种方式
}

/**
 * 删除数据
 */
void deleteV()
{
    set<int> s1;
    s1.erase(s1.begin());           // 删除某个位置的数据
    s1.erase(s1.begin(), s1.end()); //[begin,end) 区间数据删除

    s1.erase(2); // 删除所有是 2 的元素

    s1.clear(); // 清空
}

/**
 * 大小、交换
 */

void size()
{
    set<int> s1;
    s1.size();
    s1.empty();

    set<int> s2;
    s1.swap(s2); // 交换
}

/**
 * 查找、统计
 */
void query()
{
    set<int> s1;
    set<int>::iterator curr = s1.find(1); // 查找key == 1，是否存在，存在就返回迭代器，不存在返回set.end();
    int count = s1.count(1);              // 统计key == 1 个数
}

/**
 * 排序
 * 
 * set默认是升序，如果要改变规则，需要用仿函数设置
 * 自定义数据类型，必须指定排序规则，否则二叉树结构无法实现自动排序
*/
class MyCompare
{
    public:
    bool operator()(int v1,int v2)
    {
        return v1 > v2;
    }
};
void sort(){
    //使用仿函数，放入set对象的模版参数列表中
    set<int,MyCompare> s1;
}