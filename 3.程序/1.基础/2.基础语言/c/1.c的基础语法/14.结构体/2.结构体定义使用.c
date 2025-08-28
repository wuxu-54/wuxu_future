/**
 * 1.结构体无法写完整函数
 * 2.结构体可以声明函数
*/

#include<stdio.h>
#include<stdlib.h>

void study(){
    printf("1234\n");
}

struct Student{
    float score; //4
    short age; //对齐4
    char gender;//4
    void(*study)();//这是个指针，8个字节大小
};

int main(){
    struct  Student stu = {12,99.8f,'f',&study};
    
    stu.age = 13;
    printf("%hd\n",stu.age);

    stu.study();

    //结构体可以有指针
    struct  Student* stuP = &stu;
    stuP->study();
}