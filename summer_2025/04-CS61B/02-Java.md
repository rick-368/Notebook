# 类
## 定义类
```java
public class MyClass {
    // class body
}
```
- 在Java中，所有的方法都必须定义在类中。
- 若想要运行一个程序时，这个程序中必须有一个主方法。
## 创造类
```java
MyClass myObject = new MyClass();
```
- 实例化类：创建一个类的对象，并将其存储在一个变量中。
- 与python不同，java在创建新类时应使用new关键字。
## 类的内容
- 实例变量：类中用于存储数据的变量。
- 静态变量：类中只存储一次的变量，可以通过类名调用。
- 构造方法：类被实例化时，系统自动调用的特殊方法，方法名与类名相同，没有返回值，可以用来初始化实例变量。
- 方法：类中用于执行特定功能的函数，方法又分为实例方法和静态方法。
   - 实例方法（不加static关键字）：可以访问类的实例变量，可以通过对象调用。
   - 静态方法：不依赖于实例变量，可以通过类名调用。
```java
public class Dog {
    public int age;// 实例变量
    public static String binomen = "Canis lupus familiaris";// 静态变量
    public Dog(int getage) {// 构造方法
        age = getage;
    }
    public static void bark() {// 静态方法
        System.out.println("Woof!");
    }
    public void ageIncr() {// 实例方法
        age++;
    }
    public static Dog getOldest(Dog d1, Dog d2) {
        if (d1.age > d2.age) {
            return d1;
        } else {
            return d2;
        }
    }// 静态方法
    public Dog getOldest(Dog d2) {
        if (this.age > d2.age) {
            return this;
        } else {
            return d2;
        }
    }// 实例方法
    public static void main(String[] args) {
        System.out.println(Dog.binomen);
        Dog myDog = new Dog(3);
        myDog.ageIncr();
        myDog.bark();
        Dog myOldest = getOldest(new Dog(5), myDog);//Dog myOldest = myDog.getOldest(new Dog(5));
        System.out.println("The oldest dog is " + myOldest.age);
    }// 主方法
}
```
## 导入现有类
```java
import java.util.ArrayList; // 导入ArrayList类
```
- 导入类后，可以使用类名调用类中的方法。