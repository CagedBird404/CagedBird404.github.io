---
title: "st表求给定区间最大元素差值"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数据结构·区间查询","学习实现"]
description: "st表求给定区间最大元素差值的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

st表求给定区间最大元素差值的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> st(n,vector<int>(20));
    vector<vector<int>> st1(n,vector<int>(20));
    vector<int> Log(n+1);  // 预处理一直到n，所有数的恰好比这个数小或者等于，的2的k次方的k是多大
    Log[1]=0;
    for(int i=2;i<=n;i++)
    {
        Log[i] = Log[i/2] + 1;  // 这样可以更快的寻找
    }
    for(int i=0;i<n;i++)
    {
        cin >> st[i][0];
        st1[i][0]=st[i][0];
    }
    int MAX = Log[n]+1;
    for(int p=1;p<MAX;p++)
    {
        for(int i=0;i+(1<<p)-1 < n;i++)  //终点 = 起点 + 长度 - 1
        {
                st[i][p] = max(st[i][p-1],st[i+(1<<(p-1))][p-1]);
                st1[i][p] = min(st1[i][p-1],st1[i+(1<<(p-1))][p-1]);
        }
    }
    
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int k=Log[r-l+1];
        //对于这种分半的形式，不能对那种对于区间求和一类的进行计算，因为会有重复元素
        int Max = max (st[l][k] , st[r-(1 << k)+1][k]);
        int Min = min (st1[l][k] , st1[r-(1 << k)+1][k]);    // 不用无限逼近，将其分成两半，后一半的起点恰好是
        cout<<Max - Min<<endl;                               // 一个小于n的l+2^k，终点是r
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve();
    }
}
```

## 相关知识点

[前缀和](/posts/acm-keywords/#prefix) · [差分](/posts/acm-keywords/#difference) · [树状数组](/posts/acm-keywords/#fenwick) · [线段树](/posts/acm-keywords/#segment-tree) · [ST表](/posts/acm-keywords/#sparse-table)

- [前缀，差分](/posts/acm-018da06c2817/)
- [1树状数组（范围查询，单点修改）](/posts/acm-1b60614dae05/)
- [树上差分](/posts/acm-181d67d85ef4/)
- [3树状数组（范围查询，范围修改）](/posts/acm-9a6738cce8bd/)
- [1线段树基础加法](/posts/acm-d8256bf91c8f/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-a850bc5c07c1.cpp)
