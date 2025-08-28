/**
 * pair 对组，成对的数据 
 * 
 * 用途：返回两个数据
*/
#include <iostream>
using namespace std;

void fun(){
    //构造
    pair<int ,float> _pair(1,1.4f);
    //api
    pair<int ,char> _pair2 = make_pair(1,'1');

    //使用
    cout<<_pair.first<<",2:"<<_pair.second<<endl;
}
