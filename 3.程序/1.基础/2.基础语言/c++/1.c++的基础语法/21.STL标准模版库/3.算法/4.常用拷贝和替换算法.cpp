/**
 * 常用拷贝算法
 * 1.copy  将容器数据拷贝到新容器中
 *
 * 常用替换算法
 * 1.replace
 * 2.replace_if
 * 3.swap
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

//-------------copy----------------

void _copy()
{
    vector<int> v;
    initVector(v);

    vector<int> targetV;

    targetV.resize(v.size()); // 分配空间

    copy(v.begin(), v.end(), targetV.begin());
}

//-------replace---------------

void _replace()
{
    vector<int> v;
    initVector(v);

    replace(v.begin(), v.end(), 5, 9); // 将元素 5 全部替换为 9
}

//-----------replace_if---------------
class T
{
    bool operator()(int i)
    {
        return i == 3;
    }
};
void _replace_if()
{
    vector<int> v;
    initVector(v);

    replace_if(v.begin(), v.end(), T(), 9); // 将符合谓词的所有元素，替换为9
}

//-----------swap---------------
void _swap()
{
     vector<int> v;
    initVector(v);
     vector<int> v2;
    initVector(v2);

    // v.swap(v2);//vector 是互换容器，可以用于缩小size
    swap(v,v2);//每个容器都不一样，各自有实现模版重载,这里内部实现是 v.swap(v2);
}