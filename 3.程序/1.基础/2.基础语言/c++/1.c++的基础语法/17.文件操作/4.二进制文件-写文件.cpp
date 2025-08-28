
/**
 * 二进制文件读写，文件打开模式必须是 ios::binary
 * 
 * 写文件
 * 函数原型：ostream& write(const char * buffer,int len);
 * 参数解释：字符指针buffer 指向内存中的一段存储空间，len是读写的字节数
*/

#include <iostream>
#include<fstream>
using namespace std;

class Person{
    public:
    char m_name[64];//二进制文件最好不用string 容易有问题
    int m_Age;
};

int main(){
    //1.引入fstream ，创建流对象
    ofstream ofs("person.txt",ios::binary | ios::out);//打开方式可以使用 | 进行运算，同时具有多种模式：二进制+写文件;

    //2.open 文件
    // ofs.open("person.txt",ios::binary|ios::out);// 可以省略此步骤，在创建流对象时通过构造函数把open操作直接两步并一步

    //3.写文件
    Person person = {"zhangsan",123};
    ofs.write((const char *)&person,sizeof(person));//写到文件中，会有写乱码，是二进制问题，不影响读

    //4.关闭文件
    ofs.close();
}