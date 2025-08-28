#include <iostream>
#include "WorkManager.cpp"
#include "Employee.cpp"
#include "Boss.cpp"
#include "Manager.cpp"
using namespace std;

void domain()
{
    WorkManager workManager;
    int selectNum;
    while (1)
    {
        workManager.showMenu();
        cout << "请输入您的选择：";
        cin >> selectNum;

        switch (selectNum)
        {
        case 0: // 退出系统
            workManager.exitSystem();
            break;
        case 1: // 添加职工信息
            workManager.addWorker();
            break;
        case 2: // 显示职工信息
            workManager.showWorkerInfo();
            break;
        case 3: // 删除离职员工
            workManager.deleteWorker();
            break;
        case 4: // 修改职工信息
            workManager.updateWorkerInfo();
            break;
        case 5: // 查找职工信息
            workManager.findWorkerInfo();
            break;
        case 6: // 按编号排序
            workManager.sortWorkerById();
            break;
        case 7: // 清空所有文档
            workManager.clearAllInfo();
            break;
        default:
            system("cls"); // 刷新屏幕
            break;
        }
    }
}

void testEmployee()
{
    Worker *worker = NULL;
    worker = new Employee(1, "2", 3);
    worker->showInfo();
}

/**
 * mac运行：
 * 1.g++ cpp文件全名；编译exe文件
 * 2.终端输入 ./a.out；执行exe文件
 */
int main()
{
    // testEmployee();
    domain();
}
