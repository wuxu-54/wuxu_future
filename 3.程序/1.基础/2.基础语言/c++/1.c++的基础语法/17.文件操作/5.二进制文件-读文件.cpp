
/**
 * 读文件
 * 函数原型：ostream& read(const char * buffer,int len);
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
    //1.引入fstream ，声明ifstream对象
    ifstream ifs;
    //2.打开文件,并判断是否打开成功
    ifs.open("person.txt",ios::binary | ios::in);
    if(!ifs.is_open()){
        cout<<"open failed"<<endl;
        return 0;
    }
    //3.读取文件数据
    Person person;
    ifs.read((char*)&person,sizeof(person));

    cout<<"name:"<<person.m_name<<",age:"<<person.m_Age<<endl;

    //4.关闭文件
    ifs.close();

}