---
title: "1成员变量和成员函数分开储存"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "在c++中成员变量和成员函数分开存储\r 只有非静态成员变量才属于类上的对象"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

在c++中成员变量和成员函数分开存储 只有非静态成员变量才属于类上的对象

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

在c++中成员变量和成员函数分开存储
只有非静态成员变量才属于类上的对象

<!-- ACM_VALIDATION -->

## 代码

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

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

