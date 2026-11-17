---
title: "STL search"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器","学习实现"]
description: "对于search可以在一个大容器中返回小容器出现的位置\r 和find类似但是这个是对于两个容器\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于search可以在一个大容器中返回小容器出现的位置 和find类似但是这个是对于两个容器

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

对于search可以在一个大容器中返回小容器出现的位置
和find类似但是这个是对于两个容器
[复杂度](/posts/acm-keywords/#complexity)为暴力

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
对于search可以在一个大容器中返回小容器出现的位置
和find类似但是这个是对于两个容器
复杂度为暴力
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5, 3, 4};
    std::vector<int> sub = {3, 4};

    auto it = std::search(v.begin(), v.end(), sub.begin(), sub.end());

    if (it != v.end()) {
        std::cout << "Found at position: " << it - v.begin() << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [优先队列](/posts/acm-keywords/#heap) · [复杂度](/posts/acm-keywords/#complexity)

- [STL priority（排序优化）](/posts/acm-a4adadab1a7a/)
- [Dijkstra](/posts/acm-38c0561d770b/)
- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-4e7a7687cff6.cpp)
