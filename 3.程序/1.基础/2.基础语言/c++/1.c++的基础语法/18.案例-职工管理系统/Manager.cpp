//管理
#include "Manager.h"

Manager::Manager( 
     int id,
     string name,
     int dId)
{
    this->id = id;
    this->name = name;
    this->dId = dId;
}

void Manager::showInfo() 
{
    cout<<"worker id: "<<id
        <<"\t name : "<<name
        <<"\t 岗位  : "<<getDepName()
        <<"\t 岗位职责  : 接收老板任务，分派任务"<<endl;
}

string Manager::getDepName() 
{
    return "管理";
}

Manager::~Manager()
{}