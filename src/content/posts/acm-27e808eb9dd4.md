---
title: "分组背包问题"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划","已修订"]
description: "物品按组划分，每组至多选择一件。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

物品按组划分，每组至多选择一件。

## 使用前提与复杂度

用上一组的 dp 转移到 next，不依赖组号连续，也不会重复选同一组。

**复杂度：** O(V × 物品总数) 时间，O(V) 空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 groupedKnapsack(int capacity, const vector<vector<pair<int, i64>>>& groups) {
    vector<i64> dp(capacity + 1);
    for (const auto& group : groups) {
        auto next = dp;  // 不选当前组。
        for (auto [cost, value] : group)
            for (int j = cost; j <= capacity; ++j)
                next[j] = max(next[j], dp[j - cost] + value);
        dp.swap(next);
    }
    return dp[capacity];
}
```

## 相关知识点

[动态规划](/posts/acm-keywords/#dp) · [状态压缩](/posts/acm-keywords/#bitmask) · [二分查找](/posts/acm-keywords/#binary-search)

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)
- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)

## 整理记录

本次对代码进行了修订或补全：用上一组的 dp 转移到 next，不依赖组号连续，也不会重复选同一组。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-27e808eb9dd4.cpp)
