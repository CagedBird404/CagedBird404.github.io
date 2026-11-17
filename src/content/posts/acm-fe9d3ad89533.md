---
title: "欧拉函数"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论","已修订"]
description: "计算 1..n 中与 n 互质的正整数个数。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

计算 1..n 中与 n 互质的正整数个数。

## 使用前提与复杂度

phi(1)=1；逐个不同质因子执行 ans=ans/p*(p−1)，无需用模逆做普通除法。

**复杂度：** O(√n) 时间，O(1) 额外空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 phi(i64 n) {
    i64 answer = n;
    for (i64 p = 2; p <= n / p; ++p) if (n % p == 0) {
        answer = answer / p * (p - 1);
        while (n % p == 0) n /= p;
    }
    if (n > 1) answer = answer / n * (n - 1);
    return answer;
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

本次对代码进行了修订或补全：phi(1)=1；逐个不同质因子执行 ans=ans/p*(p−1)，无需用模逆做普通除法。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-fe9d3ad89533.cpp)
