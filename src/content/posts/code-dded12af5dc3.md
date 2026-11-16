---
title: "基础 · 面向对象 · 类和对象 · 5运算符重载"
published: 2026-11-16
category: "基础"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 1加号运算符重载

原文件：`基础/面向对象/类和对象/5运算符重载/1加号运算符重载.cpp`

```cpp
/*
运算符重载定义：对已有的运算符重新定义，赋予其另一种功能，以适应不同数据类型

对于内置的数据类型，编译器知道如何运算
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:

    int a,b;

//成员函数重载
    Person operator+(Person &p)
    {
        Person temp;
        temp.a = this -> a + p.a;
        temp.b = this -> b + p.b;
        return temp;
    }

    Person()
    {
        a = 10;
        b = 10;
    }
};

//全局函数重载
Person operator+(Person &p1,Person &p2)
{
    Person temp;
    temp.a = p1.a + p2.a;
    temp.b = p1.b + p2.b;
    return temp;
}

Person operator+(Person &p1,int num)
{
    Person temp;
    temp.a = p1.a + num;
    temp.b = p1.b + num;
    return temp;
}

void text01()
{
    Person p1;
    p1.a = 10;
    p1.b = 29;
    Person p2;
    p2.a = 38;
    p2.b = 48;
    //成员函数重载本质调用：Person p3 = p1.operator+(p2);

    //全局函数重载本质调用： person p3 = operator+(p1,p2);
    Person p3 = p1 + p2;
    cout << p3.a << " " << p3.b << endl;

    Person p4 = p3 + 100;
    cout << p4.a << " " << p4.b;
}

int main(){
    text01();   
}
```

## 2左移运算符重载

原文件：`基础/面向对象/类和对象/5运算符重载/2左移运算符重载.cpp`

```cpp
/*
左移运算符的重载
*/

#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream &cout,Person p);

private:

    //一般不用成员函数来重载左移运算符。因为cout会在变量左面
    //void operator<<( cout ){}

    int a = 0;
    int b = 0;

};

ostream & operator<<(ostream &cout,Person p) //所有要用全局函数
{
    cout << p.a + p.b;
    return cout;
}

void text01()
{
    Person p1;
    cout << p1;
}

int main(){
    text01();
}
```

## 3递增运算符重载

原文件：`基础/面向对象/类和对象/5运算符重载/3递增运算符重载.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream& cout, Person p1);

public:

    //重载前置++运算符
    Person& operator++()
    {
        this -> a++;
        this -> b++;
        return *this;
    }

    Person operator++(int) //int 代表占位参数，可以用于区分前置++和后置++
    {
        Person p1 = *this;
        this -> a++;
        this -> b++;
        return p1;// 返回值，返回的引用是局部引用，会被释放
    }
    //重载后置++运算符
    
    int a = 0;
    int b = 0;
};

ostream & operator<<(ostream& cout, Person p1)
{
    cout << p1.a + p1.b;
    return cout;
}



void text01()
{
    Person p1;
    cout << p1 << endl;
    cout << ++(++p1) << endl;
    cout << p1 << endl;
}

void text02()
{
    Person p1;
    cout << p1 << endl;
    cout << p1++ << endl;
    cout << p1 << endl;
}

int main(){
    text01();
    text02();
}
```

## 4递减运算符

原文件：`基础/面向对象/类和对象/5运算符重载/4递减运算符.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend ostream & operator<<(ostream& cout , Person p1);

public:

    Person& operator--()
    {
        this -> a--;
        this -> b--;
        return *this;
    }

    Person operator--(int)
    {
        Person p1 = *this;
        this -> a--;
        this -> b--;
        return p1;
    }

private:
    int a = 1;
    int b = 1;
};

ostream & operator<<(ostream& cout,Person p1)
{
    cout << p1.a + p1.b;
    return cout;
}

    void text01()
    {
        Person p1;
        cout << p1 << endl;
        cout << --p1 << endl;
        cout << p1 << endl;
    }

void text02()
{
    Person p1;
    cout << p1 << endl;
    cout << p1-- << endl;
    cout << p1 << endl; 
}

int main(){
    text01();
    text02();
}
```

## 5赋值重载运算符

原文件：`基础/面向对象/类和对象/5运算符重载/5赋值重载运算符.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

class Person
{
    friend void text01();

public:
    Person & operator=(Person &p1)
    {
        //先释放本身的堆区数据
        if(a != NULL)
        {
            delete a;
            a = NULL;
        }
        a = new int(*p1.a);
        return *this;
    }

    Person(int age)
    {
        a = new int(age);
    }

    ~Person()
    {
        if(a != NULL)
        {
            delete a;
            a = NULL;
        }
    }
private:
    int *a ;

};

void text01()
{
    Person p1(18);
    cout << *p1.a << endl;
    Person p2(20);
    p2 = p1; //浅拷贝两个对应一个内存空间，会重复释放
    cout << *p2.a << endl;
    Person p3(30);
    p1 = p2 = p3;
    cout << *p1.a << " " << *p2.a << " " << *p3.a << endl;
} 

int main(){
    text01();
}
```

## 6关系运算符重载

原文件：`基础/面向对象/类和对象/5运算符重载/6关系运算符重载.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a = 0;
    int b = 0;
    string s;
    Person(int x,int y,string s1):a(x),b(y),s(s1)
    {

    }

    bool operator==(Person p1)
    {
        if(p1.s == this -> s && p1.a == this -> a && p1.b == this -> b) return 1;
        return 0;
    }

    bool operator!=(Person p1)
    {
        if(p1.s == this -> s && p1.a == this -> a && p1.b == this -> b) return 0;
        return 1;
    }

    bool operator>=(Person p1)
    {
        if(p1.s >= this -> s && p1.a >= this -> a && p1.b >= this -> b) return 1;
        return 0;
    }

    bool operator<=(Person p1)
    {
        if(p1.s <= this -> s && p1.a <= this -> a && p1.b <= this -> b) return 1;
        return 0;
    }

    bool operator>(Person p1)
    {
        if(p1.s > this -> s && p1.a > this -> a && p1.b > this -> b) return 1;
        return 0;
    }

    bool operator<(Person p1)
    {
        if(p1.s < this -> s && p1.a < this -> a && p1.b < this -> b) return 1;
        return 0;
    }
};

void text01()
{
    Person p1(10,20,"st");

    Person p2(20,10,"st");

    if(p1 == p2) cout << "p1 和 p2 是相等的" << endl;
    else cout << "不相等" << endl;
}

int main(){
    text01();
}
```

## 7函数调用运算符重载

原文件：`基础/面向对象/类和对象/5运算符重载/7函数调用运算符重载.cpp`

```cpp
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:

    void operator()(string s)
    {
        cout << s << endl;
    }

};

class MyAdd
{
public:
    int operator()(int a,int b)
    {
        return a + b;
    }
};

void text01()
{
    Person p1;
    p1("Hello World");
    //由于使用起来，很像函数调用，所以称为仿函数
    MyAdd add;
    int ret = add(10,20);
    cout << ret << endl;
    cout << MyAdd()(100,100) << endl;//匿名对象
}


int main(){
    text01();
}
```

