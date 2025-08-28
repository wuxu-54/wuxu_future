#include<stdio.h>

/*以下方式有问题，传出去的p不是真正a的地址*/
// void fun(int *p){
//     int a = 123;

//     printf("a == %#x\n",&a);
//     p =&a;

// }
// int main(){
//     int *p;
//     fun(p);

//     printf("p == %#x\n",p);
// }

int a = 123;
void fun(int **p){
    // int a = 123;

    printf("a == %#x\n",&a);
    *p =&a;
    printf("p:%d\n",**p);
}
int main(){
    int *p;
    fun(&p);

    printf("p == %#x\n",p);

    //!!!这个地方为什么 *p取到的值不等于123？？？：以后学明白解答。
    //答：int a 属于函数中的局部变量，方法执行完就回收，其地址指向的数值可能被修改为其他数值了，当a 变为全局变量，执行同样流程会发现，结果为123了
    printf("p:%d\n",*p);
}