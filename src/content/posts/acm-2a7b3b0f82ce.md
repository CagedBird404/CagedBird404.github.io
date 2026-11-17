---
title: "km算法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["图论·匹配与网络流","学习实现"]
description: "这个和二分图的区别是，他带了权值\r 要求权值的最大\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

这个和二分图的区别是，他带了权值 要求权值的最大

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

这个和二分图的区别是，他带了权值
要求权值的最大
初始化，左部顶标 = max(出边边权最大值)，右部顶表 = 0
求最小的边权匹配和，就是将边权值反过来，改成负数
再求最大匹配边权和，注意左部要再次初始化值
最后结果要取反再加

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
这个和二分图的区别是，他带了权值
要求权值的最大

初始化，左部顶标 = max(出边边权最大值)，右部顶表 = 0

求最小的边权匹配和，就是将边权值反过来，改成负数
再求最大匹配边权和，注意左部要再次初始化值
最后结果要取反再加
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> w;
vector<int> match, lx, ly, slack, pre;
vector<bool> visy;

void bfs(int u) {
    int x, y = 0, yy = 0, delta;
    fill(slack.begin(), slack.end(), 2e18);
    fill(pre.begin(), pre.end(), 0);
    fill(visy.begin(), visy.end(), false);
    
    match[y] = u;
    while (true) {
        x = match[y];
        delta = 2e18;
        visy[y] = true;
        for (int i = 1; i <= n; i++) {
            if (visy[i]) continue;
            if (lx[x] + ly[i] - w[x][i] < slack[i]) {
                slack[i] = lx[x] + ly[i] - w[x][i];
                pre[i] = y;
            }
            if (slack[i] < delta) {
                delta = slack[i];
                yy = i;
            }
        }
        for(int i = 0; i <= n; i++)
        {
            if(visy[i])
            {
                lx[match[i]] -= delta;
                ly[i] += delta;
            } 
            else{
                slack[i] -= delta;
            }
        }
        y = yy;
        if(match[y] == 0) break;
    }
    while(y){
        match[y] = match[pre[y]];
        y = pre[y];
    }
}

void solve()
{
    cin >> n >> m; // n左部点数，m右部点数(如果要求完美匹配要求n <= m)
    // 假设都是n吧，如果不都是，可以把缺的补0
    // 对于不存在的边，权值设为-INF
    
    w.assign(n + 1, vector<int>(n + 1, -2e18)); // 边权矩阵，1-indexed
    
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        w[u][v] = max(w[u][v], weight);
    }

    match.assign(n + 1, 0); // 右部点匹配的左部点
    lx.assign(n + 1, -2e18); // 顶标
    ly.assign(n + 1, 0);
    slack.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    visy.assign(n + 1, false);

    // 初始化lx为左部点出边的最大权值
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
        {
            lx[i] = max(lx[i], w[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) 
    {
        bfs(i);
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if (w[match[i]][i] != -2e18)
        {
            res += w[match[i]][i];
        }
    }
    
    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        // 输出右部点i匹配的左部点，没有则为0。注意这里的变量名不要弄混，一般题目如果左边少，可能要特殊处理
        cout << match[i] << " \n"[i == n];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

## 相关知识点

[二分图匹配](/posts/acm-keywords/#matching) · [网络流](/posts/acm-keywords/#flow) · [图论](/posts/acm-keywords/#graph)

- [Tarjan](/posts/acm-18decad757c7/)
- [Johnson](/posts/acm-c0539a530149/)
- [最大匹配法dfs](/posts/acm-2e047f003844/)
- [最小路覆盖问题](/posts/acm-8830d80818b6/)
- [最大流EK](/posts/acm-d5f52484032e/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-2a7b3b0f82ce.cpp)
