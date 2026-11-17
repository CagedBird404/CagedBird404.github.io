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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}