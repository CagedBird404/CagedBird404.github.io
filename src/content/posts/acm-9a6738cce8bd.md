---
title: "3树状数组（范围查询，范围修改）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数据结构·区间查询","学习实现"]
description: "这种情况其实线段树最优，但是树状数组不是不能写\r 只是不好理解\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

这种情况其实线段树最优，但是[树状数组](/posts/acm-keywords/#fenwick)不是不能写 只是不好理解

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

这种情况其实线段树最优，但是[树状数组](/posts/acm-keywords/#fenwick)不是不能写
只是不好理解
维护两个[差分](/posts/acm-keywords/#difference)，一个di,一个（i- 1） * di
求l到r的和，和单点求值一样，求1到r的减去1到l-1的
算的就是 l * di - (i - 1) * di;

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
这种情况其实线段树最优，但是树状数组不是不能写
只是不好理解

维护两个差分，一个di,一个（i- 1） * di
求l到r的和，和单点求值一样，求1到r的减去1到l-1的
算的就是 l * di - (i - 1) * di;
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    vector<int> tree1(n + 1), tree2(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int k = i;
        while(k <= n)
        {
            tree1[k] += b[i];
            tree2[k] += (i - 1) * b[i];
            k += k & -k;
        }
    }
    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            int k1 = k * (x - 1);
            int k2 = k * y;
            y++;
            while(x <= n)
            {
                tree1[x] += k;
                tree2[x] += k1;
                x += x & -x;
            }
            while(y <= n)
            {
                tree1[y] -= k;
                tree2[y] -= k2;
                y += y & -y;
            }
        }
        else{
            int x, y;
            cin >> x >> y;
            int n1= x - 1, n2 = y;
            x--;
            int ans = 0;
            while(x > 0)
            {
                ans -= n1 * tree1[x] - tree2[x];
                x -= x & -x;
            }
            while(y > 0)
            {
                ans += n2 * tree1[y] - tree2[y];
                y -= y & -y;
            }
            cout << ans << endl;
        }
    }
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
        //cout << endl;
    }
}
```

## 相关知识点

[前缀和](/posts/acm-keywords/#prefix) · [差分](/posts/acm-keywords/#difference) · [树状数组](/posts/acm-keywords/#fenwick) · [线段树](/posts/acm-keywords/#segment-tree) · [ST表](/posts/acm-keywords/#sparse-table)

- [前缀，差分](/posts/acm-018da06c2817/)
- [1树状数组（范围查询，单点修改）](/posts/acm-1b60614dae05/)
- [树上差分](/posts/acm-181d67d85ef4/)
- [1线段树基础加法](/posts/acm-d8256bf91c8f/)
- [2线段树加法和乘法](/posts/acm-2091698e6dfc/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-9a6738cce8bd.cpp)
