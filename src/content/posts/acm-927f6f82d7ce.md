---
title: "数位dp"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划"]
description: "我以一个具体模型为例：统计 [0,n] 中不含数字 4 的整数。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

我以一个具体模型为例：统计 [0,n] 中不含数字 4 的整数。

## 使用前提与复杂度

数位 DP 没有脱离题意的统一转移；我以“不含 4”为例记录状态转移，0 计入，n≤10^18。

**复杂度：** O(位数 × 10) 时间，O(位数) 记忆化空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 countWithout4(i64 n) {
    if (n < 0) return 0;
    string digits = to_string(n);
    vector<i64> memo(digits.size(), -1);
    function<i64(int, bool)> dfs = [&](int pos, bool tight) -> i64 {
        if (pos == (int)digits.size()) return 1;
        if (!tight && memo[pos] != -1) return memo[pos];
        int limit = tight ? digits[pos] - '0' : 9;
        i64 ans = 0;
        for (int d = 0; d <= limit; ++d) {
            if (d == 4) continue;
            ans += dfs(pos + 1, tight && d == limit);
        }
        if (!tight) memo[pos] = ans;
        return ans;
    };
    return dfs(0, true);
}
i64 countRangeWithout4(i64 l, i64 r) {
    return countWithout4(r) - (l <= 0 ? 0 : countWithout4(l - 1));
}
```

## 相关知识点

[动态规划](/posts/acm-keywords/#dp) · [状态压缩](/posts/acm-keywords/#bitmask) · [二分查找](/posts/acm-keywords/#binary-search)

- [01背包问题](/posts/acm-b56927a13e82/)
- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)

