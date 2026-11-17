---
title: "拉格朗日插值法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论","学习实现"]
description: "简单来说，如果你在二维平面上有n个不同的点，\r 拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

简单来说，如果你在二维平面上有n个不同的点， 拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

简单来说，如果你在二维平面上有n个不同的点，
拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。
通过这个多项式，你就可以估算出其他位置上的y值。
d 次多项式需要 (d+1) 个点。

> **易错点：** 模数须为质数，横坐标必须模意义两两不同；每点计算[逆元](/posts/acm-keywords/#inverse)，因此现有实现总复杂度为 O(n²+n log MOD)。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

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

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-4c18ba3facc3.cpp)
