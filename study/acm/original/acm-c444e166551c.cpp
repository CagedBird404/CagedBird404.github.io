/*
原理就是将数组改为差分数组
利用差分数组单点修改就能改范围值的特性
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1), tree(n + 1);
    for(int i = 1; i <= n;i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        int k = i;
        while(k <= n)
        {
            tree[k] += b[i];
            k += k & -k;
        }
    }
    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x, y, k;
            cin >> x >> y >> k;
            while(x <= n)
            {
                tree[x] += k;
                x += x & -x;
            }
            y++;
            while(y <= n)
            {
                tree[y] -= k;
                y += y & -y;
            }
        }
        else{
            int t;
            cin >> t;
            int ans = 0;
            while(t > 0)
            {
                ans += tree[t];
                t -= t & -t;
            }
            cout << ans << endl;
        }
    }
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