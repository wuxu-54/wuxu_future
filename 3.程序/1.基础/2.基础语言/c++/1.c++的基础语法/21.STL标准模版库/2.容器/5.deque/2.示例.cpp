/**
 * deque
 * 双端数组， 头尾都有开口
 * 
 * 原理：内部设置了中控器，中控器存的值指向 真正存放数据的内存地址
 * 
 * 使用和vector类似，新增了头端api
 * 
 * 与vector区别
 * 1.双端数组， 头尾都有开口
 * 2.内部结构不同，有中控器指向内存地址，可以无限增加数据
 * 3.数据结构不同，所以没有容量
 * 4.
 */
#include<iostream>
#include<deque>
#include<algorithm>//引入算法，排序用
using namespace std;


/**
 * 新增数据
*/
deque<int> add(){
//   deque<int>dl(1,2); 构造 n个 element
//  deque<int> d2(dl.begin(),dl.end());构造 从旧dl中的迭代器拷贝  [begin,end)
//  deque<int> d2(dl);拷贝构造

    //默认构造
    deque<int>dl;

    for(int i = 0;i<100;i++){
        dl.push_back(i);//尾部添加
    }

    dl.push_front(1);//头部添加

    return dl;
}

/**
 * 访问
*/
void print(const deque<int> &dl){//dl设置为常对象，只读
    for(deque<int>::const_iterator it = dl.begin();it!=dl.end();it++){
        cout<<*it<<endl;
    }

   int i= dl.at(1);//返回1位置
   dl[1];//等同于at(1)

  int start= dl.front();//返回头端数据
  int end = dl.back();//返回尾端数据
}

/**
 * 赋值，与vector一样
 * =  assign
*/
void fun(){
     deque<int>d(2,2); 
    deque<int>dl(3,2); 

    dl = d;
    dl.assign(2,6);//2个6赋值给dl
    dl.assign(d.begin(),d.end());//把d从begin到end赋值给dl
}


/**
 * 大小
 * 没有容量概念，所以没有容量的api，其他与vector相同
*/
void size(){
     deque<int>d(2,2); 
     int size =d.size();
     d.resize(10);//重置大小为10
     d.resize(10,3);//重置大小为10，变长其余部分用3代替，变短删除多余数据

     bool isEmpty = d.empty();//判断是否为空
}

/**
 * 插入和删除
 * 与vector相同，只是增加头端操作
*/
void insertAndDelete(){
    deque<int>dl(2,2); 
    //插入
    dl.push_back(0);//尾部添加
    dl.push_front(1);//头部添加
    
    int index = 1;
    // dl.insert(1,1);//向index位置插入，返回新数据的位置
    // dl.insert(index,10,2);//向index位置插入 10个2 ，无返回值
   // dl.insert(index,begin,end);//向index位置插入 [begin,end)区间数据，无返回值

    //删除
    dl.pop_back();//尾部
    dl.pop_front();//头部
    //dl.erase(begin,end) 删除[begin,end)区间数据，返回下一个数据位置
    //dl.erase(pos) 删除pos位置数据，返回下一个数据位置

    dl.clear();//清空
}

/**
 * 排序
*/
void sort_1(){
    deque<int>dl(2,2); 
    sort(dl.begin(),dl.end());//默认升序
}
int main(){
   deque<int> d = add();
   print(d);
}