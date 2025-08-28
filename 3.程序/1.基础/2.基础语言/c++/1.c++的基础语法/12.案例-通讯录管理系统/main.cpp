#include <iostream>
#include "struct_type.cpp"

using namespace std;
/**
 * 菜单
 */
void showMenu()
{
    cout << "*********************" << endl;
    cout << "****1、添加联系人****" << endl;
    cout << "****2、显示联系人****" << endl;
    cout << "****3、删除联系人****" << endl;
    cout << "****4、查找联系人****" << endl;
    cout << "****5、修改联系人****" << endl;
    cout << "****6、清空联系人****" << endl;
    cout << "****0、退出通讯录****" << endl;
    cout << "*********************" << endl;
}

/**
 * 退出
 */
void exit()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

/**
 * 添加
 */
void addPerson(struct AddressBooks *addressPerson)
{
    if (addressPerson->size == MAX)
    {
        cout << "已经到最大值了，无法继续添加" << endl;
        return;
    }
    else
    {
        struct Person person;
        cout << "请输入名字：";
        cin >> person.name;
        cout << "请输入年龄：";
        cin >> person.age;
        cout << "请输入性别：";
        cin >> person.sex;
        cout << "请输入住址：";
        cin >> person.address;
        cout << "请输入电话：";
        cin >> person.phone;

        addressPerson->personArray[(addressPerson->size)++] = person;

        cout << endl;
        cout << "添加成功" << endl;
    }
}

/**
 * 显示
 */
void showBooks(struct AddressBooks *addressPerson)
{
    if (addressPerson->size == 0)
    {
        cout << "当前未添加联系人，请去添加" << endl;
        return;
    }
    else
    {
        for (int i = 0; i < addressPerson->size; i++)
        {
            Person person = addressPerson->personArray[i];
            cout << "名字：" << person.name;
            cout << ",性别：" << person.sex;
            cout << ",年龄：" << person.age;
            cout << ",住址：" << person.address;
            cout << ",电话：" << person.phone << endl;
        }
    }
}

/**
 * 删除
 *
 * 1.取
 * 2.判断
 * 3.地址提前，移除要删除的地址
 */
int isExitPerson(struct AddressBooks *books, string name)
{
    if (books->size == 0)
    {
        return -1;
    }

    for (int i = 0; i < books->size; i++)
    {
        // 取
        Person *person = &(books->personArray[i]);
        // 判断符合条件
        if (person->name == name)
        {

            return i;
        }
    }

    return -1;
}

void delPerson(struct AddressBooks *books)
{
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    int index = isExitPerson(books, name);
    if (index == -1)
    {
        cout << "不存在此联系人" << endl;
        return;
    }

    for (int i = index; i < books->size - 1; i++)
    {
        // 移除指针数据
        books->personArray[i] = books->personArray[i + 1];
    }

    books->size--;
    cout << "已删除联系人：" << name << endl;
}

/**
 * 查询
 */
void queryPerson(struct AddressBooks *books)
{
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    int index = isExitPerson(books, name);
    if (-1 == index)
    {
        cout << "未查询到此联系人" << endl;
    }
    else
    {
        Person person = books->personArray[index];
        cout << "查询到此联系人:"
             << " 姓名：" << person.name << ",年龄：" << person.age << ",性别：" << person.sex << ",住址：" << person.address << ",电话：" << person.phone << endl;
    }
}

/**
 * 修改
 */

void updatePerson(struct AddressBooks *books)
{
    string name;
    cout << "请输入要修改信息的联系人姓名：" << endl;
    cin >> name;
    int index = isExitPerson(books, name);
    if (-1 == index)
    {
        cout << "未查询到此联系人" << endl;
    }
    else
    {
        struct Person person = books->personArray[index];

        string name1;
        cout << "请输入新名字：";
        cin >> name1;
        person.name = name1;
        /**
         * 疑问：直接取person结构体，然后赋值，竟然不行，下面方式可以，第一次addPerson方法也可以。 
         * 原因：结构体在内存栈中，所以函数中重新声明变量，会复制一份给新局部变量,所以最后需要将此局部变量再赋值给对应数组地址中。
         * 
         * 总结：不要使用这中方式，会浪费资源，要不就用指针，要不就直接取数组变量。
         */ 
        // books->personArray[index].name = name1;

        int age;
        cout << "请输入新年龄：";
        cin >> age;
        person.age = age;

        int sex;
        cout << "请输入新性别：";
        cin >> sex;
         person.sex = sex;

        string address;
        cout << "请输入新住址：";
        cin >> address;
        person.address = address;

        string phone;
        cout << "请输入新电话：";
        cin >> phone;
        person.phone = phone;


        books->personArray[index] = person;//重新将局部变量赋值回来，结构体不是类，其在栈内存，每次创建声明会复制。
        cout << "修改完成" << endl;
    }
}

/**
 * 清空联系人
 */
void clearPerson(struct AddressBooks *books)
{
    books->size = 0;
    cout << "清空完成" << endl;
}

void select(int position, struct AddressBooks *books)
{
    string m_name;
    switch (position)
    {
    // 退出程序
    case 0:
        exit();
        break;

    // 1、添加联系人
    case 1:
        addPerson(books);
        break;

    // 2、显示联系人
    case 2:
        showBooks(books);
        break;

    // 3、删除
    case 3:

        delPerson(books);
        break;

    // 4、
    case 4:

        queryPerson(books);
        break;

    // 5、
    case 5:

        updatePerson(books);
        break;

    // 6、
    case 6:

        clearPerson(books);

        break;
    default:
        cout << "此命令未找到" << endl;
        break;
    }
}

int main()
{
    int inputPosition = -1;
    struct AddressBooks books;
    while (true)
    {
        showMenu();
        cin >> inputPosition;
        select(inputPosition, &books);
    }

    return 0;
}
