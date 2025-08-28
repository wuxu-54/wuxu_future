#include<iostream>
using namespace std;


struct Name{
    int a = 1;
};
struct Book{
    int id;
    float price;
    struct Name name;
}book = {1,1.43f};

int main(){
    struct Name name ={2};
    book.name = name;

    cout<<book.name.a<<endl;

}