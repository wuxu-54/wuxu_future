/**
 * map/multimap
 * 数据结构：二叉树。  元素都是pair，其中first是key，second是value
 * 
 * 特点：
 *  1.自动排序，与set一样。
 *  2.通过key可以快速找到value值
 * 
 * map与multimap区别
 * 1.map中key不可以重复，multimap可以重复
*/
#include <iostream>
#include <map>
using namespace std;

/**
 * 构造和赋值
*/
void map_struct(){
    map<int ,char> _map;//默认构造
    map<int ,char> _map2;//默认构造
    _map2 = _map;// = 赋值

    map<int ,char> _map3(_map);//拷贝构造
}


/**
 * 大小、交换
*/
void map_struct(){
    map<int ,char> _map;//默认构造
    map<int ,char> _map2;

    _map.empty();
    _map.size();
    _map.swap(_map2);
}


/**
 * 插入数据
 * 与set一样
 */
void insert()
{
    map<int,int> s1;
    s1.insert(pair<int,int>(1,1)); // 只有这一种方式
}

/**
 * 删除数据
 * 与set一样
 */
void deleteV()
{
    map<int,int> s1;
    s1.erase(s1.begin());           // 删除某个位置的数据
    s1.erase(s1.begin(), s1.end()); //[begin,end) 区间数据删除

    s1.erase(2); // 删除所有key是 2 的元素

    s1.clear(); // 清空
}


/**
 * 查找、统计
 */
void query()
{
    map<int,int> s1;
    map<int,int>::iterator curr = s1.find(1); // 查找key == 1，是否存在，存在就返回迭代器，不存在返回set.end();
    int count = s1.count(1);              // 统计key == 1 个数

    int value = s1.at(1);//获取key==1的值,set没有这个
    int value2 = s1[1];// 等同于at,set没有这个
}


/**
 * 排序
 * 
 * map与set一样
*/
class MyCompare
{
    public:
    //比较的是map 的key值
    bool operator()(int v1,int v2)
    {
        //设置降序
        return v1 > v2;
    }
};
void sort(){
    //使用仿函数，放入map对象的模版参数列表中
    map<int,int,MyCompare> s1;
    s1.insert(make_pair(1,1));
    s1.insert(make_pair(5,1));
    s1.insert(make_pair(3,1));
    s1.insert(make_pair(4,1));

    for(map<int,int,MyCompare>::iterator it=s1.begin();it!=s1.end();it++){
        cout<<(*it).first<<"|"<<it->second<<endl;
    }
}