---
title: "03二元一次方程"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论"]
description: "求 ax+by=c 的一组整数解。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

求 ax+by=c 的一组整数解。

## 使用前提与复杂度

有解当且仅当 gcd(a,b) 整除 c；不是 x 必须为 gcd 的倍数。系数和解限定在 long long 可表示范围。

**复杂度：** O(log min(|a|,|b|)) 时间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 exgcd(i64 a, i64 b, i64& x, i64& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    i64 x1, y1;
    i64 g = exgcd(b, a % b, x1, y1);
    x = y1; y = x1 - (a / b) * y1;
    return g;
}
bool linearEquation(i64 a, i64 b, i64 c, i64& x, i64& y) {
    if (a == 0 && b == 0) { x = y = 0; return c == 0; }
    i64 g = exgcd(abs(a), abs(b), x, y);
    if (c % g) return false;
    x *= c / g; y *= c / g;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}
```

## 相关知识点

[素数](/posts/acm-keywords/#prime) · [GCD](/posts/acm-keywords/#gcd) · [逆元](/posts/acm-keywords/#inverse) · [欧拉函数](/posts/acm-keywords/#phi) · [快速幂](/posts/acm-keywords/#fast-power)

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)
- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)
- [求逆](/posts/acm-efd4aac231ba/)

