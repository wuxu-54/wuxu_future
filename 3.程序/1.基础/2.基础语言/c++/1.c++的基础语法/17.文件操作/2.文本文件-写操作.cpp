#include<iostream>
#include<fstream>
using namespace std;

int main(){
    //1.引入fstream，声明 ofstream 类型对象
    ofstream ofs;
    //2.open 打开文件，如果文件不存在会创建一个，并设定打开方式
    ofs.open("test.txt",ios::out);
    //3.向文件写数据
    ofs<<"写入数据";
    //4.关闭文件
    ofs.close();
}