/*
如果你想以这个点为根的整棵树都加上贡献，你可以开一个标记数组，直接在上面加，
如果你想要某条路径上面加上贡献，那么就是lca点减去，然后两个点加上，lca的父亲减去
这两种方法都很常见，可以灵活运用
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
    //这里建图使用的链式前向星
    vector<int> head(n + 1);
    vector<int> to{0}, next{0};
    int nu = 1;
    for(int i = 1;i <= m;i++)
    {
        int u, v;
        cin >> u >> v;
        next.push_back(head[u]);
        to.push_back(v);
        head[u] = nu++;
        next.push_back(head[v]);
        to.push_back(u);
        head[v] = nu++;
    }

    int LOG = log2(n);
    vector<vector<int>> fa(n + 1, vector<int>(LOG + 1));
    vector<int> deph(n + 1);

    auto dfs = [&](auto&&self, int u, int f)->void
    {
        fa[u][0] = f;
        deph[u] = deph[f] + 1;

        for(int i = 1;i <= LOG;i++)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for(int i = head[u];i > 0; i = next[i])
        {
            if(to[i] == f) continue;
            self(self, to[i], u);
        }
    };

    dfs(dfs, 1, 0);

    auto LCA = [&](int u, int v)->int{
        if(deph[u] < deph[v]) swap(u, v);

        for(int i = LOG;i >= 0;i--)
        {
            if(deph[fa[u][i]] >= deph[v]) u = fa[u][i];
        }

        if(u == v) return u;

        for(int i = LOG;i >= 0;i--)
        {
            if(fa[v][i] != fa[u][i])
            {
                v = fa[v][i];
                u = fa[u][i];
            }
        }

        return fa[u][0];
    };

    //剩下的其实就是一种思想，利用 LCA 和 标记数组 来实现成块的树上区间加减
    //比如你想两点之间的最短路径来加上1，你可以v[u]++, v[f]++, v[LCA(u, f)]--, v[fa[LCA(u, f)][0]]--;
    //然后从叶往根来遍历去累加代价

    vector<int> w(n + 1);
    auto dfs1 = (auto&& self, int u, int f)->void{
        for(int i = head[u]; i > 0;i = next[i])
        {
            if(to[i] == f) continue;
            self(self, to[i], u);
            w[u] += w[to[i]];
        }
    }

    dfs1(dfs1, 1, 0);

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