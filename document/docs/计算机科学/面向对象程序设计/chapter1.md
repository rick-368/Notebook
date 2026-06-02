# C++ 基础
## 第一个 C++ 程序
一个输出 "Hello, world!" 的 C++ 程序如下：  

```c++
#include <iostream>
using namespace std;

int main() {
    cout << "Hello, world!" << endl;
}
```

编译并运行程序，输出结果为：
```
Hello, world!
```

可以看到，与一个普通的 C 程序不同，在 C++ 中，我们需要包含头文件 `iostream` 来使用 `cout` 输出语句。  

`endl` 语句用来换行，同时它有刷新缓冲区的作用，即‌强制将输出流中的内容立即写入目标设备（屏幕或文件）。

我们需要`using namespace std`语句来规定程序的命名空间，如果不加上这个语句，则需要使用 ：
```c++
std::cout << "Hello, world!" << std::endl;
```

同时，如果需要在终端输入一些数据，可以使用 `cin` 语句：
```c++
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
}
```
`cin` 语句用来从标准输入流（键盘）读取数据，它读取数据直到遇到空格、制表符、换行符、EOF（文件结束符）为止，但这些空格、制表符、换行符不会被读取。

`getline()` 函数可以用来读取一整行，包括换行符。

如果将`cin`和`getline()`一起使用读取多行输入，需要使用`cin.ignore()`函数来跳过输入流中的空格、制表符、换行符。避免`getline()`读到上一行的换行符等。


## 对象

### 字符串 
C++ 中，字符串是一种类，我们可以使用 `string` 类来处理字符串。  
字符串的创建赋值，字符串的创建赋值有以下三种形式：

```c++
string s1 = "Hello, world!"; // 直接初始化
string s2("Hello, world!"); // 拷贝初始化
string s3{"Hello, world!"}; //C++11 列表初始化
```


字符串作为类，具有很多成员函数，比如 `length()`、`find()`、`substr()` 等。
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello, world!";
    string s2 = s1.substr(7, 5); // 从索引 7 开始，取 5 个字符
    cout << s1.length() << endl; // 输出 13
    cout << s2 << endl; // 输出 "world"
    return 0;
}
```

还有一些函数可以修改字符串内容，比如 `replace()`、`append()`、`insert()`、`erase()` 等。
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello, world!";
    s1.replace(7, 5, "C++"); // 从索引 7 开始，替换 5 个字符为 "C++"
    cout << s1 << endl; // 输出 "Hello, C++!"
    s1.append(" is a great language."); // 在末尾添加一段文字
    cout << s1 << endl; // 输出 "Hello, C++! is a great language."
    s1.insert(7, "is"); // 在索引 7 位置插入 "is"
    cout << s1 << endl; // 输出 "Hello, is C++! is a great language."
    s1.erase(7, 3); // 从索引 7 开始，删除 3 个字符
    cout << s1 << endl; // 输出 "Hello, C++! is a great language."
    return 0;
}
```

`find()` 函数可以查找子串的位置。
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello, world!";
    int pos = s1.find("world"); // 查找子串 "world" 的位置
    cout << pos << endl; // 输出 7
    return 0;
}
```

`find()`函数还可以传入第二个参数，表示查找的起始位置。

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello, world!";
    int pos = s1.find("world", 6); // 从索引 6 开始查找子串 "world" 的位置
    cout << pos << endl; // 输出 7
    return 0;
}
```

c++ 中也有指针，也可以通过指针来访问对象的函数（通过箭头运算符 `->`）。
```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1 = "Hello, world!";
    char* p = &s1; // 获取字符串的指针
    cout << p << endl; // 输出 "Hello, world!"
    cout << p->length() << endl; // 输出 13
    return 0;
}
```

与变量不同的是，c++中变量（类）在定义时即被初始化（c语言在定义时不会将变量初始化，所以它在未定义前时不确定值），而指针是没有确定值的。