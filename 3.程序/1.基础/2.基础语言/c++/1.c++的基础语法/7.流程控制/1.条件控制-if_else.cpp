#include <iostream>
using namespace std;

/**
 * if(){
 * }else if(){
 * }else{
 * }
 * 
 * ()内是判断语句，结果为真才会进入if内，否则进入到else内
*/
int main(){
    int a  = 5;
    int b = 1;

    if (a>10)
    {
      cout<<"进入a if内"<<endl;
    }else if (a<4)
    {
         cout<<"进入a else-if内"<<endl;
    }else{
      cout<<"进入a else内"<<endl;
      //嵌套if-else
      if (b)
      {
        cout<<"进入b if内"<<endl;
      }else{
         cout<<"进入b else内"<<endl;
      }
    }
    
}