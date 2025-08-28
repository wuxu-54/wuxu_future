//老板
#include "Boss.h"

Boss::Boss( 
     int id,
     string name,
     int dId
    )
{
    this->id = id;
    this->name = name;
    this->dId = dId;
}

void Boss::showInfo() 
{
    cout<<"worker id: "<<id
        <<"\t name : "<<name
        <<"\t 岗位  : "<<getDepName()
        <<"\t 岗位职责  : 分派任务"<<endl;
}

string Boss::getDepName() 
{
    return "老板";
}

Boss::~Boss()
{

}