/**
 * vector  数据结构与数组相似，又称单端数组
 * 
 *  与数组区别：数组不可扩展，vector可以扩展
 * 
 * vector扩容原理：新开劈内存空间，将原数据拷贝到新数据，释放原空间
*/
#include<iostream>
#include<vector>
using namespace std;

class Person{
    public:
    int i;
    int j;
};


/**
 * 赋值
*/
void fun(){
    vector<int> v;
    v.push_back(0);
    v.push_back(1);

    vector<int> v2;
    // = 
    v2 = v;
    // assign

    vector<int> v3;
    v3.assign(v.begin(),v.end());//从初始迭代器到尾部迭代器

    vector<int> v4;
    v4.assign(10,100);//向v4 赋值，10个100
}

/**
 * 容量大小
*/
void fun(){
        vector<int> v;
    v.push_back(0);
    v.push_back(1);
    if(v.empty()){
        cout<<"v == empty"<<endl;
    }else{
        cout<<"v != empty"<<endl;
    }

    v.capacity();//容量，可以扩容的 >= size
    v.size();//真实大小

    v.resize(14,1);//重指定size为14，如果比原来长，用1填充；如果比原来短，移除旧的超出部分

}

/**
 * 插入、删除
 * vector是单端数组，头部插入会将所有数据移动。数据量越大效率越低
*/
void fun(){
    vector<int> v;
    v.push_back(1);//尾部插入
    v.pop_back();//尾部移除

    v.insert(v.end(),4);//向迭代器位置插入元素4
    v.insert(v.begin(),10,4);//向迭代器位置插入 10个元素4

    v.erase(v.end());//移除迭代器指向的元素
    v.erase(v.begin(),v.end());//移除从begin()迭代器 到 end()迭代器之间全部元素

    v.clear();//全部删除
}


/**
 * 数据存取
*/
void fun(){
    vector<int> v;
    v.push_back(1);

    int a =v.front();//首位
    int b = v.back();//末尾

    int c =v.at(0);
    int d =v[0];
}

/**
 * 互换容器
*/
void fun(){
     vector<int> v;
    v.push_back(1);

     vector<int> v1;
    v1.push_back(1);

    v.swap(v1);//互换元素，可以用于收缩容器容量。因为resize时容量不会变小，可以使用swap

    //用途！
    vector<int>(v).swap(v);//vector<int>(v) 拷贝构造，是个新对象，此时容量大小跟size相同。 swap方法是容器互换。这样v的容量就变为最小，减少内存浪费。
}


/*
* 预留空间
* 可以减少扩容次数，从而避免多次数据拷贝
*/
void fun(){
     vector<int> v;
    v.push_back(1);
    v.reserve(11);//预留11个内存地址空间，这段空间不会有任何初始化，且无法访问，resiz会有默认数值0
}

int main(){
    //创建vector 数组
    vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.pop_back();//移除3 


    //通过迭代器进行数据循环遍历
    //v.end() 结束迭代器，指向容器最后一个元素的后面的位置。 v.begin()起始迭代器，指向容器第一个元素位置。
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<"value = "<< *it <<endl;//迭代器访问  *it类似指针，解引用，其类型就是<>中的类型
    }


    vector<Person> vP;
    vP.push_back(Person());

    //v.end() 结束迭代器，没有具体数，指向容器最后一个元素的后面的位置
      for(vector<Person>::iterator it=vP.begin();it!=v.end();it++){
        cout<<"i = "<< (*it).i <<endl;//*it 就是Person对象
    }

    //清空
    v.clear();


}