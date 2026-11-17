/*
给定一个起点，找出这个起点到其他所有点的最短路径
条件：图的边权值不能为负数
每次从未确定的点中选出路径最短的点，再通过他找他的邻居

1、起点距离记为 0，其他点设为无穷大

2、每次选出一个“最近但未访问”的点

3、用它“松弛”（relax）所有邻居：

时间复杂度：O((m+n)log(n))
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int ,int>>> a(n + 1);
    for(int i = 0;i < m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }

    vector<int> wf(n + 1, 1e18);
    wf[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int ,int>>, greater<pair<int ,int>>> pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        pair<int ,int> p = pq.top();
        pq.pop();
        int v = p.second;
        int w = p.first;
        if(w > wf[v]) continue;

        for(auto [u, f] : a[v])
        {
            if(f + w < wf[u])
            {
                wf[u] = f + w;
                pq.push({wf[u], u});
            }
        }
    }
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
        //cout << endl;
    }
}