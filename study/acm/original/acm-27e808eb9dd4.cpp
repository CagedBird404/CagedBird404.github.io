/*
分组背包问题：多个背包分组，每组只能拿一个
             原理是每组都进行展开，注意复杂度不会变，都是O(n*t)

每个物品有三个属性：消耗，价值，组号
同一组只能选一件

和01区别就是改为要不要这组的商品，这组都依次变量
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int a,b,c;
};

void solve()
{
    int n,t;
    cin >> t >> n;
    vector<node> f(n+1);
    for(int i = 1;i <= n;i++) cin >> f[i].a >> f[i].b >> f[i].c;
    sort(f.begin()+1,f.end(),[](node f1,node f2){
        return f1.c < f2.c;
    });
    int team = f[n].c;
    vector<vector<int>> dp(team+1,vector<int>(t+1));
    int start = 1,end = 2;
    for(int i = 1;i <= team;i++)
    {
        while(end <= n && f[start].c == f[end].c) end++;
        for(int j = 0;j <= t;j++)
        {
            dp[i][j] = dp[i-1][j];
            for(int k = start;k < end;k++)
            {
                if(j - f[k].a >= 0)
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-f[k].a] + f[k].b);
                }
            }
        }
        start = end;
        end++;
    }
    cout << dp[team][t];


    //空间压缩
    vector<int> dp1(t+1);
    start = 1,end = 2;
    for(int i = 1;i <= team;i++)
    {
        while(end <= n && f[end].c == f[start].c) end++;
        for(int j = t;j >= 0;j--)
        {
            for(int k = start;k < end;k++)
            {
                if(j - f[k].a >= 0)
                {
                    dp1[j] = max(dp1[j],dp1[j-f[k].a] + f[k].b);
                }
            }
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