---
title: "高精度阉割"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数学与数论","学习实现"]
description: "高精度削弱版本，利用数组实现进位"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

高精度削弱版本，利用数组实现进位

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

高精度削弱版本，利用数组实现进位

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
高精度削弱版本，利用数组实现进位
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    string a;
    cin >> n >> a;
    int k = a.find(".");//整数
    int l = 0;
    if (k != -1) {
        l = a.size() - 1 - k;//小数
        a.erase(k, 1);
    }
    vector<int> nu(2050);
    reverse(all(a));
    int len = a.size();
    for(int i = 0;i < len;i++)
    {
        nu[i] = a[i] - '0';
    }
    for(int i = 0;i < n;i++)
    {
        int la = 0;
        for(int j = 0;j < len;j++)
        {
            nu[j] = nu[j] * 2 + la;
            la = nu[j] / 10;
            nu[j] %= 10;
        }
        if(la) nu[len++] = la;
    }
    if(l > 0 && nu[l - 1] >= 5)
    {
        int la = 1;
        for(int i = l;i < len;i++)
        {
            nu[i] = nu[i] + la;
            la = nu[i] / 10;
            nu[i] %= 10;
            if(!la) break;
        }
        if(la) nu[len++] = la;
    }
    for(int i = len - 1;i >= l;i--) cout << nu[i];
 }

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
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

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-f5bca8ed871d.cpp)
