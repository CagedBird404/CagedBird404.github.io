---
title: "基础 · 面向对象 · 类和对象 · 2对象的初始化和清理"
published: 2026-11-16
category: "基础"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 初始化列表

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/初始化列表.cpp`

```cpp
/*
列表法：作用为初始化属性
语法：构造函数():属性1(值1),属性2(值2)
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a;
    int b;
    int c;
    //传统初始化操作
    Person(int aa,int bb,int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }

    //初始化列表
    Person(int aa,int bb,int cc):a(aa),b(bb),c(cc)
    {

    }
};
int main()
{

}
```

## 拷贝构造函数调用时机

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/拷贝构造函数调用时机.cpp`

```cpp
/*
调用使用时机一般有三种
* 使用一个已经创造完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象
*/
#include<bits/stdc++.h>
using namespace std;

class Person{
public:
    Person(){
        cout << "无参构造函数！" << endl;
        mAge = 0;
    }
    Person(int age)
    {
        cout << "有参构造函数！" << endl;
        mAge = age;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数！" << endl;
        mAge = p.mAge;
    }
    ~Person()
    {
        cout << "析构函数！" << endl;
    }

private:
    int mAge;
};

//值传递的方式给函数参数传值
void dowork(Person p) //这只是一个临时的参数，属于新构造一个，不会改变原p的值
{
     
}

void text1()
{
    Person p;
    dowork(p);//属于拷贝构造函数
}

//值方式返回局部对象
Person dowork2()
{
    Person p1;
    return p1;
}

void text3()
{
    Person p = dowork2();// 属于拷贝构造函数
}
int main()
{
    //使用一个已经创造完毕的对象来初始化一个新对象
    Person p1(20);
    Person p2(p1);
}
```

## 构造函数和析构函数

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/构造函数和析构函数.cpp`

```cpp
/*
对象的初始化和清理
* 生活中我们买电子产品基本都会有初始化设置，在某一天不用的时候也会删除一些自己信息数据保证安全
* C++中的面相对象来源于生活，每个对象都会有初始设置和 对象销毁前的清理数据的设置

一个对象或者变量没有初始状态
或者没有使用完清理，那么会有安全的问题

c++利用了构造函数和析构函数解决
注：如果我们不提供构造函数和析构函数，那么编译器会提供
    但是编译器提供的是空实现的

构造函数语法： 类名(){}
    1、构造函数，没有返回值也不写void
    2、函数名称与类名相同
    3、构造函数可以有参数，因此可以发生重载
    4、程序在调用对象时候会自动调用，无需手动操作，而且只会调用一次

析构函数语法： ~类名(){}
    1、构造函数，没有返回值也不写void
    2、函数名与类名相同，在名称前加上~
    3、析构函数不可以有参数，所以不可以发生重载
    4、程序在对象销毁前会自动调用析构，无需手动操作，而且只会调用一次
*/
#include<bits/stdc++.h>
using namespace std;

//1、构造函数
class Person
{
public:
    Person()
    {
        cout<< 1 << endl;
    }
    ~Person()
    {
        cout << 2 << endl;
    }
};

void text1()
{
    Person p; //在栈上的数据，text1执行完毕就会释放这个对象
}
int main()
{
    text1();
    Person p1;//只有构造没有析构

    system("pause");//因为有这个，程序中断，但是还没结束main函数，所以还没有析构，去掉就有了
    return 0;
}
```

## 构造函数的分类及调用

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/构造函数的分类及调用.cpp`

```cpp
/*
两种分类方式：
    1、按照参数：有参构造和无参构造
    2、按照类型：普通构造和拷贝构造

三种调用方法：
    1、括号法
    2、显示法
    3、隐式转换法
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //普通构造函数
    Person()//默认构造函数
    {
        cout << "无参构造" << endl;
    }
    Person(int a)
    {
        cout << "有参构造函数" << endl;
    }
    //拷贝构造函数
    Person(const Person &p)
    {
        //将传入的这个人身上的属性，传到我身上
        cout << "拷贝构造函数" << endl;
        age = p.age;
    }

    int age = 10;
};

void text1()
{
    //1、括号法
    Person p; // 默认构造函数不要加()
              // 因为加括号的代码，编译器会认为是一个函数声明,不会认为在创建对象
              // 例如 void cc();
    Person p1(10);
    Person(p1); // 拷贝构造函数
    cout << p2.age << endl;
    cout << p3.age << endl;

    //2、显示法
    Person p1;
    Person p2 = Person(10);//有参构造
    Person p3 = Person(p2);//拷贝构造
    //不能利用拷贝构造函数，初始化匿名对象，例如  Person(p1);这可以看成再创建一个叫p3的对象
    Person(10);//匿名对象， 特点：当执行完结束后，系统会立即回收,所以会执行析构函数

    //3、隐式转换法
    Person p4 = 10;//相当于Person p4 = Person(10);
    Person p5 = p4;//拷贝构造
}
int main()
{
    text1();
}
```

## 构造函数的调用规则

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/构造函数的调用规则.cpp`

```cpp
/*
默认情况下，c++编译器至少给一个类添加三个函数
1、默认构造函数
2、默认析构函数（都是无参，函数体为空）
3、默认拷贝构造函数，对属性进行值拷贝

* 如果用户定义有参构造函数 c++不再提供无参构造函数 但是会提供默认构造函数
* 如果用户定义拷贝构造函数 c++不会再提供其他构造函数
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    
}
```

## 深拷贝和浅拷贝

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/深拷贝和浅拷贝.cpp`

```cpp
/*
浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "默认构造函数调用" << endl;
    }
    Person(int age,int height)
    {
        cout << "有参构造函数"  << endl;
        Age = age;
        Height = new int(height);//由我们开启，就要由我们释放
    }
    //自己创建一个深拷贝
    Person(const Person &p)
    {
        cout << "拷贝构造函数" << endl;
        Age = p.Age;
        Height = new int(*p.Height); 
    }
    ~Person()
    {
        //在析构函数中，将堆区开辟数据释放
        if(Height != NULL)
        {
            delete Height;
            Height = NULL;
        }
        cout << "析构函数调用" << endl;
    }
    int Age;
    int *Height;//指针
};

void text1()
{
    Person p1(18,185);
    Person p2(p1);
    //浅拷贝是将数据直接拷贝过去，即使是地址，也是直接过去，所以p2先进行释放，p1再释放，就会冲突
    //深拷贝会再创建一块堆区内存，和p1数据一样，但是地址不一样
}
int main()
{
    text1();
}
```

## 类对象作为类成员

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/类对象作为类成员.cpp`

```cpp
/*

*/
#include<bits/stdc++.h>
using namespace std;

//类对象作为类成员
class Phone
{
public:
    Phone(string s)
    {
        pname = s;
    }
    string pname;
};

class Person
{
public:

    Person(string s1,string s2):name(s1),p(s2) // 先构造phone,后释放phone
    {

    }

    string name;
    Phone p;
};

void text1()
{
    Person("zhangsan","huawei");
}
int main()
{

}
```

## 静态成员

原文件：`基础/面向对象/类和对象/2对象的初始化和清理/静态成员.cpp`

```cpp
/*
静态成员分为：静态成员变量，静态成员函数

静态成员变量
    1、所有对象共享一份数据,所有成员都指向
    2.在编译阶段分配内存
    3.类内声明，类内初始化   必须有初始值

静态成员函数
    1.所有对象共享一个函数
    2.静态成员函数只能访问静态成员变量
*/

//静态成员变量
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //所有对象都共享同一份数据
    static int a;//类内声明，类外初始化

    static void func()
    {
        a = 200;
        cout << "你被调用了" << endl;
    }
    //静态成员变量也有访问权限
private:
    static int b;
};

int Person::a = 100;
int Person::b = 200;

void text01()
{
    //静态成员变量 不属于某个变量 所有对象都共享同一份数据
    //静态成员变量有两种访问方式
    //1、通过对象进行访问

    Person p1;
    cout << p1.a << endl;
    //2、通过类名进行访问

    cout << Person::a << endl;
}

void text02()
{
    Person p1;
    p1.func();
    Person::func();
}

int main()
{
    Person p1;
    cout << p1.a << endl;
    Person p2;
    p2.a = 200;
    cout << p1.a << endl;;
}
```

