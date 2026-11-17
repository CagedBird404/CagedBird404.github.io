---
title: "2-sat问题"
published: 2026-11-16
category: ACM竞赛模板
tags: ["图论·连通性","学习实现"]
description: "给出n个变量x，每个变量只能取0/1，给出m个条件，\r 比如xi = 0/1，或者xj = 0/1\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

给出n个变量x，每个变量只能取0/1，给出m个条件， 比如xi = 0/1，或者xj = 0/1

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

给出n个变量x，每个变量只能取0/1，给出m个条件，
比如xi = 0/1，或者xj = 0/1
求2-sat问题就是求出满足m个条件的一组x
样例：x2只能取0，x1只能取1，x3能取0或1
时间复杂度O(n + m)

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
给出n个变量x，每个变量只能取0/1，给出m个条件，
比如xi = 0/1，或者xj = 0/1
求2-sat问题就是求出满足m个条件的一组x

样例：x2只能取0，x1只能取1，x3能取0或1

时间复杂度O(n + m)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

const int N = 2e6 + 10;
int head[N], to[N], ne[N], tot;
int dfn[N], low[N], stk[N], scc[N];
bool in_stk[N];
int tim, top, cnt;

void add(int u, int v)
{
    to[++tot] = v;
    ne[tot] = head[u];
    head[u] = tot;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++tim;
    stk[++top] = x;
    in_stk[x] = true;
    for(int i = head[x]; i; i = ne[i])
    {
        int y = to[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(in_stk[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(low[x] == dfn[x])
    {
        ++cnt;
        int y;
        do {
            y = stk[top--];
            in_stk[y] = false;
            scc[y] = cnt;
        } while (y != x);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    tot = tim = top = cnt = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        head[i] = dfn[i] = low[i] = scc[i] = 0;
        in_stk[i] = false;
    }

    for (int i = 1; i <= m; ++i) {
        int i1, a, i2, b;
        cin >> i1 >> a >> i2 >> b;
        // i1为a OR i2为b
        // !a -> b, !b -> a
        add(i1 + (a ^ 1) * n, i2 + b * n);
        add(i2 + (b ^ 1) * n, i1 + a * n);
    }

    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (scc[i] == scc[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; ++i) {
        cout << (scc[i] > scc[i + n]) << " \n"[i == n];
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
        cout << endl;
    }
}
```

## 相关知识点

[强连通分量](/posts/acm-keywords/#scc) · [拓扑排序](/posts/acm-keywords/#topological) · [DFS](/posts/acm-keywords/#dfs)

- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [P_4017_最大食物链(拓扑排序)](/posts/acm-bb016f9e4308/)
- [期望dp](/posts/acm-95f75c628fe0/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-921f68f2aebd.cpp)
