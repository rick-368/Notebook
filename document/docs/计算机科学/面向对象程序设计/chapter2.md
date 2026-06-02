# 容器（Container）

## STL
STL（Standard Template Library，标准模板库）是一系列常用且高效的算法和数据结构的模板集合，是ISO标准C++库的一部分。

使用STL有很多优点：缩短开发时间，增加代码可读性，鲁棒性好，代码易移植和维护等等。

C++标准库中包含：  
- `Pair`类（任何类型的配对，int/int,int/char等）
- 容器：vector（可扩展数组），deque（可扩展数组，两端均可扩展），list（双向链表），forward_list（单向链表），array（固定大小数组），string（字符串），set（集合）和 map（映射）等等
- 基本算法：排序，搜索等等
- 库中所以的标识符都在std命名空间中`using namespace std;`

## Vector

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
    // 声明一个ints的vector，此刻vector的值是确定的。
    vector<int> v;
    cout << number.size() << "," << number.capacity() << endl; 
    // 向vector中添加元素
    for(int i=1;i<=5;i++){
        v.push_back(i);
        cout << number.size() << "," << number.capacity() << endl;
    }
    // 访问vector中的元素
    for(int x: v){// 这种方式可以遍历vector中的元素，称为for-each循环
        cout << x << " ";
    }

}
```  
上述程序输出为：
```  
0,0
1,1
2,2
3,4
4,4
5,8
1 2 3 4 5
```    

我们将像vector这样的类称为泛型类（Generic Class），它在使用时必须指定两种类型：一是集合本身的类型，二是集合中元素的类型。

可以从上述程序看出，vector的容量是动态变化的，当向vector中添加元素时，如果容量不够，vector会自动扩容。它会自行统计当前存储的元素数量，使用它的size()方法可以获取当前元素数量。同时，它会保持插入元素的顺序。

可以对vector类型使用逻辑运算符，如`==`、`!=`、`>`、`>=`、`<`、`<=`等。这些运算符可以比较两个vector是否相等、大小关系等。

```c++
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1(100);
    cout << number.size() << "," << number.capacity() << endl;// 100,100
    // v1[100]=1; // 超出范围，会引发不确定性行为
    v1.push_back(1);
    cout << number.size() << "," << number.capacity() << endl;// 101,200
    cout << v1[100] << endl; // 1
```
在定义vector时，可以指定它的初始容量，如`vector<int> v(100)`，这时vector的size和capacity都为100。

当然也可以在定义时指定内部元素的值，如`vector<int> v{1,2,3,4,5}`。
### Vector的常见函数

- `V.size()`：返回vector中元素的数量
- `V.empty()`：判断vector是否为空
- `V.swap(W)`：交换两个vector的内容
- `I.begin()`：返回指向vector第一个元素的指针
- `I.end()`：返回指向vector最后一个元素的指针的下一位置的指针
- `V.at(i)`：返回第i个元素的引用，等价于`V[i]`
- `V.front()`：返回vector第一个元素的引用
- `V.back()`：返回vector最后一个元素的引用
- `V.push_back(x)`：在vector的末尾添加一个元素
- `V.pop_back()`：删除vector的最后一个元素
- `V.insert(I,x)`：在位置I处插入一个元素x
- `V.erase(I)`：删除位置I处的元素
- `V.clear()`：清空vector
- `find(first,last,x)`：在范围[first,last)中查找元素x的位置，返回指向x的指针，如果找不到，返回last（在algorithm头文件中定义）

## List
链表的定义和使用与vector类似，以下是一个链表的应用：

```c++
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(){
    list<string> s;
    s.push_back("hello");
    s.push_back("world");
    s.push_back("!");
    list<string>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}
```

### 迭代器（Iterator）
Iterater是一种特殊的指针，它可以用来遍历容器中的元素。  
定义：`list<int>::iterator it;`（::是解析运算符）
指向第一个元素：`it=s.begin()`    
指向最后一个元素的下一位置：`it=s.end()`    
前进一个元素：`++it`    
后退一个元素：`--it`     
访问当前元素：`*it`     

注意，下面的方法不可取：

```c++
list<string>::iterator it=s.begin();
list<string>::iterator it2=s.end();
while(it<it2){
    //...
}
```

在 C++ 中，`std::list` 的迭代器属于双向迭代器（Bidirectional Iterator），它只支持 ++（前进）、--（后退）以及相等/不等比较（==、!=）。它不支持 <、>、<=、>= 这类关系运算符。（`std::list` 的元素在内存中不是连续存储的，每个节点通过指针链接，无法直接通过地址偏移计算出两个迭代器之间的“距离”或“顺序”关系。）

### 在顺序容器间做出选择
- 除非有其他理由，否则使用 vector
- 如果程序包含大量小型元素且空间开销很重要，则不要使用 list 或 forward_list
- 如果程序需要随机访问元素，则使用 vector 或 deque
- 如果程序需要在容器中间插入元素，则使用 list 或 forward_list
- 如果程序需要在头部和尾部（而非中间）插入元素，则使用 deque

## Map

map（映射）是一种关联容器，它存储一组键值对（key-value pair）。每个键值对都是一个键和一个值。键必须是唯一的，值可以重复。  
map中的映射值可以通过对应的键使用下标运算符（operator[]）直接访问。  
map通常实现为二叉搜索树。

```c++
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, int> m;
    m["apple"] = 10;
    m["banana"] = 20;
    m["orange"] = 30;
    m["apple"] = 40; // 更新值
    for(auto p: m){
        cout << p.first << " " << p.second << endl;
    }
    // 访问值
    cout << m["apple"] << endl; // 40
    // 访问不存在的键
    cout << m["grape"] << endl; // 0
    // 删除键值对
    m.erase("banana");
}
```
## for-each循环

for-each循环是C++11引入的一种简化的循环语法，它可以用来遍历容器中的元素。它将元素的值赋给循环内部声明的迭代。

for-each是Iterater的语法糖，它会被编译器转换为对begin()和end()的调用。

```c++
for(auto/type var:array/vector_name){
    // 循环体
}
```
for-each它有很多优点如：它易于实现，无需初始化迭代器，且它消除了错误的可能性，并使代码更易读。
当然，for-each也有缺点，它无法直接访问对应的元素索引，且在遍历每个元素时不允许用户跳过任何元素。无法按逆序访问元素。