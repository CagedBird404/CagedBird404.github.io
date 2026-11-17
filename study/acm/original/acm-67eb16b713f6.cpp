/*
题目形式：给定若干个不等式，类似xi - xj <= ci,判断所有不等式是否有解，有解给出一组变量

对于边，对应的点，往小更新，然后判断负环，如果有负环，就无法成立

将所有不等式的形式都转化为 xi <= xj + ci,就是从xj往xi建边

spfa：如果任意节点进入队列次数 > 节点数 - 1，说明有负环
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m;i++){
        int u, v, w;
        // u - v <= w => u <= v + w
        cin >> u >> v >> w;
        adj[v].push_back({u, w});
    }

    // 为了保证图是连通的，并且能到达所有节点，通常建立一个超级源点0，向所有点连边，边权为0
    for(int i = 1; i <= n;i++){
        adj[0].push_back({i, 0});
    }

    vector<int> dist(n + 1, 1e18);
    vector<int> cnt(n + 1, 0);
    vector<bool> inq(n + 1, false);
    queue<int> q;

    dist[0] = 0;
    q.push(0);
    inq[0] = true;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] = false;

        for(auto& edge : adj[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] > n){
                    cout << "NO" << endl; // 存在负环，无解
                    return;
                }
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }

    // 有解，输出一组可行解
    for(int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << endl;
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