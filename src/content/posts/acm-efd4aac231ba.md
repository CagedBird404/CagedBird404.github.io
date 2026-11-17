---
title: "求逆"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论","已修订"]
description: "在线性时间内计算 1..n 在质数模数下的逆元。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

在线性时间内计算 1..n 在质数模数下的[逆元](/posts/acm-keywords/#inverse)。

## 使用前提与复杂度

要求 p 为质数且 1≤n<p；必须初始化 inv[1]=1。

**复杂度：** O(n) 时间，O(n) 空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<i64> inverses(int n, i64 p) {
    vector<i64> inv(n + 1);
    if (n >= 1) inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = p - (__int128)(p / i) * inv[p % i] % p;
    return inv;
}
```

## 相关知识点

[素数](/posts/acm-keywords/#prime) · [GCD](/posts/acm-keywords/#gcd) · [逆元](/posts/acm-keywords/#inverse) · [欧拉函数](/posts/acm-keywords/#phi) · [快速幂](/posts/acm-keywords/#fast-power)

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)
- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)
- [1逆元](/posts/acm-00eb98730042/)

## 整理记录

本次对代码进行了修订或补全：要求 p 为质数且 1≤n<p；必须初始化 inv[1]=1。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-efd4aac231ba.cpp)
