---
title: "有依赖的背包"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划"]
description: "这份模板处理树形依赖背包：选子物品必须选父物品。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

这份模板处理树形依赖背包：选子物品必须选父物品。

## 使用前提与复杂度

我用函数接口记录这个模型；物品 1..n，0 是虚根，parent[i]=0 表示无父依赖，父关系必须为森林。

**复杂度：** O(nV²) 时间，O(nV) 空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dependencyKnapsack(int capacity, const vector<int>& parent,
                       const vector<int>& cost, const vector<i64>& value) {
    int n = (int)parent.size() - 1;
    vector<vector<int>> children(n + 1);
    for (int i = 1; i <= n; ++i) children[parent[i]].push_back(i);
    const i64 NEG = -(1LL << 60);
    function<vector<i64>(int)> dfs = [&](int u) {
        vector<i64> dp(capacity + 1, NEG);
        int c = u == 0 ? 0 : cost[u];
        if (c > capacity) return dp;
        dp[c] = u == 0 ? 0 : value[u];
        for (int v : children[u]) {
            auto sub = dfs(v);
            auto next = dp;  // 可以不选这个子树。
            for (int a = c; a <= capacity; ++a) if (dp[a] != NEG)
                for (int b = 0; a + b <= capacity; ++b) if (sub[b] != NEG)
                    next[a + b] = max(next[a + b], dp[a] + sub[b]);
            dp.swap(next);
        }
        return dp;
    };
    auto dp = dfs(0);
    return *max_element(dp.begin(), dp.end());
}
```

## 相关知识点

[动态规划](/posts/acm-keywords/#dp) · [状态压缩](/posts/acm-keywords/#bitmask) · [二分查找](/posts/acm-keywords/#binary-search)

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)
- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)

