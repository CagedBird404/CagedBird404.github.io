---
title: "回溯 分数字"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治"]
description: "回溯 分数字的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

回溯 分数字的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

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

