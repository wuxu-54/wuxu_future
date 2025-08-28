/**
 * 需求：++ 自增
 * 
 * 这个案例，目的不是学习操作符重载，目的是突出使用引用的重要性。
 * 
 * 核心：使用引用作为返回值，可以避免数据不同步问题。
 * 例如：自定义类，自增函数返回非引用， 其实与外部对象不是同一个而是新的对象。导致数据不同步。这里概念很笼统，看下面代码实例注释，可以明确我要表达什么。
 * 
 * 
 * 前置：operator++()
 * 后置: operator++(int)  ,比前置多个占位参数int 表示后置
*/

#include <iostream>

using namespace std;

class MyInteger{
    friend ostream& operator<<(ostream& cout,MyInteger myInt);
    private:
    int num;

    public:
    MyInteger(int a):num(a){}
    /**
     * 这里返回值如果是 【MyInteger &】 那么指向原对象
     * 
     * 
     * 2.如果是【MyInteger】 那么返回是新建的对象。
         打印日志:
            打印this地址：0x7ffeefbff2a8
            打印this地址：0x7ffeefbff298
            2
            1
        日志可以看出，两次this指针打印的地址不同，说明不是一个对象
    */
    MyInteger operator++(){//这是前置++
        cout<<"打印this地址："<<this<<endl;//打印地址
        this->num++;
        return  *this;
    }
    //返回引用，保证操作对象不变
    // MyInteger& operator++(){
    //     this->num++;
    //     return  *this;
    // }


    //后置递增,要先建立新对象，这就得返回值了，不能是引用，因为局部变量引用不可以作为返回值
    MyInteger operator++(int){//这是后置++
        MyInteger temp = *this;
        this->num++;
        return  temp;
    }
};

ostream& operator<<(ostream& cout1,MyInteger myInt){
     cout1 << myInt.num << endl;
    return cout1;
}


void printProblem(){
    MyInteger myInt = MyInteger(0);
    /**
     * 这里如果 operator++ 返回的不是引用，而是MyInteger类型，第二次++,与局部变量myInt 对不起来了，这就是我上面说的问题：俩次++操作的对象不是同一个了
     * 
     * 第一次操作的是 myInt
     * 第二次操作的是 函数返回的新myInt
     */
    cout<<++(++myInt);
    cout<<myInt;
    // cout<<myInt;
}
int main(){
    // int a = 0;
    // cout << ++(++a)<<endl;//这里操作的始终是局部变量 a 
    // cout <<a<<endl;
    printProblem();
    return 0;
}
