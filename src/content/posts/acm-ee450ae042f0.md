---
title: "函数重载"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "作用：函数名可以形同，提高复用性\r 函数重载满足条件：\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

作用：函数名可以形同，提高复用性 函数重载满足条件：

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

作用：函数名可以形同，提高复用性
函数重载满足条件：
* 同一个作用域下
* 函数名称相同
* 函数参数类型不同 或者 个数不同 或者 顺序不同

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
作用：函数名可以形同，提高复用性

函数重载满足条件：
* 同一个作用域下
* 函数名称相同
* 函数参数类型不同 或者 个数不同 或者 顺序不同
*/
#include<bits/stdc++.h>
using namespace std;

void func()
{
    cout << "hello world";
}

void func(int a,double b)
{
    cout << "hello world";
}
void func(double a,int b)    //这个类型必须相同，就像这些都是void
{
    cout << "hello world";
}

//函数重载注意事项
//1、引用作为重载条件
//2、函数语法相同，要避免重载时存在多种可以处理的情况
void cc(int &a)
{
    cout << "cc" << endl;
}
void cc(const int &a)
{
    cout << "ccc" << endl;
}
int main(){
    int a = 10;
    func();
    func(10,3.14);
    func(3.14,10);
    cc(a);//调用,加了引用，那么就要传变量
    cc(10);//调用const的
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

