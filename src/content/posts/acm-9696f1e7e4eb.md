---
title: "最大连续子区间去掉最大值"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划","学习实现"]
description: "对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值\r 因为对于最大值减去的情况有太多\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值 因为对于最大值减去的情况有太多

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值
因为对于最大值减去的情况有太多
那么就可以将最大值定死

> **易错点：** 枚举最大值只覆盖 −30..30；必须确认题目中的元素范围，否则会漏解。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值
因为对于最大值减去的情况有太多
那么就可以将最大值定死
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
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    int ans = LLONG_MIN;
    for(int k = -30;k <= 30;k++)
    {
        int ok = 0;
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            if(a[i] > k)
            {
                if(ok) ans = max(ans,sum - k);
                sum = 0;
                ok = 0;
            }
            else{
                if(sum < 0) sum = 0;sum += a[i];
                if(a[i] == k) ok = 1;
                if(ok) ans = max(ans,sum - k);
            }
        }
    }
    cout << max(ans,0ll);
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

[动态规划](/posts/acm-keywords/#dp) · [状态压缩](/posts/acm-keywords/#bitmask) · [二分查找](/posts/acm-keywords/#binary-search)

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)
- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-9696f1e7e4eb.cpp)
