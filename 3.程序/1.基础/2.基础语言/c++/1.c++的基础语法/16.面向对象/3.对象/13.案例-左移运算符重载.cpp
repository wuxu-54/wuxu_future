/**
 * 需求：实现 cout<<类P； 快速输出其属性
 * 
 * 注意，此需求是cout在左，所以无法用P类内进行成员函数操作符重载
*/

#include <iostream>

using namespace std;

 //cout << p; 先天导致无法使用 成员函数操作符重载
class P{
    public:
    int c ;
    P(int a,int b):a(a),b(b){
        c= 9;
    }

    private:
    int a;
    int b;

    friend ostream & operator<<(ostream &cout1,P &p);
   
};



/**
 * 只能用全局函数操作符重载实现需求
 * 
 * cout 是 ostream 类型
 * 
 * return ostream &  可以链式调用 cout<< p << p1 <<p2
*/
ostream & operator<<(ostream &cout1,P &p){
    cout1<<"a = "<< p.a <<",b = "<<p.b<<endl;
    return cout1;
}



int main(){
 
    P p = P(1,2);
    P p1 = P(2,4);
    P p2 = P(3,5);
    
    cout << p << p1 << p2;


    P p4(1,2);
    cout << p4;
}

