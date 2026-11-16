---
title: "基础 · 面向对象 · 函数提高"
published: 2026-11-16
category: "基础"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 函数提高

原文件：`基础/面向对象/函数提高/函数提高.cpp`

```cpp
/*

*/
#include<bits/stdc++.h>
using namespace std;

int Add(int a,int b = 20,int c = 30) //如果某个位置有了默认值，那么从这起右面都必须有默认值
{                                    //如果函数声明有参数，实现就不能有，声明和实现只能有一个有默认参数
    return a+b+c;
}

void func(int a,int)  //进行站位
{
    cout << "hello world" << endl;
}
void func1(int a,int  = 10)  //还可以这样，直接不用传值；
{
    cout << "hello world" << endl;;
}
int main()
{
    cout << Add(10) << endl;    //不用传另外两个
    cout << Add(10,30) << endl; //传进去的会覆盖函数里的值
    func(10,10);
    func1(10);
}
```

## 函数重载

原文件：`基础/面向对象/函数提高/函数重载.cpp`

```cpp
/*
作用：函数名可以形同，提高复用性

函数重载满足条件：
* 同一个作用域下
* 函数名称相同
* 函数参数类型不同 或者 个数不同 或者 顺序不同
*/
#include<bits/stdc++.h>
using namespace std;

void func()
{
    cout << "hello world";
}

void func(int a,double b)
{
    cout << "hello world";
}
void func(double a,int b)    //这个类型必须相同，就像这些都是void
{
    cout << "hello world";
}

//函数重载注意事项
//1、引用作为重载条件
//2、函数语法相同，要避免重载时存在多种可以处理的情况
void cc(int &a)
{
    cout << "cc" << endl;
}
void cc(const int &a)
{
    cout << "ccc" << endl;
}
int main(){
    int a = 10;
    func();
    func(10,3.14);
    func(3.14,10);
    cc(a);//调用,加了引用，那么就要传变量
    cc(10);//调用const的
}
```

