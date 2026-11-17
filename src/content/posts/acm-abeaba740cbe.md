---
title: "4const修饰成员函数"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "常函数：\r      成员函数加const后我们称这个函数为常函数\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

常函数：      成员函数加const后我们称这个函数为常函数

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

常函数：
* 成员函数加const后我们称这个函数为常函数
* 常函数内不可以修改成员属性
* 成员属性声明时加关键字mutable后，在常函数中依旧可以修改
常对象：
* 声明对象前加const称该对象为常对象
* 常对象只能调用常函数

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
常函数：
    * 成员函数加const后我们称这个函数为常函数
    * 常函数内不可以修改成员属性
    * 成员属性声明时加关键字mutable后，在常函数中依旧可以修改

常对象：
    * 声明对象前加const称该对象为常对象
    * 常对象只能调用常函数
*/
#include<bits/stdc++.h>
using namespace std;

class Person
{
public:
    //this指针本质是指针常量，指针的指向是不可以修改的 可理解为 Person* const（this 不能被重新赋值）。
    void showPerson() const // 通过 this 访问对象时，对象被视为 const；mutable 成员除外。
    {
        //this -> a = 100;
        this -> b = 100;
    }
    int a = 0;
    mutable int b = 0; //加上mutable后即使加上const也可以修改
};

int main()
{
    //常对象，属性不可以修改
    const Person p;
    //但是mutable修饰后可以修改
    p.b = 100;
    //常对象只能调用常函数
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

