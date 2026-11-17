---
title: "类对象作为类成员"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "类对象作为类成员的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

类对象作为类成员的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

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

