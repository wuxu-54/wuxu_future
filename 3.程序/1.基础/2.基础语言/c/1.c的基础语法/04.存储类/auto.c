/*auto 只能用于函数中，在函数结束时被销毁*/
#include <stdio.h>

void ss(){
    auto int a =1;
}

int main(){
    ss();
}