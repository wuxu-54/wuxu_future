/**
 * 属性成员私有化好处
 * 1.设置set get ，控制访问权限。
 * 2.在set、get方法中可以增加数据判断或其他逻辑。
*/

#include<iostream>
using namespace std;

class Test{
    private:
        int a;

    public:
    Test(){};

    int getA(){
        return a;
    }

    void setA(int value){
        a = value;
    }
};

int main(){
    Test test = Test();
}