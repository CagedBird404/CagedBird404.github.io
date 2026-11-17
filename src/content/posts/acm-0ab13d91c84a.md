---
title: "1继承基本语法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "继承好处：减少重复代码\r 语法 ： class 子类: 继承方式 父类\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

继承好处：减少重复代码 语法 ： class 子类: 继承方式 父类

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

继承好处：减少重复代码
语法 ： class 子类: 继承方式 父类
子类也称为派生类，父类也称为基类

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
继承好处：减少重复代码

语法 ： class 子类: 继承方式 父类
子类也称为派生类，父类也称为基类
*/

#include<bits/stdc++.h>
using namespace std;

class gg
{
public:
    void sh()
    {
        cout << "kaitou" << endl;
    }
    void mu()
    {
        cout << "mulu" << endl;
    }
    void ji()
    {
        cout << "jiewei" << endl;
    }

};

class Gcc : public gg
{
public:
    void zj()
    {
        cout << "gcc shipin" << endl;
    }
};
class java : public gg
{
public:

    void zj()
    {
        cout << "java shipin" << endl;
    }

};

class python : public gg
{
public:

    void zj()
    {
        cout << "python shipin" << endl;
    }
};

void text01()
{
    java ja;
    ja.sh(),ja.mu(),ja.zj(),ja.ji();
    python py;
    py.sh(),py.mu(),py.zj(),py.ji();
    Gcc gk;
    gk.sh(),gk.mu(),gk.zj(),gk.ji();
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

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-0ab13d91c84a.cpp)
