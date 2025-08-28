#include<iostream>

using namespace std;

/**
 * 数组：与c一样
 * 一段连续的内存地址；(这就意味着可以用【指针++】的方式来获取数据)
 * 
 * 1. 如何声明数组 : int a[]；
 * 2. 如何获取数组元素:一维数组 a[0];
 * 3. 数组的指针: int* point = a 或 int* point = &a[0]
 * 4. 如何使用数组: 先取再用
*/
int main(){
    //1 如何声明数组

    //方式1
    int a[] = {1,3};
    //方式2 先声明长度的数组，然后再向里面写入值
    int b[10];
    for (int i = 0; i < 10; i++)
    {
       b[i] = i;
    }
    
    //2.如何获取数组元素
    cout<<"这是数组第一个数："<< a[0]<<endl;


    //3.数组的指针
    //数组默认地址是其首元素的内存地址，所以可以直接赋值给指针，这个指针既可以是首元素的地址也可是数组的地址
    int* arrPoint = a;
    int* arrPoint2 = &a[0];


    //4.如何使用数组

    //获取数组长度
    cout<<"数组长度是："<<(sizeof(a)/sizeof(int))<<endl;

    //遍历数组
    //方式1 直接遍历
     for (int i = 0; i < 10; i++)
    {
       cout<<"数组b元素: "<<b[i]<<endl;
    }
    //方式2 指针
     int* bPoint = a;
     for (int i = 0; i < 10; i++)
    {
       cout<<"数组b元素: "<< *(bPoint+i) <<endl;//(bPoint+i)是元素地址
    }    
}