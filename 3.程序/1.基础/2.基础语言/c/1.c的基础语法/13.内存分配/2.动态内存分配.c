#include<stdio.h>
#include<stdlib.h>

 /**
  * 动态内存分配，手动申请内存
  * malloc 在堆中 动态申请内存，free 标记当前地址可使用，不是立刻清空，一般会将指针变量置NULL。参考：https://blog.csdn.net/piano_diano/article/details/88857499
  * 
  */

int main(){
   int *p = malloc(sizeof(int) * 3);//分配12字节内存
   int i = 0;//旧版本，c中int必须在外部声明；当前版本，好像没这个限制了
   for (i = 0; i < 3; i++)
   {
     *(p+i) = i;
   }

   for ( i = 0; i < 3; i++)
   {
    printf("p+%d = %d\n",i,*(p+i));

   }

   free(p);

    for ( i = 0; i < 3; i++)
   {
    printf("after free: p+%d = %d\n",i,*(p+i));
   }
}