#include "WorkManager.h"

WorkManager::WorkManager()
{
    initSystem();
}

void WorkManager::save()
{
    ofstream ofs(WORKER_FILE, ios::out);
    for (int i = 0; i < m_worker_num; i++)
    {
        Worker** w= m_workerArray+1;
        Worker* t = *w;

        ofs <<m_workerArray[i]->id << WORKER_FILE_SPLIT
            << m_workerArray[i]->name << WORKER_FILE_SPLIT
            << (*(m_workerArray+i))->dId<< endl;
    }

    ofs.close();
}

void WorkManager::init_worker()
{
    ifstream ifs(WORKER_FILE, ios::in);
    int id;
    int dId;
    string name;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker;
        switch (dId)
        {
            // boss
        case 1:
            worker = new Boss(id, name, dId);
            break;
            // 管理
        case 2:
            worker = new Manager(id, name, dId);
            break;
        // 普通员工
        default:
            worker = new Employee(id, name, dId);
            break;
        }

        this->m_workerArray[num] = worker;

        num++;
    }

    ifs.close();
}
int WorkManager::query_num()
{
    ifstream ifs(WORKER_FILE, ios::in);
    int id;
    int dId;
    string name;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++; // 以上都有时，会走到循环
    }

    ifs.close();
    return num++;
}

int WorkManager::findWorkerIndexById(int id)
{
    int index = -1;
    // 遍历
    for (int i = 0; i < m_worker_num; i++)
    {
        if ((*m_workerArray + i)->id == id)
        {
            index = i;
        }
    }
    return index;
}

void WorkManager::initSystem()
{
    this->m_worker_num = 0;
    this->m_workerArray = NULL;
    this->m_isempty_file = true;

    ifstream ifs(WORKER_FILE, ios::in);

    // 情况1.文件未创建
    if (!ifs.is_open())
    {
        cout << "文件未打开" << endl;
        ifs.close();
        return;
    }

    // 情况2.文件为空
    char ch;
    ifs >> ch;
    if (ch == EOF)
    { // 说明文件为空
        cout << "文件为空" << endl;
        ifs.close();
        return;
    }

    // 情况3.文件有数据

    // 创建worker数组
    int num = query_num();
    this->m_worker_num = num;
    this->m_workerArray = new Worker *[num];
    this->m_isempty_file = false;
    // 将数据写入数组中
    this->init_worker();

    ifs.close();
}

void WorkManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause"); // 防止窗口直接关闭
    exit(0);
}

void WorkManager::showMenu()
{
    cout << "******************************" << endl;
    cout << "******* 职工管理系统 **********" << endl;
    cout << "******* 0.退出系统 ***********" << endl;
    cout << "******* 1.添加职工信息 ********" << endl;
    cout << "******* 2.显示职工信息 ********" << endl;
    cout << "******* 3.删除离职员工 ********" << endl;
    cout << "******* 4.修改职工信息 ********" << endl;
    cout << "******* 5.查找职工信息 ********" << endl;
    cout << "******* 6.按编号排序 **********" << endl;
    cout << "******* 7.清空所有文档 ********" << endl;
    cout << "******************************" << endl;
    cout << endl;
}

void WorkManager::addWorker()
{
    cout << "请输入添加员工个数：";
    int add_num = 0;
    cin >> add_num;

    if (add_num > 0)
    {
        int newSize = add_num + m_worker_num;
        Worker **newSpace = new Worker *[newSize];

        if (m_workerArray != NULL)
        {
            // 添加新员工，需要将旧数据拷贝到新地址
            for (int i = 0; i < m_worker_num; i++)
            {
                newSpace[i] = m_workerArray[i];
            }
        }

        // 正式添加数据
        for (int i = m_worker_num; i < newSize; i++)
        {
            int id;
            cout << "请输入员工编号" << endl;
            cin >> id;
            string name;
            cout << "请输入员工姓名" << endl;
            cin >> name;

            int dId;
            cout << "请选择岗位编号" << endl;
            cout << "1. 老板" << endl;
            cout << "2. 管理" << endl;
            cout << "3. 普通员工" << endl;
            cin >> dId;

            Worker *worker;
            switch (dId)
            {

                // boss
            case 1:
                worker = new Boss(id, name, dId);
                break;
                // 管理
            case 2:
                worker = new Manager(id, name, dId);
                break;
            // 普通员工
            default:
                worker = new Employee(id, name, dId);
                break;
            }

            newSpace[i] = worker;

            cout << "worker：" << worker<<" ,i:"<<i << endl;
        }
        // 释放原有空间
        delete[] this->m_workerArray;

        this->m_workerArray = newSpace;
        this->m_worker_num = newSize;
        this->m_isempty_file = false; // 文档不为空
        // 将数据写入文档中
        this->save();
    }
    else
    {
        cout << "输入添加员工个数无效";
        system("pause");
        system("cls");
    }
}

void WorkManager::showWorkerInfo()
{
    // 判断worker集合
    if (m_workerArray == nullptr)
    {
        cout << "还没添加职工呢~" << endl;
        return;
    }
    // 循环展示worker信息
    for (int i = 0; i < m_worker_num; i++)
    {
        (*(m_workerArray + i))->showInfo();
    }
}

void WorkManager::deleteWorker()
{
    if (m_isempty_file)
    {
        cout << "还没添加职工呢~" << endl;
        return;
    }

    int id;
    cout << "输入要删除的员工号" << endl;
    cin >> id;

    int index = findWorkerIndexById(id);
    if (index != -1)
    {
        // 执行删除,本质是数据前移
        for (int i = index; i < m_worker_num - 1; i++)
        {
            m_workerArray[i] = m_workerArray[i + 1]; // 数据前移
        }
        m_worker_num--;

        this->save();
        cout << "员工删除完成" << endl;
    }
    else
    {
        cout << "员工不存在，无法删除" << endl;
    }

    if (m_worker_num == 0)
    {
        this->m_isempty_file = true; // 文档为空
    }

    // 清屏
    system("pause");
    system("cls");
}

void WorkManager::updateWorkerInfo()
{
    if (m_isempty_file)
    {
        cout << "还没添加职工呢~" << endl;
        return;
    }

    int id;
    cout << "输入要修改的员工号" << endl;
    cin >> id;

    int index = findWorkerIndexById(id);
    if (index != -1)
    {

        // delete this->m_workerArray[index];//释放原堆区对象,这里运行会报错， illegal hardware instruction

        int id;
        cout << "请输入员工编号" << endl;
        cin >> id;
        string name;
        cout << "请输入员工姓名" << endl;
        cin >> name;

        int dId;
        cout << "请选择岗位编号" << endl;
        cout << "1. 老板" << endl;
        cout << "2. 管理" << endl;
        cout << "3. 普通员工" << endl;
        cin >> dId;

        Worker *worker;
        switch (dId)
        {
            // boss
        case 1:
            worker = new Boss(id, name, dId);
            break;
            // 管理
        case 2:
            worker = new Manager(id, name, dId);
            break;
        // 普通员工
        default:
            worker = new Employee(id, name, dId);
            break;
        }

        m_workerArray[index] = worker;

        this->save();
        cout << "员工修改完成" << endl;
    }
    else
    {
        cout << "员工不存在" << endl;
    }
}

void WorkManager::findWorkerInfo()
{
    if (m_isempty_file)
    {
        cout << "还没添加职工呢~" << endl;
        return;
    }

    cout << "请输入查找方式: 按编号查输入0,按姓名查输入1" << endl;
    int select = 0;
    cin >> select;
    if (select == 0)
    {
        // 按id查
        cout << "请输入编号" << endl;
        int id;
        cin >> id;
        int index = findWorkerIndexById(id);
        if (index == -1)
        {
            cout << "没查到员工" << endl;
        }
        else
        {
            cout << "编号" << id << "员工信息如下：" << endl;
            cout << "编号: " << m_workerArray[index]->id
                 << "姓名：" << m_workerArray[index]->id
                 << "部门：" << m_workerArray[index]->name
                 << "岗位职责：" << m_workerArray[index]->getDepName() << endl;
        }
    }
    else if (select == 1)
    {
        // 按姓名查
        cout << "请输入姓名" << endl;
        string name;
        cin >> name;
        bool finded = false;
        for (int index = 0; index < m_worker_num; index++)
        {
            if (m_workerArray[index]->name == name)
            {
                finded = true;
                cout << "姓名：" << name << "，编号为[" << m_workerArray[index]->id << "]的员工信息如下：" << endl;
                cout << "编号: " << m_workerArray[index]->id
                     << "姓名：" << m_workerArray[index]->id
                     << "部门：" << m_workerArray[index]->name
                     << "岗位职责：" << m_workerArray[index]->getDepName() << endl;
            }
        }

        if (finded == false)
        {
            cout << "没查到员工" << endl;
        }
    }
}

void WorkManager::sortWorkerById()
{
    if (m_isempty_file)
    {
        cout << "还没添加职工呢~" << endl;
        return;
    }

    cout << "请输入排序方式: 按编号降序0,按编号升序1" << endl;
    int select = 0;
    cin >> select;

    // 选择排序实现
    for (int i = 0; i < m_worker_num; i++)
    {
        int minOrMax = i; // 取i位置
        for (int j = i + 1; j < m_worker_num; j++)
        {
            if (select == 0)
            {
                // 降序
                if (m_workerArray[minOrMax]->id < m_workerArray[j]->id)
                {
                    minOrMax = j;
                }
            }
            else
            {
                // 升序
                if (m_workerArray[minOrMax]->id > m_workerArray[j]->id)
                {
                    minOrMax = j;
                }
            }
        }

        if (minOrMax != i)
        {
            // 交换
            Worker *temp = m_workerArray[i];
            m_workerArray[i] = m_workerArray[minOrMax];
            m_workerArray[minOrMax] = temp;
        }
    }

    cout << "排序成功" << endl;

    save();
}

void WorkManager::clearAllInfo()
{
    cout << "确定清空数据吗？" << endl;
    cout << "1、确定" << endl;
    cout << "2、取消" << endl;
    int select = 1;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs(WORKER_FILE, ios::trunc); // ios::trunc 删除重建
        ofs.close();

        deleteMemory();

        cout << "清除成功" << endl;
    }
    system("pause");
    system("cls");
}

void WorkManager::deleteMemory()
{
    // 清空缓存数据
    if (this->m_workerArray != NULL)
    {
        for (int i = 0; i < m_worker_num; i++)
        {
            delete m_workerArray[i]; // 清除堆内存数据
            m_workerArray[i] = NULL;
        }

        delete[] m_workerArray;
        m_workerArray = NULL;
        m_worker_num = 0;
        m_isempty_file = true;
    }
}

WorkManager::~WorkManager()
{
    deleteMemory();
}