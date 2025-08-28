/**
 * 常用排序算法
 * 1.sort  将容器数据有序排列
 * 2.random_shuffle  打乱容器元素，随机排列
 * 3.merge  合并两个容器元素，返回新容器
 * 4.reverse 将容器数据反向
 *
 * 注意，所有不支持随机访问的容器，不能使用标准排序算法。得用其自己的。
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void initVector(vector<int> &vector)
{
    for (int i = 0; i < 10; i++)
    {
        vector.push_back(i);
    }
}

//-------------sort----------------
bool _compare(int pre, int next)
{
    // true 降序
    return pre > next;
}
void _sort()
{
    vector<int> v;
    initVector(v);

    sort(v.begin(), v.end(), _compare);
}

//-------random_shuffle---------------
_LIBCPP_DEPRECATED_IN_CXX14
void _random_shuffle()
{
    vector<int> v;
    initVector(v);

    // random_shuffle(v.begin(),v.end());//_LIBCPP_DEPRECATED_IN_CXX14,c++14以上版本无法使用了
}

//-----------merge---------------
void _merge()
{
    vector<int> v;
    initVector(v);
    vector<int> v2;
    initVector(v2);

    vector<int> newV;
    //需要给newV分配空间
    newV.resize(v.size()+v2.size());

    merge(v.begin(), v.end(), v2.begin(), v2.end(), newV.begin());
}

//-----------reverse---------------
void _reverse()
{
    vector<int> v;
    initVector(v);
    reverse(v.begin(),v.end());//反转[begin,end) 区间内容
}