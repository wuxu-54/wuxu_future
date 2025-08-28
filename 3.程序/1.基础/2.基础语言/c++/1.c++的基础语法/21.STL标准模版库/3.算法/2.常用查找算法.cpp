
/**
 * 常用查找算法
 * 1.find(key) 查找对应值的迭代器
 * 2.find_if(谓词) 查找符合条件的迭代器
 * 3.adjacent_find 查找相邻重复元素，返回相邻元素的第一个位置的迭代器
 * 4.binary_search() 查找指定值是否存在，存在true，不存在false
 * 5.count() 统计元素出现次数
 * 6.count_if(谓词) 按条件统计元素次数
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

//-------------------find------------------------

/*
* find 内部是个遍历，但也是查找算法。通过遍历找到对应数据
*/
void _find(){
     vector<int> v;
    initVector(v);

    vector<int>::iterator it =  find(v.begin(),v.end(),4);//查找值为4 的迭代器,如果没找到，返回v.end()
}

//-------------------find_if------------------------

class T{
    bool operator()(int i){
        return i>5;
    }
};
/**
 * 按条件查找
*/
void _find_if(){
     vector<int> v;
    initVector(v);

    vector<int>::iterator it =  find_if(v.begin(),v.end(),T());//按条件查找，谓词T，符号条件就直接返回对应的迭代器
}

//-------------------adjacent_find------------------------

void _adjacent_find(){  
     vector<int> v;
    initVector(v);

    /**
     *  typedef typename iterator_traits<_ForwardIterator>::value_type __v;
     * 上述是源码，意思是告诉编译器，iterator_traits<_ForwardIterator>::value_type __v 类型已经存在，也就是编译时就可以校验了。
    */
   vector<int>::iterator it = adjacent_find(v.begin(),v.end());//返回的是相邻重复元素第一个

}

//-------------------binary_search------------------------
bool myCompare(int key,int item){
    return key == item;
}

void _binary_search(){  
     vector<int> v;
    initVector(v);

   
   /**
    * 源码：__comp(__value_, *__first);
    * 
    * 注意，容器元素必须是有序序列，否则查找会有问题。
   */
  bool cur = binary_search(v.begin(),v.end(),5);//返回是否找到
  bool it = binary_search(v.begin(),v.end(),5,myCompare);

}


//-------------------count------------------------

void _count(){  
     vector<int> v;
    initVector(v);

   int num = count(v.begin(),v.end(),4);//统计4出现的次数

}

//-------------------count_if------------------------

class V{
    bool operator()(int i){
        return i > 3;
    }
};

void _count(){  
    vector<int> v;
    initVector(v);

    int num =count_if(v.begin(),v.end(),V());//统计>3 的值的个数
}