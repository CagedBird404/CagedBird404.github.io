/*
求的是小于等于n，且与n互质的正整数有多少个
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int Max = 1e6 + 10;
vector<int> is_prime(Max, 1);
vector<int> primes;
vector<int> pp(Max);

void cc(int n)
{
    is_prime[0] = is_prime[1] = 0;
    int num = 0;
    for(int i = 2;i <= n;i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
            pp[i] = i;
            num++;
        }
        for(int j = 0;j < num && primes[j] * i <= n;j++)
        {
            is_prime[i * primes[j]] = 0;
            pp[i * primes[j]] = primes[j];
            if(i % primes[j] == 0) break;
        }
    }
}

int ksm(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int x;
    cin >> x;
    int ans = x;
    ans %= MOD;
    while(x != 1)
    {
        ans = ans * (pp[x] - 1) % MOD;
        ans = ans * ksm(pp[x], MOD - 2) % MOD;
        int nu = pp[x];
        while((x % nu) == 0) x /= nu;
    }
    cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; cc(2e5);
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}