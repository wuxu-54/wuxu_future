/**
 * 常用遍历算法
 * 1.for_each 循环遍历，期间可以执行对应方法进行逻辑运算
 * 2.transform 搬运容器数据到另一个容器中，期间可以执行对应方法进行逻辑运算
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void initVector( vector<int> &vector){
    for(int i=0;i<10;i++){
        vector.push_back(i);
    }

}

//-----------------for_each--------------------------

void fun(int i){
    cout<<i<<endl;
}

//仿函数
class T{
   void operator()(int i){
         cout<<i<<endl;
    }
};

void forEach(){
    vector<int> v;
    initVector(v);

    //传入普通函数，只需要函数名(函数名是个指针)
    for_each(v.begin(),v.end(),fun);

    //传入仿函数,必须有括号
    for_each(v.begin(),v.end(),T());
}

//-----------------transform--------------------------

float funTransformItem(int v){
    return (float)v;
}

void transform(){
    vector<int> v;
    initVector(v);

    vector<float> v2;

    /* 
    * class _InputIterator, class _OutputIterator; 传入的是 vector<int>，输出的是 vector<float>
    *
    * funTransformItem ： *__result = __op(*__first);所以返回值是v2的float类型，形参类型是v的int类型
    */
   vector<float>::iterator it=  transform(v.begin(),v.end(),v2.begin(),funTransformItem);//返回迭代器v2最后一个迭代器

}
