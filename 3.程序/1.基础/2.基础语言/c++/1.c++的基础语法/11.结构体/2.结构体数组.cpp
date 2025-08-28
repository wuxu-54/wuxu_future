#include<iostream>
using namespace std;

struct Book{
    int id;
    float price;
};

int main(){
    //定义数组
    struct Book bookArray[2]={{1,1.4f},{2,1.5f}};
    cout<<bookArray[0].id<<endl;
    cout<<bookArray[1].id<<endl;
}