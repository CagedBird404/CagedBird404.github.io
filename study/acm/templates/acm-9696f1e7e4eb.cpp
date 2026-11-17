/*
对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值
因为对于最大值减去的情况有太多
那么就可以将最大值定死
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    int ans = LLONG_MIN;
    for(int k = -30;k <= 30;k++)
    {
        int ok = 0;
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            if(a[i] > k)
            {
                if(ok) ans = max(ans,sum - k);
                sum = 0;
                ok = 0;
            }
            else{
                if(sum < 0) sum = 0;sum += a[i];
                if(a[i] == k) ok = 1;
                if(ok) ans = max(ans,sum - k);
            }
        }
    }
    cout << max(ans,0ll);
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
        //cout << endl;
    }
}