/**
 * 冒泡排序
 * 使用指针、数组、函数
 *
 * 1.定义数组
 * 2.指针指向数组首地址
 * 3.获取数组长
 * 4.双层遍历数组
 * 5.函数封装，使用指针参数进行数据交换
 * 6.打印元素
 */
#include <iostream>
using namespace std;

//5.函数封装，使用指针参数进行数据交换
void swap(int *left, int *right)
{
    int temp = *left;
    if (temp > *right)
    {
        *left = *right;
        *right = temp;
    }
    
}

void printArr(int* arr,int length){
      for (int i = 0; i < length; i++){
        cout<<*(arr+i);
     }
     cout<<endl;
}

int main()
{
    // 1.定义数组
    int arr[] = {3, 4, 2, 1, 5, 6, 1};
    // 2.指针指向数组首地址
    int *p = arr;
    // 3.获取数组长
    int length = sizeof(arr) / sizeof(int);
    printArr(p,length);   
    // 4.双层循环
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            swap(p+i,p+j);
        }
    }
    printArr(p,length);   
}