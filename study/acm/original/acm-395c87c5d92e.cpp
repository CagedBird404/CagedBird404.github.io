/*
用于求任意两点间最短路径
图可以是有向或者无向
这个并不常用，但是他使用的意义在于他可以处理带负权的边，但是不能是环

时间复杂度：O(n^3)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(n+1,1e9));
    for(int i = 1;i <= n;i++)
    {
        a[i][i] = 0;
    }
    for(int i = 0;i < m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x][y] = min(a[x][y],z);
    }

    for(int k  =1;k <= n;k++)
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(a[i][k] < 1e9 && a[k][j] < 1e9)
                a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        if(a[x][y] >= 1e9) cout << "无法达到" << endl;
        else cout << a[x][y] << endl;
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