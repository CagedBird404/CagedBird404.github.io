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