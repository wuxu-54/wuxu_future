#include <iostream>
#include <string>
using namespace std;

/**
 * string 是个类，其是个容器，内部管理了char*
 */
int main()
{
    // 构造函数
    string s = string(1, '1'); // n个字符 1
    string s1 = string("11");  // char*
    string s2 = string();      // 空字符
    string s3 = string(s);     // 另一个string作为构造参数

    // 赋值 string类重载了操作符 = 。内部是assign
    s = "11";
    s.assign("111");

    // 拼接
    s += "11";
    s.append("111");
    s.append("0123", 1, 2); // 拼接字符串0123， 从位置1开始 2个字符数据。

    // string查找
    s.find("a", 1);  // 从位置1开始查找到第一次出现 字符a
    s.rfind("b", 2); // 倒序 从位置2查找，b出现的位置

    // string 替换
    s.replace(1, 2, "012345"); // 位置1 ，2个字符数据，替换为新的字符串

    // 字符串比较
    int result = s.compare(s1); // 按字符ASCII码，从左到右逐一比较 ，返回 -1 0 1

    // string 每个字符的存取
    char c = s[1]; // 取，底层通过指针获取
    s[1] = '2';    // 存

    s.at(1); // 取 同上
    s.at(1) = '3'; // 存

    //插入
    s.insert(1,"11");//位置1插入

    //删除
    s.erase(1,3);//从1开始 删除3个字符

    //截取
    string newstring =  s.substr(2,3);//从2开始，截取3个字符,返回一个新字符串
}