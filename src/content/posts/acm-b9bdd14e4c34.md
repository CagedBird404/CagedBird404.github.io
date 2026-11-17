---
title: "7函数调用运算符重载"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "7函数调用运算符重载的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

7函数调用运算符重载的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

<!-- ACM_VALIDATION -->

## 代码

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

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-b9bdd14e4c34.cpp)
