# Cast 运算符

在c++中，`cast` 运算符用于将一个对象转换为另一个类型。

有四种cast运算符：

- static_cast
- dynamic_cast
- const_cast
- reinterpret_cast

## static_cast

static_cast 用于在相关类型之间进行转换。它是最常用的cast之一，适用于以下情况：

- 基本类型之间的转换（例如，int 到 float）。
- 类层次结构中，父类指针/引用和子类指针/引用之间的转换。
- 将void指针转换为目标类型指针。

```cpp
int main() {
    int a = 10;
    double b = static_cast<double>(a); // int到double的转换

    class Base {};
    class Derived : public Base {};
    Derived d;
    Base* basePtr = static_cast<Base*>(&d); // 子类指针转换为父类指针

    void* voidPtr = &a;
    int* intPtr = static_cast<int*>(voidPtr); // void指针转换为int指针

    return 0;
}
```

## dynamic_cast

dynamic_cast 主要用于多态类型的转换。它可以在运行时检查类型安全。常用于将父类指针/引用转换为子类指针/引用。

```cpp
#include <iostream>

class Base {
    virtual void foo() {} // 需要有至少一个虚函数
};

class Derived : public Base {
};

int main() {
    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr); // 运行时检查
    if (derivedPtr) {
    std::cout << "Cast succeeded.\n";
    } else {
    std::cout << "Cast failed.\n";
    }
    delete basePtr;
    return 0;
}
```

## const_cast

const_cast 用于修改类型的 const 或 volatile 属性。例如，可以去除 const 属性，以便修改原本 const 的变量。

```cpp
int main() {
    const int a = 10;
    int* b = const_cast<int*>(&a); // 去除const属性
    *b = 20; // 现在可以修改a的值
    return 0;
}
```

## reinterpret_cast

reinterpret_cast 用于进行低级别的、几乎没有类型检查的转换。它可以在几乎任何类型之间进行转换，但这种转换是非常危险的，因为它可能破坏数据的完整性。

```cpp
#include <iostream>

int main() {
    int a = 65;
    char* chPtr = reinterpret_cast<char*>(&a); // 将int指针转换为char指针
    std::cout << *chPtr << std::endl; // 输出'A'。因为65对应ASCII码的'A'
    return 0;
}
```

