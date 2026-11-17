// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18
constexpr int Max = 2*1e5;
int fa[Max];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void cc(int f,int v)
{
    fa[find(f)] = find(v);
}
bool dd(int x,int y)
{
    return find(x) == find(y);
}
void solve()
{
    int n,m,q;
    cin >> n >> m >> q;
    for(int i = 0;i <= n;i++)
    {
        fa[i] = i;
    }
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        cc(x,y);
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        if(dd(x,y)) cout << "YES" << endl;
        else cout << "NO" << endl;
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