// 普通员工
#include "Employee.h"

Employee::Employee( 
     int id,
     string name,
     int dId
    )
{
    this->id = id;
    this->name = name;
    this->dId = dId;
}

void Employee::showInfo() 
{
    cout<<"worker id: "<<id
        <<"\t name : "<<name
        <<"\t 岗位  : "<<getDepName()
        <<"\t 岗位职责  : 执行任务"<<endl;
}

string Employee::getDepName() 
{
    return "普通员工";
}

Employee::~Employee()
{}