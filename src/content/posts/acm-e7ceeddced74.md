---
title: "欧拉降幂"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论"]
description: "当底数与模数互质时，用欧拉函数压缩十进制大指数。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

当底数与模数互质时，用[欧拉函数](/posts/acm-keywords/#phi)压缩十进制大指数。

## 使用前提与复杂度

严格要求 gcd(a,m)=1；不互质时不能直接取模指数，需广义欧拉定理或逐位模幂。mod 限于 1..10^9，指数是非负十进制字符串。

**复杂度：** O(√m + L + log m) 时间，L 为指数位数。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 eulerPhi(i64 n) {
    i64 result = n;
    for (i64 p = 2; p <= n / p; ++p) if (n % p == 0) {
        result = result / p * (p - 1);
        while (n % p == 0) n /= p;
    }
    if (n > 1) result = result / n * (n - 1);
    return result;
}
i64 eulerPower(i64 a, const string& exponent, i64 mod) {
    if (mod == 1) return 0;
    if (gcd(a, mod) != 1) throw invalid_argument("base and modulus must be coprime");
    i64 cycle = eulerPhi(mod), e = 0;
    for (char ch : exponent) e = (e * 10 + ch - '0') % cycle;
    a %= mod; if (a < 0) a += mod;
    i64 result = 1;
    while (e) {
        if (e & 1) result = result * a % mod;
        a = a * a % mod; e >>= 1;
    }
    return result;
}
```

## 相关知识点

[素数](/posts/acm-keywords/#prime) · [GCD](/posts/acm-keywords/#gcd) · [逆元](/posts/acm-keywords/#inverse) · [欧拉函数](/posts/acm-keywords/#phi) · [快速幂](/posts/acm-keywords/#fast-power)

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)
- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)
- [求逆](/posts/acm-efd4aac231ba/)

