---
title: "LCA共同祖先问题（倍增）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["图论·树上问题"]
description: "LCA共同祖先问题（倍增）的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

LCA共同祖先问题（[倍增](/posts/acm-keywords/#doubling)）的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

constexpr int N = 1e5 + 5;
constexpr int LOG = 20;

int n,m,root; // 节点数，查询次数，root为根
vector<vector<int>> g(N,vector<int>());
int depth[N];
int fa[N][LOG];

void dfs(int u,int f)
{
    fa[u][0] = f;           //记录父点
    depth[u] = depth[f] + 1;//深度
    for(int k = 1;k < LOG;k++)
    {
        fa[u][k] = fa[fa[u][k - 1]][k - 1]; //倍增
    }

    for(int v : g[u])          //遍历u的相邻点
    { 
        if(v == f) continue;   //跳过父节点
        dfs(v,u);              //深入子节点
    }
}

int LCA(int u,int v)
{
    if(depth[u] < depth[v]) swap(u,v);
    // 让其同一个深度
    for(int k = LOG - 1;k >= 0;k--)
    {
        if(fa[u][k] && depth[fa[u][k]] >= depth[v])
        u = fa[u][k];
    }
    // 如果已经相遇，直接返回
    if(u == v) return u;
    // 从高到低一起跳，直到他们的父节点相同
    for(int k = LOG - 1;k >= 0;k--)
    {
        if(fa[u][k] && fa[v][k] && fa[u][k] != fa[v][k])
        {
            u = fa[u][k];
            v = fa[v][k];
        }
    }
    return fa[u][0];
}
void solve()
{
    cin >> n >> m >> root;
    for(int i = 1;i <= n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(root,0);

    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >> y;
        cout << LCA(x,y) << endl;
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

[最近公共祖先](/posts/acm-keywords/#lca) · [倍增](/posts/acm-keywords/#doubling) · [DFS](/posts/acm-keywords/#dfs)

- [ST表](/posts/acm-227c4f00c3c6/)
- [树上差分](/posts/acm-181d67d85ef4/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)

