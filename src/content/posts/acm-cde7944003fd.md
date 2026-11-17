---
title: "树形dp"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划"]
description: "套路：\r 1.分析父树得到答案需要子树的哪些信息\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

套路： 1.分析父树得到答案需要子树的哪些信息

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

套路：
1.分析父树得到答案需要子树的哪些信息
2.把子树信息的全集定义成递归返回值
3.通过递归让子树返回全集信息
4。整合子树的全集信息得到父树的全集信息并返回

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

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

