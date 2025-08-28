#include<iostream>
using namespace std;

#define MAX 1000

/**
 * 联系人结构体
*/

struct Person
{
   string name;
   int sex;
   int age;
   string address;
   string phone;
};

/**
 * 通讯录结构体
 * 
 * 联系人数组、联系人个数
*/
struct AddressBooks
{
   struct Person personArray[MAX];

   int size=0;
};