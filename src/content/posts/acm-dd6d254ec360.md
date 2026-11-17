---
title: "类对象作为类成员"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "类对象作为类成员的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

类对象作为类成员的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

<!-- ACM_VALIDATION -->

## 代码

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

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-dd6d254ec360.cpp)
