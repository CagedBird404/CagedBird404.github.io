---
title: "大数组合数"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论","已修订"]
description: "Lucas 定理：把 n、m 按质数 p 进制拆分，再相乘。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

Lucas 定理：把 n、m 按质数 p 进制拆分，再相乘。

## 使用前提与复杂度

p 必须是质数且足够小以便预处理；原注释“把 n 和 p 拆开”应为“把 n 和 m 拆开”。

**复杂度：** 预处理 O(p)，单次 O(log_p n)，空间 O(p)。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Lucas {
    int p;
    vector<i64> fact, inverseFact;
    i64 power(i64 a, i64 e) const {
        i64 result = 1;
        while (e) {
            if (e & 1) result = result * a % p;
            a = a * a % p; e >>= 1;
        }
        return result;
    }
    explicit Lucas(int prime) : p(prime), fact(p, 1), inverseFact(p, 1) {
        for (int i = 1; i < p; ++i) fact[i] = fact[i - 1] * i % p;
        inverseFact[p - 1] = power(fact[p - 1], p - 2);
        for (int i = p - 1; i >= 1; --i) inverseFact[i - 1] = inverseFact[i] * i % p;
    }
    i64 small(int n, int m) const {
        if (m > n) return 0;
        return fact[n] * inverseFact[m] % p * inverseFact[n - m] % p;
    }
    i64 choose(i64 n, i64 m) const {
        if (m < 0 || n < m) return 0;
        i64 result = 1;
        while (n || m) {
            result = result * small(n % p, m % p) % p;
            n /= p; m /= p;
        }
        return result;
    }
};
```

## 相关知识点

[素数](/posts/acm-keywords/#prime) · [GCD](/posts/acm-keywords/#gcd) · [逆元](/posts/acm-keywords/#inverse) · [欧拉函数](/posts/acm-keywords/#phi) · [快速幂](/posts/acm-keywords/#fast-power)

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)
- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)
- [求逆](/posts/acm-efd4aac231ba/)

## 整理记录

本次对代码进行了修订或补全：p 必须是质数且足够小以便预处理；原注释“把 n 和 p 拆开”应为“把 n 和 m 拆开”。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-51bdf9fde205.cpp)
