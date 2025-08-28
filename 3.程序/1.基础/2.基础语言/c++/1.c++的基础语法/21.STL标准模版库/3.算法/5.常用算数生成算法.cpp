/**
 * 常用算数生成算法
 * 小型算法，体积小，只进行简单的数学运算。
 * 
 * 引用numeric
 * 
 * 1.accumulate 计算元素个数
 * 2.fill 向容器区间填充新的内容
*/

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void initVector(vector<int> &vector)
{
    for (int i = 0; i < 10; i++)
    {
        vector.push_back(i);
    }
}

//-------------accumulate----------------
void _accumulate(){
    vector<int> v;
    initVector(v);

   int num= accumulate(v.begin(),v.end(),0);//最后参数是起始数值。在起始值基础上统计元素个数
}

//-------------fill----------------
void _accumulate(){
    vector<int> v;
    initVector(v);

    fill(v.begin(),v.end(),19);//向[begin,end)区间填充新内容 19
}
