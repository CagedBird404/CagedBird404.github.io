---
title: "矩阵快速幂"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学·快速幂"]
description: "把线性递推表示为矩阵，再对转移矩阵做快速幂。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

把线性递推表示为矩阵，再对转移矩阵做[快速幂](/posts/acm-keywords/#fast-power)。

## 使用前提与复杂度

这是模矩阵版本；明确取模语义，指数 0 返回单位矩阵；矩阵必须为同阶方阵。

**复杂度：** O(k³ log e) 时间，O(k²) 空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

using Matrix = vector<vector<i64>>;
Matrix multiply(const Matrix& a, const Matrix& b, i64 mod) {
    int n = (int)a.size();
    Matrix c(n, vector<i64>(n));
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < n; ++k)
            for (int j = 0; j < n; ++j)
                c[i][j] = (c[i][j] + (__int128)a[i][k] * b[k][j]) % mod;
    return c;
}
Matrix matrixPow(Matrix a, i64 e, i64 mod) {
    int n = (int)a.size();
    Matrix result(n, vector<i64>(n));
    for (int i = 0; i < n; ++i) result[i][i] = 1 % mod;
    for (auto& row : a) for (i64& x : row) x = (x % mod + mod) % mod;
    while (e) {
        if (e & 1) result = multiply(result, a, mod);
        a = multiply(a, a, mod); e >>= 1;
    }
    return result;
}
```

## 相关知识点

[快速幂](/posts/acm-keywords/#fast-power) · [状态压缩](/posts/acm-keywords/#bitmask)

- [快速幂](/posts/acm-48c8db93529d/)
- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)

