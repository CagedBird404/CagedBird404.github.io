---
title: "3递增运算符重载"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "3递增运算符重载的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

3递增运算符重载的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

<!-- ACM_VALIDATION -->

## 代码

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

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-bcd85814d02b.cpp)
