---
title: "1继承基本语法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "继承好处：减少重复代码\r 语法 ： class 子类: 继承方式 父类\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

继承好处：减少重复代码 语法 ： class 子类: 继承方式 父类

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

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

