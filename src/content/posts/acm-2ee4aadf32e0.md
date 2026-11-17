---
title: "回溯 分数字"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治","学习实现"]
description: "回溯 分数字的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

回溯 分数字的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 998244353;
// -9.2e18 ~ 9.2e18
int ans;
double n,k;
void dp(double now,double s,double num)
{
    //cout<<now<<" ";
    if(num==1) 
    {
        ans++;
        return;
    }
    
    double Max=now-(num-1);
    double Min=(now+num-1) / num;
     Max=min(Max,s);
    for(int i=Min;i<=Max;i++)
    {
        dp(now-i,i,num-1);
    }
}

void solve()
{
    ans=0;
    cin>>n>>k;
    dp(n,n,k);
    cout<<ans;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << setiosflags(ios::fixed) << setprecision(2);
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

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-2ee4aadf32e0.cpp)
