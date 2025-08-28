# c++的存储类

参考资料：[菜鸟教程c++的存储类](https://www.runoob.com/cplusplus/cpp-storage-classes.html)

存储类定义 C++ 程序中变量/函数的范围（可见性）和生命周期。这些说明符放置在它们所修饰的类型之前。（对比c 中存储类，c++做了些修改。）

## C++ 程序中可用的存储类

auto、register、static、external、mutable、thread_local

*从 C++ 17 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用。*

---

### auto

**在c++ auto与c是完全不同的含义，同时使用方式也不同。** 自 C++ 11 以来，auto 关键字用于两种情况：声明变量时根据初始化表达式自动推断该变量的类型、声明函数时函数返回值的占位符。C++98标准中auto关键字用于自动变量的声明，但由于使用极少且多余，在 C++17 中已删除这一用法。

```cpp
auto f=3.14;      //double  c中定义方式：auto float f=3.14; 且c中auto只是代表变量生命周期跟随随函数，无其他意义。c++中表示动态数据类型，其具体类型跟随值确定，也就是kotlin中var、js中的let、flutter中的dynamic
auto s("hello");  //const char*
auto z = new auto(9); // int*
auto x1 = 5, x2 = 5.0, x3='r';//错误，必须是初始化为同一类型
```

从 C++ 17 开始，auto 关键字不再是 C++ 存储类说明符。

---

### register

与c相同，但从 C++ 17 开始 register 关键字被弃用。

---

### static

c++中增加了一种定义,其他的与C相同：  

在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。简单来说就是某个类所有的对象都持有同一个static 变量，**跟java中静态一样**。  

使用: `类名::静态成员名`

---

### extern

与C相同

---

### mutable

（**C++特有**）

mutable 成员可以在 const 函数内修改。

[CSDN博文:](https://blog.csdn.net/weixin_51684362/article/details/131364670)在 C++ 中，`mutable` 是一个关键字，用于修饰类的成员变量。`mutable` 关键字的作用是允许被修饰的成员变量在 `const` 成员函数中被修改，即使这些函数被声明为 `const`。

下面是 `mutable` 关键字的使用示例：

```cpp
    class MyClass {
    public:
        int getValue() const;
    private:
        mutable int counter;
    };

    int MyClass::getValue() const {
        counter++;  // 允许在 const 成员函数中修改 mutable 成员变量
        return counter;
    }
```

在上述示例中，`counter` 是一个 `mutable` 成员变量。虽然 `getValue` 函数被声明为 `const`，即不会修改类的状态，但由于 `counter` 被标记为 `mutable`，因此在 `getValue` 函数内部可以对其进行修改。

使用 `mutable` 关键字的典型场景是当类的成员变量需要在某些情况下被修改，即使这些修改发生在 `const` 成员函数中。一种常见的应用是在类中使用缓存或记录对象状态的变量，而这些变量的更新操作并不会影响类的逻辑或状态。

需要注意的是，滥用 `mutable` 关键字可能会导致代码可读性和维护性的问题。因此，在使用 `mutable` 时，应谨慎考虑并确保其使用是必要的，并遵循良好的设计原则。

---

### thread_local (C++11)

（**C++特有**）

使用 `thread_local` 说明符声明的变量仅可在它在其上创建的线程上访问。 变量在创建线程时创建，并在销毁线程时销毁。 每个线程都有其自己的变量副本。

`thread_local` 说明符可以与 `static` 或 `extern` 合并。

可以将 `thread_local` 仅应用于数据声明和定义，`thread_local` 不能用于函数声明或定义。

```cpp
thread_local int x;  // 命名空间下的全局变量
class X
{
    static thread_local std::string s; // 类的static成员变量
};
static thread_local std::string X::s;  // X::s 是需要定义的

void foo()
{
    thread_local std::vector<int> v;  // 本地变量
}
```

从 C++ 17 开始，auto 关键字不再是 C++ 存储类说明符，且 register 关键字被弃用。
