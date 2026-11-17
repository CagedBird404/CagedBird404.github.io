/*
与Dijkstra相比，这个算法唯一好处在于可以计算负权边，还能检测负环

时间复杂度O(nm);
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int x,y,z;
};
void solve()
{
    int n,m,s;
    cin >> n >> m >> s;
    vector<node> a(m);
    for(int i = 0;i < m;i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    vector<int> v(n+1,1e9);
    v[s] = 0;
    for(int i = 1;i <= n-1;i++)
    {
        for(auto k : a)
        {
            if(v[k.x] < 1e9 && v[k.y] > v[k.x] + k.z)
            {
                v[k.y] = v[k.x] + k.z;
            }
        }
    }

    //检测负环
    bool ok = 0;
    for(auto k : a)
    {
        if(v[k.x] < 1e9 && v[k.y] > v[k.x] + k.z)
        {
            ok = 1;
            break;
        }
    }
    if(ok) cout << "存在负环" << endl;
    else {
        for(int i = 1;i <=n;i++)
        {
            cout << v[i] << " ";
        }
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