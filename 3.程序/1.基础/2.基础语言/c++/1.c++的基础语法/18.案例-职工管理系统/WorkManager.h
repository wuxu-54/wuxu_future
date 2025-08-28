#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Boss.h"
#include "Manager.h"

using namespace std;

#define WORKER_FILE  "work.txt"
#define WORKER_FILE_SPLIT  " "//空格，读取时可以视为两个数据

class WorkManager{
    private:
    void save();
    int query_num();
    void init_worker();

    int findWorkerIndexById(int id);//-1 不存在
    void deleteMemory();

    public:
    bool m_isempty_file;
    int m_worker_num;//员工数
    //这里必须是两个星，因为不允许创建抽象数组，得用指针方式创建。这个array存放的是每个Worker对象的指针地址
    Worker** m_workerArray;//员工数组，放在堆区，避免内存回收

    WorkManager();
    
    void exitSystem();

    void initSystem();

    void showMenu();

    void addWorker();

    void showWorkerInfo();

    //删除员工
    void deleteWorker( );

    //修改员工信息
    void updateWorkerInfo( );

    //查找员工信息,按id、按名字
    void findWorkerInfo( );

    //按编号排序
    void sortWorkerById( );

    //清空所有文档
    void clearAllInfo();

    ~WorkManager();
}; 