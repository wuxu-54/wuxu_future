/**
 * 常用集合算法
 * 1.set_intersection 求俩容器交集
 * 2.set_union 求俩容器并集
 * 3.set_difference 求俩容器差集
 *  差集，需要明确谁和谁的差集。
 *          A、B  A和B的差集，就是在A容器内取B中没有的元素，
 *                B和A的差集，就是在B容器内取A中没有的元素

 *
 * 注意，使用集合算法，容器元素需要是有序的序列
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

//-----------set_inersection----------------
void _set_intersection()
{
    vector<int> v;
    initVector(v);

    vector<int> v2;
    initVector(v2);

    vector<int> targetV;
    // 取交集，那么size取两个容器最小值
    targetV.resize(min(v.size(), v2.size()));

    vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), targetV.begin()); // 返回交集的最后一个迭代器
}

//-----------set_union----------------
void _set_union()
{
    vector<int> v;
    initVector(v);

    vector<int> v2;
    initVector(v2);

    vector<int> targetV;
    // 取并集，那么size取两个容器大小之和
    targetV.resize(v.size() + v2.size());

    vector<int>::iterator itEnd = set_union(v.begin(), v.end(), v2.begin(), v2.end(), targetV.begin()); // 返回并集的最后一个迭代器
}

//-----------set_difference----------------
void _set_difference()
{
    vector<int> v;
    initVector(v);

    vector<int> v2;
    initVector(v2);

    vector<int> targetV;
    // 取v与v2的差集，那么size=v的大小
    targetV.resize(v.size());

    vector<int>::iterator itEnd = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), targetV.begin()); // 取v容器数据与 v2对比，获取v容器中元素不在v2内的元素集合

    vector<int> targetV2;
    // 取v2比较v的差集，那么size=v2的大小
    targetV2.resize(v2.size());

    vector<int>::iterator itEnd2 = set_difference(v2.begin(), v2.end(), v.begin(), v.end(), targetV.begin()); // 取v2容器数据与 v对比，获取v2容器中元素不在v内的元素集合
}