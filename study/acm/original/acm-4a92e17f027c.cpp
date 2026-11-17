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