/*
完全背包和01背包的区别是可以选无限次
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int t,n;
    cin >> t >> n;
    vector<int> f(n+1),w(n+1);
    for(int i = 1;i <= n;i++) cin >> f[i] >> w[i];
    vector<int> dp(t+1);
    for(i = 1;i <= n;i++)
    {
        for(int j = 0;j <= t;j++)
        {
            if(j - f[i] >= 0) dp[j] = max(dp[j],dp[j-f[i]] + w[i]);
        }
    }
    cout << dp[t];
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