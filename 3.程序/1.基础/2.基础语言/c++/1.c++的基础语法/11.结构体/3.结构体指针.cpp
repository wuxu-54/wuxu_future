#include<iostream>
using namespace std;

struct Book{
    int id;
    float price;
}book = {1,1.43f};

int main(){

    struct Book* bookPoint;
    bookPoint = &book;

    cout<<bookPoint<<endl;
    cout<<bookPoint->id<<endl;
}