/*
如果想求 a / b % c 的结果
(1) 必须保证a/b可以整除，每次有除法时，都需要保证绝对能整除
(2) 必须保证MOD是质数，求逆元的原理是费马小定理，要求MOD是质数，比如1000000007
(3) 必须保证b和MOD的最大公约数为1，也就是b和MOD互质

b的逆元等于 pow(b,MOD - 2) % MOD;
求 a / b % MOD 就等于 ((a % MOD) * (pow(b,MOD - 2) % MOD));

连续数字逆元下线性递推
在 % p意义下
1,2,3,4......n，求每个数的逆元
用inv[i]，表示i的逆元
inv[1] = 1;
inv[i] = (p - inv[p % i] * (p / i) % p);

连续阶乘逆元的线性递推
1!,2!,3!.....n!
fact[0] = 1;
fact[i] = (i * fact[i-1]) % MOD; 算阶乘

inv[n] = pow(fact[n],MOD-2) % MOD;
inv[i] = ((i + 1) * inv[i + 1]) % MOD;

C n m = n! / (m! * (n - m)!);
等于 (fact[n] * inv[m] * inv[n-m]) % MOD;
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
int p;
int ksm(int x,int y)
{
    int ans = 1;
    while(y)
    {
        if(y & 1) ans = (ans * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n >> p;
    vector<int> fact(n+1);
    fact[0] = 1;
    for(int i = 1;i <= n;i++) fact[i] = (i * fact[i-1]) % p;
    vector<int> inv(n+1);
    inv[0] = 1;
    inv[n] = ksm(fact[n],p - 2) % p;
    for(int i = n - 1;i >= 0;i--)
    {
        inv[i] = ((i + 1) * inv[i+1]) % p;
    }
    vector<int> ans(n+1);
    for(int i = 0;i <= n;i++)
    {
        ans[i] = (((fact[n] * inv[i]) % p) * inv[n - i]) % p;
        cout << ans[i] << " ";
    }
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