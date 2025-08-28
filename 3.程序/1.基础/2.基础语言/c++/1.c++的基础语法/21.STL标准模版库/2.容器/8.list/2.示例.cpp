/**
 * list
 * 数据结构： 双链表
 * （java里默认是个数组，link开头是链表结构）
 *
 * 原理：节点（存放值、下个节点地址、上个节点地址。如过地址没有指向，值是null)，连起来就是个单链表
 *
 * 优点：快速插入和删除。
 * 缺点：数据量大访问慢，从头遍历
 *
 */

#include <iostream>
#include <list>
using namespace std;

/**
 * 构造
 */
void list_struct()
{
    list<int> _list;                             // 默认
    list<int> list2(_list);                      // 拷贝构造
    list<int> list3(_list.begin(), _list.end()); //[begin,end)区间数据，构造
    list<int> list4(10, 1);                      // 10个1
}

/**
 * 赋值
 */
void fun()
{
    list<int> _list;
    list<int> _list2;
    list<int> _list3;
    list<int> _list4;
    // =
    _list2 = _list;
    // assign
    _list3.assign(_list.begin(), _list.end()); // 从初始迭代器到尾部迭代器 [begin,end)
    _list4.assign(10, 100);                    // 向_list4 赋值，10个100
}

/**
 * 互换
*/
void swap()
{  
    list<int> _list;
    list<int> _list2;

    _list.swap(_list2);//两个list中的内容完全互换
}

/**
 * 大小
*/
void size()
{  
    list<int> _list;
    _list.size();
    _list.empty();

    _list.resize(1);
    _list.resize(10,1);//重置大小，变长，1填充；变短，移除多余元素
}

/**
 * 插入和删除
*/
void insertAndDelete()
{
     list<int> _list;

    _list.push_back(1);//尾部添加
    _list.pop_back();//尾部删除

    _list.push_front(1);//头部添加
    _list.pop_front();//头部删除

    _list.insert(++_list.begin(),1);//某个位置插入1，返回新数据位置
    _list.insert(++_list.begin(),2,1);//某个位置插入2个1
    _list.insert(++_list.begin(),_list.begin(),_list.end());//某个位置插入,[begin,end)区间数据

    _list.clear();//清空
    
    _list.erase(_list.begin(),_list.end());//移除[begin,end)区间数据，返回下一个数据位置
    _list.erase(_list.begin());//移除某个位置数据，返回下一个数据位置

    _list.remove(3);//移除容器所有 == 3  的元素
}

/**
 * 取数
*/
void query(){
    list<int> _list;
    _list.push_back(1);//尾部添加

    _list.back();//尾部数据
    _list.front();//头部数据

    // _list.begin() + 3;//list迭代器，不支持随机访问，只能双向顺序访问

    // 无法使用  [],at ，因为数据结构不是连续线性的内存空间，同时迭代器不支持随机访问
 }


/**
 * 反转
 * 所有不支持随机访问的迭代器，不可以使用标准算法。所以使用list自带特殊的算法
*/
 void reverse(){
    list<int> _list;
    _list.push_back(1);//尾部添加
    _list.push_back(2);//尾部添加

    _list.reverse();//反转
 }



/**
 * 排序
 * 所有不支持随机访问的迭代器，不可以使用标准算法。所以使用list自带特殊的算法
*/
 void sort(){
      list<int> _list;
    _list.push_back(1);//尾部添加
    _list.push_back(2);//尾部添加

    _list.sort();//排序，默认升序
    _list.sort(myComapre);//降序
 }


 bool myComapre(int v1,int v2){
    //降序 第一个数 > 第二个数
    return v1 > v2;
 }