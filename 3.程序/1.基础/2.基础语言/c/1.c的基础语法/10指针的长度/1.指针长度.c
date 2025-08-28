#include<stdio.h>
/**
 * 参考：https://www.bilibili.com/video/BV1BK4y1j7AW?p=11&vd_source=3509947f569e04aa5c144447e22d0ceb
 * 指针长度：
 * 64位系统 8个字节，32位系统4个字节
 * 
 * 32位系统指：32个二进制数，可以表示2^32个内存地址，最高识别总共4G
*/

int main(){
    printf("%d \n",sizeof(int*));
    printf("%d \n",sizeof(short*));
    printf("%d \n",sizeof(float*));
    printf("%d \n",sizeof(double*));
    printf("%d \n",sizeof(long*));
}