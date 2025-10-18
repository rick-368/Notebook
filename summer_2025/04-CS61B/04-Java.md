# 列表
## 简易实现
- java中有列表类，可以通过ArrayList、LinkedList等类来实现。 
- java中的列表与c中的链表类似，是一种递归的数据结构。
```java
public class IntList{
    public int first;
    public IntList rest;
    public IntList(int f, IntList r){
        first = f;
        rest = r;
    }
/* 返回列表的长度 */
    public int length(){
        if(rest == null)
            return 1;
        else
            return 1 + rest.length();
    }
/* 返回列表的长度(非递归) */
    public int length2(){
        int len = 1;
        IntList current = this;
        while(current.rest!= null){
            len++;
            current = current.rest;
        }
        return len;
    }
/* 获取指定位置的元素 */
    public void get(int index){
        if(index == 0){
            return first;
        }
        else{
            return rest.get(index-1);
      }
    }

}

```

## SL列表（单链表）
```java
public class IntNode{
    public int item;
    public IntNode next;
    public IntNode(int i, IntNode n){
        item = i;
        next = n;
    }
}
public class SLList{
    public IntNode first;
    public SLList(int x){
        first = new IntNode(x, null);
    }
    public SLList(){// 空列表
        first = null;
    }
} 
```
- 相较于上文的IntList,SLList将IntNode作为节点单独创建了一个类，这样在新建列表时不必指定空值，因为我们将其隐藏在构造函数内部。
```java
public void addFirst(int x){
    first = new IntNode(x, first);
}
```
- IntList是一种裸递归结构，指针直接指向递归数据结构；而SLList则先定义了节点类，作为中间人进行递归调用，这样可以避免了递归的考虑。
```java
/* IntList */
IntList L = new IntList(15,null);
L = new IntList(10,L);
L = new IntList(5,L);
/* SLList */
SLList L2 = new SLList(15);
L2.addFirst(10);
L2.addFirst(5);
```
- 若不允许用户擅自对节点进行操作，致使错误，则可以使用private修饰符，使得节点只能在SLList内进行操作。
```java
public class SLList{
    private IntNode first;
}
```
- 类是可以嵌套的，你也可以直接将IntNode定义在SLList中，这样可以避免单独创建节点类，同样也可以使用前置private修饰符来避免对节点类的直接使用。 
- 在SLList中，我们可以定义一些变量实时跟踪列表的变化，比如长度，这样在需要的时候可以直接获取，而不需要遍历整个列表。
```java
public class SLList{
    private int length;
    private IntNode first;
    public SLList(int x){
        first = new IntNode(x, null);
        length = 1;
    }
    public void addFirst(int x){
        first = new IntNode(x, first);
        length++;
    }
    public int getLength(){
        return length;
    }
}
```
- 反之，在IntList中，则没有合适的变量来实时跟踪列表的变化，只能通过遍历来获取长度。

## 哨兵节点
- 在SLList中，我们可以定义一个哨兵节点，作为列表的头节点，这样可以简化对列表的操作。
```java
public class SLList{
    private IntNode sentinel;
    public SLList(int x){
        sentinel = new IntNode(0, null);
        sentinel.next = new IntNode(x, null);
    }
    public SLList(){
        sentinel = new IntNode(0, null);
    }
    public void addFirst(int x){
        sentinel.next = new IntNode(x, sentinel.next);
    } 
}
```
- 在有哨兵节点之前，有些方法我们需要先判断列表是否为空，比如addLast
```java
public void addLast(int x){
    if(first == null){
        first = new IntNode(x, null);
    }

    IntNode p = first;
    while(p.next!= null){
        p = p.next;
    }
    p.next = new IntNode(x, null);
}
```
- 而在有哨兵节点之后，我们可以规避特殊情况的判断，直接操作sentinel.next即可。
```java
public void addLast(int x){
    IntNode p = sentinel;
    while(p.next!= null){
        p = p.next;
    }
    p.next = new IntNode(x, null);
}
```

## DL列表（双链表）
- 双链表与单链表类似，只是每个节点除了存储数据，还存储了指向前驱节点的指针。
```java
public class DLNode{
    public int item;
    public DLNode prev;
    public DLNode next;
}
```
- 同样的，除了头节点，我们还可以定义一个哨兵节点，作为列表的尾节点，从而规避一些特殊情况讨论。当然，**更好的解决办法是创建一个循环列表**，这样只需要一个哨兵节点就足够了。
## 拓展列表元素类型——泛型
- 在上述定义的列表中，我们都是使用int作为元素类型，但实际上，我们可以定义任意类型的元素，只需要修改节点类即可。
- 另外一个方法是使用泛型，定义一个泛型类，然后在节点类中使用泛型变量。                                                                                
```java
public class SLList<T>{
    private class Node{
        public T item;
        public Node next;
        public Node(T i, Node n){
            item = i;
            next = n;
        }
    }
    public SLList(){
        sentinel = new Node(null, null);
    }
    ...

    public static void main(String[] args) {
        SLList<String> L = new SLList<String>();// 定义一个字符串列表
        L.addFirst("hello");
        SLList<Integer> L2 = new SLList<>();// 定义一个整数列表（右侧尖号内的类型可省）
        L2.addFirst(10);
    }
}
```