#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int n, m;
vector<int> a, d;
vector<int> e, f;

void build(int l, int r, int p)
{
    if(l == r)
    {
        d[p] = a[l];
        f[p] = 1; //乘法懒标记初始化
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, p * 2 + 1);

    d[p] = d[p * 2] + d[p * 2 + 1];
}

void push_down(int p, int l, int r)
{
    int mid = l + (r - l) / 2;

    d[2 * p] = (d[2 * p] * f[p] % MOD + e[p] * (mid - l + 1)) % MOD;
    d[2 * p + 1] = (d[2 * p + 1] * f[p] % MOD + e[p] * (r - mid)) % MOD;

    f[p * 2] = f[p * 2] * f[p] % MOD;
    f[p * 2 + 1] = f[p * 2 + 1] * f[p] % MOD;

    e[p * 2] = (e[p] + (e[p * 2] * f[p])) % MOD;
    e[p * 2 + 1] = (e[p] + (e[p * 2 + 1] * f[p])) % MOD;

    e[p] = 0;
    f[p] = 1;
}

void update1(int l, int r, int c, int s, int t, int p)
{
    if(r < s || l > t) return;

    if(l <= s && r >= t)
    {
        d[p] = (d[p] + c * (t - s + 1)) % MOD;
        e[p] = (e[p] + c) % MOD;
        return;
    }

    push_down(p, s, t);

    int mid = s + (t - s) / 2;
    if(mid >= l) update1(l , r, c, s, mid, p * 2);
    if(mid < r) update1(l, r, c, mid + 1, t, p * 2 + 1);

    d[p] = (d[p * 2 + 1] + d[p * 2]) % MOD;

}

void update2(int l, int r, int c, int s, int t, int p)
{
    if(r < s || l > t) return;

    if(l <= s && r >= t)
    {
        d[p] = (d[p] * c) % MOD;
        e[p] = e[p] * c % MOD;
        f[p] = (f[p] * c) % MOD;

        return;
    }

    push_down(p, s, t);

    int mid = s + (t - s) / 2;
    if(mid >= l) update2(l , r, c, s, mid, p * 2);
    if(mid < r) update2(l, r, c, mid + 1, t, p * 2 + 1);

    d[p] = (d[p * 2 + 1] + d[p * 2]) % MOD;

}

int sum(int l, int r, int s, int t, int p)
{
    if(r < s || l > t) return 0;

    if(l <= s && t <= r)
    {
        return d[p] % MOD;
    }

    push_down(p, s, t);

    int ans = 0;
    int mid = s + (t - s) / 2;

    if(mid >= l) ans += sum(l, r, s, mid, p * 2);
    ans %= MOD;
    if(mid < r) ans += sum(l, r, mid + 1, t, p * 2 + 1);
    ans %= MOD;

    return ans;
}

void solve()
{
    cin >> n >> m;
    a.assign(n + 1, 0);
    d.assign(4 * n + 1, 0);
    e.assign(4 * n + 1, 0);
    f.assign(4 * n + 1, 1);
    for(int i = 1;i <= n;i++) cin >> a[i];

    build(1, n, 1);

    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r, k;
            cin >> l >> r >> k;
            update2(l, r, k, 1, n, 1);
        }
        else if(op == 2)
        {
            int l, r, k;
            cin >> l >> r >> k;
            update1(l, r, k, 1, n, 1);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << sum(l, r, 1, n, 1) << endl;
        }
    }
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