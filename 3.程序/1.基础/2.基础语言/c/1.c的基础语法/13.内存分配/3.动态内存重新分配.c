#include<stdio.h>
#include<stdlib.h>

 /**
  * 动态内存重新分配：realloc
  * 
  * 注意！！如果原位置有足够可用内存空间，那么会在原内存继续分配；如果不可用，会重新申请内存空间，把原数据复制到新地址；
  */

int main(){
   int *p = malloc(sizeof(int) * 3);//分配12字节内存
   int i = 0;
   for (i = 0; i < 3; i++)
   {
     *(p+i) = i;
   }

   for ( i = 0; i < 3; i++)
   {
    printf("p+%d = %d\n",i,*(p+i));

   }


    realloc(p,sizeof(int) * 5);//扩充内存，重新分配:注意！！如果原位置有足够可用内存空间，那么会在原内存继续分配；如果不可用，会重新申请5个内存空间，把原数据复制到新地址；


    *(p+3) = 33;
    for ( i = 0; i < 3; i++)
   {
    printf("after free: p+%d = %d\n",i,*(p+i));
   }
}