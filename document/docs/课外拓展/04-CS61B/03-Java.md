# 数据类型
- java的数据类型分为基本数据类型和引用数据类型。
- 基础数据类型包括byte、short、int、long、float、double、char、boolean。
- 引用数据类型包括类、接口、数组、枚举。


## 基本数据类型
Java有八种基本数据类型：

- byte：1字节，-128~127
- short：2字节，-32768~32767
- int：4字节，-2147483648~2147483647
- long：8字节，-2^63 ~ 2^63-1
- float：4字节，小数点后6位
- double：8字节，小数点后15位
- char：2字节，Unicode编码
- boolean：1字节，true或false

## 引用数据类型
-  在Java中，引用类型的变量非常类似于C/C++的指针。引用类型指向一个对象，指向对象的变量是引用变量，这个被指向对象的地址存储在引用变量中。这些变量在声明时被指定为一个特定的类型，比如 Employee、Puppy 等。变量一旦声明后，类型就不能被改变了。
- 所有引用类型的默认值都是null（空引用）。
- 一个引用变量可以用来引用任何与之兼容的类型。

## 两者的区别
- 基本数据类型的值是直接存储在变量中，而引用数据类型的值是存储在变量中的是对象的引用，而不是对象本身。
- 基本数据类型的值是不可变的，而引用数据类型的值是可变的。
```java
int a = 10; 
b = a;
a = 20;
System.out.println(b); // 输出结果为10

Employee e1 = new Employee("John");
Employee e2 = e1;
e1.setName("Mary");
System.out.println(e2.getName()); // 输出结果为Mary
```
## 等号的黄金法则
- 给定变量b和a，b = a的含义是将a的所有位值复制到b中。
- 在传递参数时也遵循这个法则，只需将位复制到新作用域，如果参数是基本数据类型，则传递的是值，如果参数是引用数据类型，则传递的是引用。


## 数组的定义和使用
```java
数据类型[] 数组名 = new 数据类型[数组长度];
数据类型[] 数组名 = {元素1, 元素2, 元素3...};
```

- 由于数组不是基础数据类型，所以在定义数组时，需要加new关键字。
- 数组的长度是固定的，一旦定义后，不能改变。 
- 要打印数组，可以调用 `Arrays.toString(array)`。
- Java 不支持负索引或切片。
- Java 提供复制数组的函数 `System.arraycopy(src, srcPos, dest, destPos, length)`。
  - src：源数组
  - srcPos：源数组的起始位置
  - dest：目标数组
  - destPos：目标数组的起始位置
  - length：复制的元素个数
## 列表的定义和使用
- Java有List接口，使用ArrayList类实现。
- List 接口是通过它包含的类型进行参数化的，使用尖括号 < 和 >。
- List 同样不支持切片和负索引。
```java
List<数据类型> 列表名 = new ArrayList<>();
列表名.add(元素1);
列表名.set(索引, 元素2);
System.out.println(列表名.get(索引));
System.out.println(列表名.size());
if(列表名.contains(元素)){...}
```

## 集合的定义和使用
- Java有Set接口，使用HashSet类和TreeSet类实现。
- TreeSet 保持其元素的“排序”顺序，并且很快。相比之下，HashSet 没有定义的“顺序”，但通常非常快。
- Set 不能包含重复项。如果我们尝试向集合中添加已经存在的项，什么也不会发生。
- Set与List相近，都有add、remove、contains等方法。

## 字典的定义和使用
- Java有Map接口，使用HashMap类和TreeMap类实现，类似于集合。
- Map 不能包含重复的键。如果我们尝试向映射中添加已经存在的键，值将被覆盖。
- 在尖括号中，我们首先有“键类型”，然后是“值类型”。
```java
Map<键类型, 值类型> 字典名 = new HashMap<>();
字典名.put(键, 值);
System.out.println(字典名.get(键));
System.out.println(字典名.size());
if(字典名.containsKey(键)){...}
```

## 抛出异常
 与python raise 语句类似，Java也有throw语句来抛出异常。

```java
if(条件){
    throw new 异常类型("异常信息");
}
```

- 异常类型可以是任何类，但通常是Exception或其子类。