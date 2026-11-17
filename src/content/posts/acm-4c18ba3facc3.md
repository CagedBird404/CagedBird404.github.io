---
title: "拉格朗日插值法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论"]
description: "简单来说，如果你在二维平面上有n个不同的点，\r 拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

简单来说，如果你在二维平面上有n个不同的点， 拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

简单来说，如果你在二维平面上有n个不同的点，
拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。
通过这个多项式，你就可以估算出其他位置上的y值。
d 次多项式需要 (d+1) 个点。

> **使用时我会注意：** 模数须为质数，横坐标必须模意义两两不同；每点计算[逆元](/posts/acm-keywords/#inverse)，因此现有实现总复杂度为 O(n²+n log MOD)。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
简单来说，如果你在二维平面上有n个不同的点，
拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。
通过这个多项式，你就可以估算出其他位置上的y值。
d 次多项式需要 (d+1) 个点。
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

// 快速幂
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 拉格朗日插值
// 已知 n 个点 (x[i], y[i])
// 求 f(k)
//
// 要求：x[i] 两两不同
// 时间复杂度：O(n^2)
int lagrange(vector<int> x, vector<int> y, int k)
{
    int n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int up = 1;
        int down = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            // 分子：k - x[j]
            up = up * ((k - x[j] + MOD) % MOD) % MOD;
            // 分母：x[i] - x[j]
            down = down * ((x[i] - x[j] + MOD) % MOD) % MOD;
        }
        int term = y[i] * up % MOD;
        term = term * qpow(down, MOD - 2) % MOD;
        ans = (ans + term) % MOD;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int k;
    cin >> k;

    cout << lagrange(x, y, k) << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

## 相关知识点

[素数](/posts/acm-keywords/#prime) · [GCD](/posts/acm-keywords/#gcd) · [逆元](/posts/acm-keywords/#inverse) · [欧拉函数](/posts/acm-keywords/#phi) · [快速幂](/posts/acm-keywords/#fast-power)

- [快速幂](/posts/acm-48c8db93529d/)
- [矩阵快速幂](/posts/acm-89a27b6cbc0e/)
- [01裴蜀定理](/posts/acm-6a724df7489d/)
- [02拓展欧几里得算法](/posts/acm-0df06f54651e/)
- [求逆](/posts/acm-efd4aac231ba/)

