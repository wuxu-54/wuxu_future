#include <stdio.h>
/**
 * include 引入对应头文件。参考：https://blog.csdn.net/lmm0513/article/details/89554759
 * 
 * include 两种括号:
 * 1.<> 编译器从系统路径引入文件
 * 2."" 编译先从当前目录引入文件，没有再去系统引入
 * 
 * c语言的include不会检测已导入过的文件，会出现重复导入，此时需要通过#if判断是否导入
*/
int main()
{
    printf("hellow word c~");
}
