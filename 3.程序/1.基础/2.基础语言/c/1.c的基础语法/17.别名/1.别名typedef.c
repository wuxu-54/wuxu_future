
/**
 * 别名：给某种类型起一个别名
 * 
 * void* 表示任意类型的内存地址
*/
#include<stdio.h>


enum Week{
    MON,TURES=11,WED
};

typedef int myInt;

typedef enum Week myWeek;

int main(){
   myWeek my_week = WED;
   printf("my week : %d\n",my_week);

   myInt a = 21;
   printf("int typedef is myInt ,a=%d\n",a);
}