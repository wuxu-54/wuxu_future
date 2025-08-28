#include <iostream>
#include <fstream>
#include<string>
using namespace std;

int main()
{
    // 1.引入fstream，声明 ifstream 对象
    ifstream ifs;
    // 2.打开文件，需要判断文件是否成功打开
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "open file failed." << endl;
        return 0;
    }
    // 3.读取文件数据。有四种方式

    // 方式1 ifs>> buf
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // { // while循环，将数据读到数组中，当读取完成时，会返回false，结束循环
    //     cout << buf << endl;
    // }

    // 方式2 ifs.getline
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // { // ifs.getline() 获取一行，返回类型是char*。 参数1 接收的数字，参数2 读取的长度
    //     cout << buf << endl;
    // }
    
    //方式3 使用string  , basic中的全局函数 getline
    // string buf;
    // while (getline(ifs,buf))
    // {
    //     cout << buf << endl;
    // }
    
    //方式4(不推荐，效率低), char , 一个一个字符的读，直到 == EOF 
    char c;
    while ((c = ifs.get()) != EOF)//EOF : end of file，表示文件尾
    {
       cout << c;
    }
    

    // 4.关闭文件
    ifs.close();
}