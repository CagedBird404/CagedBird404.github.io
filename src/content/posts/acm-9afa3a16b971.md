---
title: "拷贝构造函数调用时机"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "调用使用时机一般有三种\r  使用一个已经创造完毕的对象来初始化一个新对象\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

调用使用时机一般有三种  使用一个已经创造完毕的对象来初始化一个新对象

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

调用使用时机一般有三种
* 使用一个已经创造完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象

<!-- ACM_VALIDATION -->

## 代码

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

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-9afa3a16b971.cpp)
