#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker
{
public:
    int id;   // 员工编号
    string name; // 姓名
    int dId;  // 所在部门编号

    virtual void showInfo() = 0;
    virtual string getDepName() = 0;//获取岗位名称
    virtual ~Worker(){};//析构必须是虚函数或纯虚函数，因为释放时需要把子view同时释放，如果不写，需要子类写有析构。否则delete会报错
};