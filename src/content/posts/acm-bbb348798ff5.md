---
title: "初始化列表"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "列表法：作用为初始化属性\r 语法：构造函数():属性1(值1),属性2(值2)"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

列表法：作用为初始化属性 语法：构造函数():属性1(值1),属性2(值2)

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

列表法：作用为初始化属性
语法：构造函数():属性1(值1),属性2(值2)

<!-- ACM_VALIDATION -->

## 代码

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

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-bbb348798ff5.cpp)
