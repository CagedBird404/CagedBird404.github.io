---
title: "初始化列表"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "列表法：作用为初始化属性\r 语法：构造函数():属性1(值1),属性2(值2)"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

列表法：作用为初始化属性 语法：构造函数():属性1(值1),属性2(值2)

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

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
    // 初始化列表
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

