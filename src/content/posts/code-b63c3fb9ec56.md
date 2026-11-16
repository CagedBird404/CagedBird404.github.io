---
title: "算法 · 二分图"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## km算法

原文件：`算法/二分图/km算法.cpp`

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

## 二分图最大匹配法

原文件：`算法/二分图/二分图最大匹配法.cpp`

```cpp
/*
设G为二分图，若在G的子图，任意两条边都没有公共节点，那么称M为二分图的一组匹配
在二分图中，包含最多的一组匹配被称为二分图最大匹配

交替路：从一个未匹配点出发，依次经过非匹配边，匹配边，形成的路径叫交替路

增广路：如果能从一个非匹配点走交替路到一个非匹配点，称之为增广路
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

const int INF = 1e18;

struct Edge {
    int to;
    int cap;
    int flow;
    int rev;
};

vector<vector<Edge>> adj;
vector<int> level, ptr;

// 链式建边：正向容量为cap，反向容量为0
void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

// bfs 给残量网络分层建立层次图
bool bfs(int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& edge : adj[v]) {
            if (edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

// dfs 在层次图上多路增广
int dfs(int v, int t, int pushed) {
    if (pushed == 0) return 0;
    if (v == t) return pushed;
    // ptr[v]是当前弧优化，避免重复遍历已经饱和的边
    for (int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if (level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        int push = dfs(tr, t, min(pushed, edge.cap - edge.flow));
        if (push == 0) continue;
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

// dinic 算法主函数
int dinic(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(s, t, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

void solve()
{
    int n, m, e; // n为左部点数，m为右部点数，e为边数
    cin >> n >> m >> e;
    
    // 超级源点s，超级汇点t
    int s = 0, t = n + m + 1; 
    adj.assign(t + 1, vector<Edge>());
    level.resize(t + 1);
    ptr.resize(t + 1);

    // 1. 将源点s和所有左部点(1~n)相连，容量为1
    for (int i = 1; i <= n; i++) {
        add_edge(s, i, 1);
    }
    
    // 2. 将所有右部点(偏移为n+1~n+m)和汇点t相连，容量为1
    for (int i = 1; i <= m; i++) {
        add_edge(n + i, t, 1);
    }

    // 3. 读入二分图的边，左部连到右部，容量为1
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, n + v, 1);
    }

    // 二分图最大匹配数 即为 网络最大流
    int ans = dinic(s, t);
    
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
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

## 最大匹配法dfs

原文件：`算法/二分图/最大匹配法dfs.cpp`

```cpp
/*
【作用与应用场景】
1. 求解二分图最大匹配问题（如经典的“相亲问题”、“任务分配问题”），即寻找最多的不相交的边。
2. 基于 König定理，还可用于求解以下问题：
   - 二分图最小点覆盖（= 最大匹配数）
   - 二分图最大独立集（= 总顶点数 - 最大匹配数）
   - DAG（有向无环图）的最小路径覆盖（= 顶点数 - 拆点后的最大匹配数）

【相关概念】
设G为二分图，若在G的子图，任意两条边都没有公共节点，那么称M为二分图的一组匹配
在二分图中，包含最多的一组匹配被称为二分图最大匹配

交替路：从一个未匹配点出发，依次经过非匹配边，匹配边，形成的路径叫交替路

增广路：如果能从一个非匹配点走交替路到一个非匹配点，称之为增广路
（DFS版本：匈牙利算法求二分图最大匹配，时间复杂度 O(V*E) ）
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> match;
vector<bool> vis;

bool dfs(int u) {
    for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n, m, e;
    cin >> n >> m >> e;
    
    adj.assign(n + 1, vector<int>());
    match.assign(m + 1, -1);
    
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        vis.assign(m + 1, false);
        if (dfs(i)) {
            ans++;
        }
    }
    
    cout << ans << endl;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
    }
}
```

## 染色法

原文件：`算法/二分图/染色法.cpp`

```cpp
/*
一张无向图的N个节点可以分成A，B两个不相交的集合，并且同一集合中没有边相连
那么视为二分图

定理：二分图内没有奇环
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
vector<vector<int>> a;
int n, m;
vector<int> vi;

int ok = 0;
int cnt1 = 0, cnt2 = 0;

void dfs(int l, int co)
{
    if(co == 1) cnt1++;
    else cnt2++;
    
    for(auto k : a[l])
    {
        if(vi[k] == co)
            {
                ok = 1;
                return;
            }
        
        else if(!vi[k]){
            vi[k] = 3 - co;
            dfs(k, 3 - co);
        }
    }
}

void solve()
{
    
    cin >> n >> m;
    a.assign(n + 1,vector<int>());
    for(int i = 0;i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vi.assign(n + 1, 0);
    int ans = 0;
    
    for(int i = 1;i <= n;i++)
    {
        if(vi[i]) continue;
        vi[i] = 1;
        cnt1 = 0;
        cnt2 = 0;
        dfs(i, 1);
        ans += min(cnt1, cnt2);
    }
    
    if(ok) cout << "Impossible";
    else cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
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

