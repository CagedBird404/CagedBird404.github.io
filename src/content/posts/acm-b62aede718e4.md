---
title: "分解质因数"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论","已修订"]
description: "把正整数分解为不同质因子。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

把正整数分解为不同质因子。

## 使用前提与复杂度

剩余的大质因子在循环结束后加入，不能放在循环内部；用 d≤n/d 避免 d*d 溢出。

**复杂度：** O(√n) 时间，O(log n) 输出空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> primeFactors(i64 n) {
    vector<i64> factors;
    for (i64 d = 2; d <= n / d; ++d) {
        if (n % d != 0) continue;
        factors.push_back(d);
        while (n % d == 0) n /= d;
    }
    if (n > 1) factors.push_back(n);
    return factors;
}
```

## 相关知识点

[素数](/posts/acm-keywords/#prime) · [GCD](/posts/acm-keywords/#gcd) · [逆元](/posts/acm-keywords/#inverse) · [欧拉函数](/posts/acm-keywords/#phi) · [快速幂](/posts/acm-keywords/#fast-power)

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)
- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)
- [求逆](/posts/acm-efd4aac231ba/)

## 整理记录

本次对代码进行了修订或补全：剩余的大质因子在循环结束后加入，不能放在循环内部；用 d≤n/d 避免 d*d 溢出。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-b62aede718e4.cpp)
