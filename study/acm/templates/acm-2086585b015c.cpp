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
    vector<vector<int>> a(n,vector<int>(20));
    for(int i=0;i<n;i++) cin >> a[i][0];
    int Max = log2(n) + 1;
    for(int p=1;p<Max;p++)
    {
        for(int i=0;i + (1 << p) - 1< n;i++)
        {
            a[i][p] = gcd(a[i][p-1],a[i + (1 << (p - 1))][p - 1]);
        }
    }
    vector<int> Log(n + 1);
    Log[1] = 0;
    for(int i=2;i <= n;i++)
    {
        Log[i] = Log[i / 2] + 1;
    }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int sz = Log[r - l + 1];
        int ans = gcd(a[l][sz],a[r - (1 << sz) + 1][sz]);
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
        cout << endl;
    }
}