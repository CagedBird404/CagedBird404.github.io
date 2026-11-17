---
title: "二分搜索"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治"]
description: "二分搜索的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

二分搜索的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

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

