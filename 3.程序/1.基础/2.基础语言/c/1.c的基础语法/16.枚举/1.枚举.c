
/**
 * 枚举：默认int类型，会自增
*/
#include<stdio.h>


enum Week{
    MON,TURES=11,WED
};

int main(){
    enum Week m = MON;
    printf("%d\n",m);

      enum Week m1 = TURES;
    printf("%d\n",m1);

        enum Week m2 = WED;
    printf("%d\n",m2);


    enum Week m3 = 18;//不在枚举范围内也不报错。
    printf("%d\n",m3);
}