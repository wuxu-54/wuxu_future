/**
 * 1.结构体无法写完整函数
 * 2.结构体可以声明函数
 * 3.结构体大小：参数需要按最大成员进行对齐
 *  所谓对齐，是有个偏移量的概念，
 *  计算结构体大小参考：
 *      https://www.cnblogs.com/qiumingcheng/p/11370836.html
 *      http://www.360doc.com/content/17/0705/16/44422250_669100288.shtml 
 *      http://www.360doc.com/content/17/0705/17/44422250_669107998.shtml
 *      
 *      这个是黑马视频解释结构体长度获取，角度与上面不同，感觉好理解
 *      https://www.bilibili.com/video/BV1BK4y1j7AW?p=21&vd_source=3509947f569e04aa5c144447e22d0ceb
 * 
 * 注意！！！ c++空结构体有1字节占用；c中空结构体无字节占用；
*/

#include<stdio.h>
#include<stdlib.h>

void study(){
    printf("1234\n");
}

struct Student{
    //当前数偏移量计算公式：上个数偏移量+上个数大小+填充数（保证偏移量是当前数的倍数）
    short age; //0 偏移量
    float score; //0+1+3  因为必须是自身倍数，所以当前填充3，1是age大小。score首地址=0+1
    char gender;//4+4 score首地址（偏移量）+score自身大小 = gender的首地址(偏移量)
    void(*study)();//8+1+7  8偏移量+gender大小=9，自身倍数，所以要+7填充；偏移量是16；  Student整体大小就是偏移量16+最后一个数的大小8 =24
};

int main(){
    // struct  Student stu = {12,99.8f,'f'};
    
    // stu.age = 13;
    // printf("%hd\n",stu.age);

    // // stu.study();

    // //结构体可以有指针
    // struct  Student* stuP = &stu;
    // stuP->study();

    printf("stu size: %d\n",sizeof(struct Student));
}