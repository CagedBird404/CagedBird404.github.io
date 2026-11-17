// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
 
constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18
//链接：https://ac.nowcoder.com/acm/contest/92182/K来源：牛客网有

 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
 
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n and v[j] - v[i] <= k)
        {
            j++;
        }    //移动窗口，比二分快，
        auto m = j - i;
        ans = max(ans, m);
    }
 
    cout << ans * 1.0 / n;
}
 
signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    cout << setiosflags(ios::fixed) << setprecision(4);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
    }
}