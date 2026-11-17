---
title: "STL search"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器"]
description: "对于search可以在一个大容器中返回小容器出现的位置\r 和find类似但是这个是对于两个容器\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于search可以在一个大容器中返回小容器出现的位置 和find类似但是这个是对于两个容器

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

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

