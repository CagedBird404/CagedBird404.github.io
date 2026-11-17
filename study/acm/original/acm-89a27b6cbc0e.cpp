#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<vector<int>> cheng(vector<vector<int>> p, vector<vector<int>> q)
{
    vector<vector<int>> c(p.size(), vector<int>(q[0].size()));
    for(int i = 1;i < p.size();i++)
    {
        
        for(int k = 1;k < p[i].size();k++)
        {
            if(p[i][k] == 0) continue;
            for(int j = 1;j < q[0].size();j++)
            {
                c[i][j] += p[i][k] * q[k][j];
            }
        }
    }

    return c;
}


vector<vector<int>> ksm(int x, vector<vector<int>> k, int n)
{
    vector<vector<int>> ans(n + 1, vector<int>(n + 1));

    for(int i = 1;i <= n;i++) ans[i][i] = 1;

    while(x)
    {
        if(x & 1)
        {
            ans = cheng(ans, k);
        }
        k = cheng(k, k);
        x >>= 1;
    }

    return ans;
}

void solve()
{
    int n, b;
    cin >> n >> b;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++) cin >> a[i][j];
    }
    vector<vector<int>> ans = ksm(b, a, n);

    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
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