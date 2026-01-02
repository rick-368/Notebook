# Java 基础
## Java 简介
Java 是一门面向对象编程语言，是一种静态类型、多线程、分布式、健壮的语言。Java 语言的语法与 C 语言和 C++ 语言很接近，使得大多数程序员很容易学习和使用。
## 第一个 Java 程序
```java
public class HelloWorld {
    /* 第一个Java程序
     * 它将输出字符串 Hello World
     */
    public static void main(String[] args) {
        System.out.println("Hello World"); // 输出 Hello World
    }
}
```
编写 Java 程序时，应注意以下几点：

- 大小写敏感：Java 是大小写敏感的，这就意味着标识符 Hello 与 hello 是不同的。
- 类名：对于所有的类来说，类名的首字母应该大写。如果类名由若干单词组成，那么每个单词的首字母应该大写，例如 MyFirstJavaClass 。
- 方法名：所有的方法名都应该以小写字母开头。如果方法名含有若干单词，则后面的每个单词首字母大写。
- 源文件名：源文件名必须和类名相同。当保存文件的时候，你应该使用类名作为文件名保存（切记 Java 是大小写敏感的），文件名的后缀为 .java。（如果文件名和类名不相同则会导致编译错误）。
- 主方法入口：所有的 Java 程序由 public static void main(String[] args) 方法开始执行。
## 变量定义
- Java和c语言一样，都是需要先声明变量，然后再使用变量，基本变量类型也和c语言一样，包括整数、浮点数、字符、布尔值、字符串。
- 变量定义的语法如下：
```java
数据类型 变量名 = 变量值;
```
## 注释
- Java中单行注释以双斜线开头，多行注释以 /* 开头，以 */ 结尾。
## 循环语句
- Java中有三种循环语句，分别是for循环、while循环和do-while循环，语法均跟c语言类似。
- for循环语法：
```java
for(初始化表达式; 循环条件表达式; 迭代表达式){
    //循环体
}
```
- while循环语法：
```java
while(循环条件表达式){
    //循环体
}
```
- do-while循环语法：
```java
do{
    //循环体
}while(循环条件表达式);
```
## 条件语句
- Java中有if-else语句，与c语言类似，语法如下：
```java
if(条件表达式){
    //执行语句
}else if(条件表达式){
    //执行语句
}else{
    //执行语句
}
```

- 布尔运算符如下：
   - `&&` 与运算
   - `||` 或运算
   - `!` 非运算
   - `==` 等于

## 函数声明使用
- Java中函数声明使用，语法如下：
```java
修饰符 返回值类型 函数名(参数类型 参数名, ...){
    //函数体
}
```
- 修饰符：`public、private、protected、static、final、abstract、synchronized、native、transient、volatile`，之后会详解。
- 返回值类型：函数的返回值类型，可以是基本数据类型、自定义类型、void。
