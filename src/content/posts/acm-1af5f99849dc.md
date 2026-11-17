---
title: "STL list"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器","已修订"]
description: "双向链表在已知迭代器处进行插入删除。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

双向链表在已知[迭代器](/posts/acm-keywords/#iterator)处进行插入删除。

## 使用前提与[复杂度](/posts/acm-keywords/#complexity)

erase 后该[迭代器](/posts/acm-keywords/#iterator)失效；unique 仅删除相邻重复值。不能把已失效的 it 传给 splice。

**[复杂度](/posts/acm-keywords/#complexity)：** 已知位置插删 O(1)，寻找位置 O(n)，排序 O(n log n)。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    list<int> values{1, 2, 3};
    values.push_front(0); values.push_back(4);
    auto it = next(values.begin(), 2);
    values.insert(it, 99);
    it = values.erase(it);  // 接收下一个有效位置。
    list<int> extra{6, 7};
    values.splice(it, extra);
    values.sort(); values.unique();
    for (int x : values) cout << x << ' ';
    cout << '\n';
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

本次对代码进行了修订或补全：erase 后该[迭代器](/posts/acm-keywords/#iterator)失效；unique 仅删除相邻重复值。不能把已失效的 it 传给 splice。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-1af5f99849dc.cpp)
