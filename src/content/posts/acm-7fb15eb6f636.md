---
title: "构造函数的调用规则"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "默认情况下，c++编译器至少给一个类添加三个函数\r 1、默认构造函数\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

默认情况下，c++编译器至少给一个类添加三个函数 1、默认构造函数

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

默认情况下，c++编译器至少给一个类添加三个函数
1、默认构造函数
2、默认析构函数（都是无参，函数体为空）
3、默认拷贝构造函数，对属性进行值拷贝
* 如果用户定义有参构造函数 c++不再提供无参构造函数 但是会提供默认构造函数
* 如果用户定义拷贝构造函数 c++不会再提供其他构造函数

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
默认情况下，c++编译器至少给一个类添加三个函数
1、默认构造函数
2、默认析构函数（都是无参，函数体为空）
3、默认拷贝构造函数，对属性进行值拷贝

* 如果用户定义有参构造函数 c++不再提供无参构造函数 但是会提供默认构造函数
* 如果用户定义拷贝构造函数 c++不会再提供其他构造函数
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    
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

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-7fb15eb6f636.cpp)
