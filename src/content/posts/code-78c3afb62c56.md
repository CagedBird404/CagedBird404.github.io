---
title: "基础 · 面向对象 · 类和对象 · 3c++对象模型和this指针"
published: 2026-11-16
category: "基础"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 1成员变量和成员函数分开储存

原文件：`基础/面向对象/类和对象/3c++对象模型和this指针/1成员变量和成员函数分开储存.cpp`

```cpp
/*
在c++中成员变量和成员函数分开存储
只有非静态成员变量才属于类上的对象
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    int a;
    static int b;
};
int Person::b = 10;

int main()
{
    Person p1;//空的情况下，占用一个字节
              //非空才是正常字节计算
              //静态是不占字节的，他不属于类上对象
              //成员函数都不属于类的对象上
}
```

## 2this指针概念

原文件：`基础/面向对象/类和对象/3c++对象模型和this指针/2this指针概念.cpp`

```cpp
/*
成员函数会被重复多次使用，实际上他们访问的都是一块代码
问题：那么他们是怎么区分哪个对象调用自己的？

用this指针
* this指针指向被调用的成员函数所属的对象
this指针是隐含在每一个非静态成员函数的一种指针
this指针不需要定义，直接使用即可

作用：
1、当形参和成员变量同名时，可以用this指针来区分
2、在类的非静态成员函数返回对象本身时，可以用 return *this
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //解决名称冲突
    Person(int age)
    {
        this -> age = age;
    }

    Person& Personadd(Person &p)
    {
        this -> age += p.age;
        return *this; //返回的是p2本身
    }
    int age;
};

void text01()
{
    Person p1(18);
    cout << p1.age;
}

void text02()
{
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.Personadd(p1).Personadd(p1).Personadd(p1);
    cout << p2.age << endl;
}
int main()
{
    text02();
}
```

## 3空指针判断成员函数

原文件：`基础/面向对象/类和对象/3c++对象模型和this指针/3空指针判断成员函数.cpp`

```cpp
/*
c++中空指针也是可以调用成员函数的，但是也要主要有没有用到this指针

如果用到this指针，需要加以判断保证代码的健壮性
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:

void showClassName()
{
    cout << "this is a person class" << endl;
}

void showAge()
{
    if(this == NULL) return;
    cout << "Age = " <<this -> Age << endl;
}

    int Age; 
};

void text01()
{
    Person * p = NULL; //空指针代表本来也没有建立对象
    p -> showClassName();//可以运行
    p -> showAge();//不可以,报错原因是因为传入的指针为空
}

int main()
{

}
```

## 4const修饰成员函数

原文件：`基础/面向对象/类和对象/3c++对象模型和this指针/4const修饰成员函数.cpp`

```cpp
/*
常函数：
    * 成员函数加const后我们称这个函数为常函数
    * 常函数内不可以修改成员属性
    * 成员属性声明时加关键字mutable后，在常函数中依旧可以修改

常对象：
    * 声明对象前加const称该对象为常对象
    * 常对象只能调用常函数
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //this指针本质是指针常量，指针的指向是不可以修改的 相当于 Person const * this;
    void showPerson() const // 相当于 const Person const * this;
    {
        //this -> a = 100;
        this -> b = 100;
    }
    int a;
    mutable int b; //加上mutable后即使加上const也可以修改
};

int main()
{
    //常对象，属性不可以修改
    const Person p;
    //但是mutable修饰后可以修改
    p.b = 100;
    //常对象只能调用常函数
}
```

