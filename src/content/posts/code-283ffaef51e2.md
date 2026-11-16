---
title: "算法 · 网络流"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 最大流EK

原文件：`算法/网络流/最大流EK.cpp`

```cpp
/*
这是最大流EK算法
对于一个图，有一个源点和一个汇点
存在一些边，这些边存在最大容量
求从源点出发，到汇点的最大流量，边上经过的流量不能超过限制

具体流程：
先bfs找增广路，也就是合理路径，mf数组记录流量上限
对于找到的增光路，将其反向建边，也就是建立残留网
将可行流累加，总体就是最大流量

复杂度 On*m*m
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

const int N = 10005; // 节点数
const int M = 200005; // 边数，记得开两倍，因为有反向边

int head[N], to[M], val[M], nxt[M], cnt = 1; // cnt初值为1，使得正反向边可以通过 ^1 转换
int mf[N], pre[M]; // mf[i]表示到达点i的最大流量，pre[i]记录到达点i的边的编号
bool vis[N]; // BFS时记录点是否访问过
int n, m, s, t; // n个点，m条边，源点s，汇点t

void add(int u, int v, int w) {
    to[++cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt;
}

// 添边：正向建边容量为w，反向建边容量为0
void add_edge(int u, int v, int w) {
    add(u, v, w);
    add(v, u, 0);
}

bool bfs() {
    memset(mf, 0, sizeof(mf));
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = true;
    mf[s] = 1e18; // 初始源点流量无穷大
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = nxt[i]) 
        {
            int v = to[i], w = val[i];
            if (!vis[v] && w > 0) { // 如果未访问过且残余容量大于0
                vis[v] = true;
                mf[v] = min(mf[u], w);
                pre[v] = i; // 记录过来的边
                q.push(v);
                if (v == t) return true; // 找到一条增广路
            }
        }
    }
    return false;
}

int EK() {
    int maxflow = 0;
    while (bfs()) {
        int v = t;
        // 顺着路径寻找，更新容量残余网
        while (v != s) {
            int i = pre[v]; // 走到这里的边
            val[i] -= mf[t];
            val[i ^ 1] += mf[t]; // 反向边增加
            v = to[i ^ 1]; // 回溯到上一个点
        }
        maxflow += mf[t]; // 累加可行流
    }
    return maxflow;
}

void solve()
{
    // 初始化
    memset(head, 0, sizeof(head));
    cnt = 1;

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    
    cout << EK();
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
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

## 最小路覆盖问题

原文件：`算法/网络流/最小路覆盖问题.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

const int N = 20005;
const int M = 400005;

int n, m, s, t;

int head[N], to[M], val[M], nxt_edge[M], cnt = 1;
int mf[N], pre[M];
bool vis[N];

void add(int u, int v, int w)
{
    to[++cnt] = v;
    val[cnt] = w;
    nxt_edge[cnt] = head[u];
    head[u] = cnt;
}

void ad(int u, int v, int w)
{
    add(u, v , w);
    add(v, u , 0);
}

bool bfs()
{
    memset(vis,false,sizeof(vis));
    memset(mf, 0, sizeof(mf));
    queue<int> q;

    q.push(s);
    vis[s] = 1;
    mf[s] = 1e18;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = head[u]; i ; i = nxt_edge[i])
        {
            int v = to[i];
            if(!vis[v] && val[i] > 0)
            {
                vis[v] = 1;
                mf[v] = min(mf[u], val[i]);
                pre[v] = i;
                q.push(v);
                if(v == t) return 1;
            }
        }
    }
    return 0;
}

int EK()
{
    int ans = 0;
    while(bfs())
    {
        int v = t;
        while(v != s)
        {
            int i = pre[v];
            val[i] -= mf[t];
            val[i ^ 1] += mf[t];
            v = to[i ^ 1];
        }
        ans += mf[t];
    }
    return ans;
}

void solve()
{
    memset(head, 0, sizeof(head));
    cnt = 1;

    cin >> n >> m;

    s = 0;
    t = 2 * n + 1;

    for(int i = 1; i <= n; i++)
        ad(s, i, 1);

    for(int i = 1; i <= n; i++)
        ad(i + n, t, 1);

    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ad(u, v + n, 1);  
    }

    int max_match = EK();

    

    vector<int> nxt(n + 1, 0), pre_v(n + 1, 0);

    for(int u = 1; u <= n; u++)
    {
        for(int i = head[u]; i; i = nxt_edge[i])
        {
            int v = to[i];
            if(v > n && v <= 2*n && val[i] == 0)
            {
                int real_v = v - n;
                nxt[u] = real_v;
                pre_v[real_v] = u;
            }
        }
    }

    vector<bool> vis2(n + 1, false);

    for(int i = 1; i <= n; i++)
    {
        if(pre_v[i] == 0)
        {
            int u = i;
            while(u)
            {
                cout << u << " ";
                vis2[u] = true;
                u = nxt[u];
            }
            cout << endl;
        }
    }
    
    cout << n - max_match << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
```

