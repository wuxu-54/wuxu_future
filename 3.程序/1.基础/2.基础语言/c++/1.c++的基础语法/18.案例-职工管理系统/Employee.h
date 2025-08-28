#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Employee : public Worker
{
public:
    Employee( 
        int id,   // 员工编号
        string name, // 姓名
        int dId);

    void showInfo();
    string getDepName();
    ~Employee();
};