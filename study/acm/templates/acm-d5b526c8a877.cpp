/*
给定一个长度为n的数组，求所有长度大于等于m的子区间其中间值的最大值，
长度为奇数就是中间数，偶数是中间偏左，从小到大排列

离散化 + 二分 + 前缀和
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
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    int l = 0;
    int r = b.size() - 1;
    int ans = b[0];
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        int x = b[mid];
        vector<int> c(n);
        for(int i = 0;i < n;i++)
        {
            if(a[i] >= x) c[i] = 1;
            else c[i] = -1;
        }
        vector<int> d(n+1);
        for(int i = 1;i <= n;i++)
        {
            d[i] = d[i-1] + c[i-1];
        }
        int ok = 0;
        int mi = LLONG_MAX;
        for(int i = m;i <= n;i++)
        {
            mi = min(mi,d[i-m]);
            if(d[i] - mi >= 0)
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        {
            ans = x;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}