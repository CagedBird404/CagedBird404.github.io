---
title: "树形dp"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划","学习实现"]
description: "套路：\r 1.分析父树得到答案需要子树的哪些信息\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

套路： 1.分析父树得到答案需要子树的哪些信息

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

套路：
1.分析父树得到答案需要子树的哪些信息
2.把子树信息的全集定义成递归返回值
3.通过递归让子树返回全集信息
4。整合子树的全集信息得到父树的全集信息并返回

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
套路：
1.分析父树得到答案需要子树的哪些信息
2.把子树信息的全集定义成递归返回值
3.通过递归让子树返回全集信息
4。整合子树的全集信息得到父树的全集信息并返回
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
constexpr int N = 2e5 + 10;
vector<int> adj[N];
int dp[N][2]; // dp[u][0] 不选u, dp[u][1] 选u
int a[N];     // 节点权值

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (auto v : adj[u])
    {
        if (v == p) continue;
        dfs(v, u);
        // 状态转移方程（以最大权独立集为例：“没有上司的舞会”）
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve()
{
    int n;
    cin >> n;
    
    // 初始化清空
    for(int i = 1; i <= n; i++) 
    {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    
    // 读入点权
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    // 读入边
    for(int i = 1; i < n; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0); // 从根节点(默认1)开始DFS
    
    cout << max(dp[1][0], dp[1][1]) << endl;
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

[动态规划](/posts/acm-keywords/#dp) · [状态压缩](/posts/acm-keywords/#bitmask) · [二分查找](/posts/acm-keywords/#binary-search)

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)
- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-cde7944003fd.cpp)
