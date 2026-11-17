/*
01背包：每个物品 要和不要 两种可能性展开

给定一个正数t，表示背包容量
有m个货品，每个可以选一次
每个货品有自己的体积和价值
返回不超过容量的情况下，怎么获得最大的价值

定义dp[i][j] ：前i个物品总花费不超过j，最大价值
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
    vector<vector<int>> dp(n+1,vector<int>(t+1));
    vector<int> cost(n+1),w(n+1);
    for(int i = 1;i <= n;i++) cin >> cost[i] >> w[i];
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j <= t;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j - cost[i] >= 0)
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j-cost[i]] + w[i]);
            }
        }
    }
    cout << dp[n][t];


    //压缩
    vector<int> dp1(t+1);
    for(int i = 1;i <= n;i++)
    {
        for(int j = t;j >= cost[i];j--)
        {
            dp1[j] = max(dp1[j],dp[j - cost[i]] + w[i]);
        }
    }
    cout << dp1[t];
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
        //cout << endl;
    }
}