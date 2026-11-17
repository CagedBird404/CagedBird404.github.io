/*
简单来说，如果你在二维平面上有n个不同的点，
拉格朗日插值法可以帮你找出一个次数不超过n−1的多项式曲线，这条曲线会完美地穿过这 n个点。
通过这个多项式，你就可以估算出其他位置上的y值。
d 次多项式需要 (d+1) 个点。
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

// 快速幂
int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 拉格朗日插值
// 已知 n 个点 (x[i], y[i])
// 求 f(k)
//
// 要求：x[i] 两两不同
// 时间复杂度：O(n^2)
int lagrange(vector<int> x, vector<int> y, int k)
{
    int n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int up = 1;
        int down = 1;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            // 分子：k - x[j]
            up = up * ((k - x[j] + MOD) % MOD) % MOD;
            // 分母：x[i] - x[j]
            down = down * ((x[i] - x[j] + MOD) % MOD) % MOD;
        }
        int term = y[i] * up % MOD;
        term = term * qpow(down, MOD - 2) % MOD;
        ans = (ans + term) % MOD;
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int k;
    cin >> k;

    cout << lagrange(x, y, k) << endl;
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