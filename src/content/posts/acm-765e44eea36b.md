---
title: "数学符号"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "数学符号的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

数学符号的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int mainn(){
    int x,a,b;
    //根号
    sqrt(x);
    //绝对值
    abs(x);
    fabs(x);//输出浮点数
    //向上取整
    ceil(x);
    //向下取整
    floor(x);
    //四舍五入
    round(x);
    //幂函数
    pow(a,b);
}
```

## 相关知识点

[复杂度](/posts/acm-keywords/#complexity)

- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-765e44eea36b.cpp)
