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