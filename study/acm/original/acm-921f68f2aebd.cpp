/*
给出n个变量x，每个变量只能取0/1，给出m个条件，
比如xi = 0/1，或者xj = 0/1
求2-sat问题就是求出满足m个条件的一组x

样例：x2只能取0，x1只能取1，x3能取0或1

时间复杂度O(n + m)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

const int N = 2e6 + 10;
int head[N], to[N], ne[N], tot;
int dfn[N], low[N], stk[N], scc[N];
bool in_stk[N];
int tim, top, cnt;

void add(int u, int v)
{
    to[++tot] = v;
    ne[tot] = head[u];
    head[u] = tot;
}

void tarjan(int x)
{
    dfn[x] = low[x] = ++tim;
    stk[++top] = x;
    in_stk[x] = true;
    for(int i = head[x]; i; i = ne[i])
    {
        int y = to[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if(in_stk[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if(low[x] == dfn[x])
    {
        ++cnt;
        int y;
        do {
            y = stk[top--];
            in_stk[y] = false;
            scc[y] = cnt;
        } while (y != x);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    tot = tim = top = cnt = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        head[i] = dfn[i] = low[i] = scc[i] = 0;
        in_stk[i] = false;
    }

    for (int i = 1; i <= m; ++i) {
        int i1, a, i2, b;
        cin >> i1 >> a >> i2 >> b;
        // i1为a OR i2为b
        // !a -> b, !b -> a
        add(i1 + (a ^ 1) * n, i2 + b * n);
        add(i2 + (b ^ 1) * n, i1 + a * n);
    }

    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (scc[i] == scc[i + n]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    cout << "POSSIBLE\n";
    for (int i = 1; i <= n; ++i) {
        cout << (scc[i] > scc[i + n]) << " \n"[i == n];
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
        cout << endl;
    }
}