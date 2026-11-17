---
title: "二分搜索"
published: 2026-11-16
category: ACM竞赛模板
tags: ["已修订","基础算法·搜索与分治","学习实现"]
description: "二分搜索的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

二分搜索的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
int binarySearch(const vector<long long>& a, long long x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = l + (r-l)/2;
        if (a[mid] < x) l = mid+1; else r = mid;
    }
    return l < (int)a.size() && a[l] == x ? l : -1;
}
// O(log n) 时间，O(1) 额外空间。
```

## 相关知识点

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)

## 整理记录

**本次修正：** 补全二分搜索；要求数组升序，返回第一次出现的 0 基下标，找不到返回 −1。

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-c39b0f67aec5.cpp)
