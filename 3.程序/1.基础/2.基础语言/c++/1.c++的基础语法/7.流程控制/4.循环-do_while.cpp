#include <iostream>
using namespace std;

/**
 * 循环，顾名思义，不多解释；
 * 
 * do{
 * } while（）
 * 
 * （）内与if相同，是条件判断，真进入，假不进入
 * 
 * 与while区别： do-while 是先进行一次执行，然后再判断条件
*/
int main()
{
    int a = 5;
    int b = 0;

    do{
      cout<<"执行循环"<<b<<endl;
    }while(b++>a);
}