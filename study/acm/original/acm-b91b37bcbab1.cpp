/*
有依赖的背包：多个物品变成一个复合物品（互斥），每件复合物品 不要和怎么要 多种可能性展开

就是类似谁是谁的前提
每个物品有三个信息 花费，价值，归属
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int t,n,m;
    cin >> t >> n;
    vector<bool> zhu(n+1);//判断他是不是主数组，就是有附属商品
    vector<int> f(n+1);//他有几个附属
    vector<vector<int>> fl(n+1);//记录他的附属
    vector<int> cost(n+1);
    vector<int> w(n+1);
    for(int i = 1;i <= n;i++)
    {
        cin >> cost[i] >> w[i];
        int num;
        cin >> num;
        if(num != 0) f[i] = 1;
        while(num--)
        {
            int x;
            cin >> x;
            f[x]++;
            fl[x].emplace_back(i);
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(t+1));
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