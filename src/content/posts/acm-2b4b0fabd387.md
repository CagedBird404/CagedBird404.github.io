---
title: "3继承中的对象模型"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "对于析构和构造函数\r 顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于析构和构造函数 顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

对于析构和构造函数
顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
对于析构和构造函数
顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构
*/

#include<bits/stdc++.h>
using namespace std;

//继承中的对象模型
class base
{
public:

    int a;

protected:

    int b;

private:

    int c;
};
//对象中的私有也会继承到子类中，占内存
//父类中所有非静态成员属性都会被继承到子类
//父类中私有成员属性 只是被编译器隐藏了，不能访问但是被继承下去了

class son:public base
{
public:

    int d;
};

void text01()
{
    son k;
    cout << sizeof(k) << endl;
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

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-2b4b0fabd387.cpp)
