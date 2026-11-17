 #include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 80112002;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    vector<int> inp(n+1);
    vector<int> outp(n+1);
    for(int i = 0;i < m ;i ++)
    {
        int x,y;
        cin >> x >> y;
        inp[x]++;
        outp[y]++;
        a[x].emplace_back(y);
    } 
    queue<int> q;
    vector<int> dp(n+1);
    for(int i=1;i<=n;i++)
    {
        if(!outp[i]) 
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    while(!q.empty())
    {
        auto k = q.front();
        q.pop();
        for(auto p : a[k])
        {
            dp[p] = (dp[p] + dp[k]) % MOD;
            outp[p]--;
            if(!outp[p]) q.push(p);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        if(!inp[i])
        {
            ans = (ans + dp[i])%MOD;
        }
    }
    cout << ans;
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