#include <stdio.h>

/**
 * 数组是连续的内存地址
*/
int main(){
  char arr1[] = "hello";//此方式，数组后会自动增加结束符 \0
  printf("arr[0] %#x\n",&arr1[0]);
  printf("arr[1] %#x\n",&arr1[1]);
  printf("arr[2] %#x\n",&arr1[2]);
  printf("arr[3] %#x\n",&arr1[3]);
  printf("arr[4] %#x\n",&arr1[4]);
  printf("arr %#x \n",&arr1);//取arr[0]地址

  //生命字符串常用方式,默认取数组第一个内存地址
  char* p = "hello";

   printf("p=%s, %#x \n",p,p);
   printf("p[0]=%c, p[0] address=%#x \n",*p,p);
   printf("p[1]=%c, p[1] address=%#x \n",*(p+1),p+1);
}