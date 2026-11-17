#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
constexpr int Max = 200005;
int fa[Max];
int v[Max];
int find(int x)
{
    if(x != fa[x])
    {
        int f = fa[x];
        fa[x] = find(fa[x]);
        v[x] += v[f];    //重点
    }
    return fa[x];   
}
void solve()
{
    int n,m;
    while(cin >> n >> m)
    {for(int i = 0;i <=n ;i++)
    {
        fa[i] = i;
        v[i] = 0;
    }
    int ans = 0;
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        int fx = find(a);
        int fy = find(b);
        if(fx != fy)
        {
            fa[fx] = fy;
            v[fx] = v[b] + c - v[a];
        }
        else{
            if(v[a] - v[b] != c) ans++;
        }
    }
    cout << ans<<endl;
}
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}