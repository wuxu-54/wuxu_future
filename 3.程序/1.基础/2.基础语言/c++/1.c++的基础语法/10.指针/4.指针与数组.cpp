/**
 * c++中指针与数组 和 c语言没有区别，可以看上面c基础语法中的【指针与数组关系】
 * 
 * 这里我再复习下
 * 1.数组内存地址是连续的
 * 2.指针可持有数组元素的指针，通过+1或-1方式得到当前元素相邻的数组元素内存地址
*/
#include <iostream>
using namespace std;

int main(){
    //定义一个数组
    char str[] = "adfbnadf";
    //指针取数组首地址
    char *p = str;
    //获取数组长
    int length = sizeof(str) / sizeof(char) - 1;//char [] 表示字符串时，末尾会自动补 \0，所以长度要-1
    //通过指针遍历数组
    for (int i = 0; i < length; i++)
    {
       char *currP = (p + i);
       cout<<"当前数组元素是："<< *currP<<",当前数组元素地址是："<<currP<<endl;
    }
    
}