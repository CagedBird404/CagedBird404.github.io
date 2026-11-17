/*
给定整数x,y，你需要输出x^y % p的值
0 <= x <= 1e5 ,
0 <= y <= 10^1e5
1e5 <= p <= 1e9 + 7

*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

int ksm(int base, int exp, int MOD)
{
    int ans = 1;
    while (exp)
    {
        if (exp & 1)
        {
            ans = ans * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return ans;
}
void solve()
{
    int x, p;
    string y;
    cin >> x >> y >> p;
    if (p == 1)
    {
        cout << 0;
        return;
    }

    int ans = 1 % p;
    int base = x % p;
    for(int i = 0;i < y.size();i++)
    {
        ans = ksm(ans, 10, p);
        int k = y[i] - '0';
        if(k)
        {
            ans = ans * ksm(base, k, p) % p;
        }
    }
    cout << ans;
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