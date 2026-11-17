/*
利用欧拉定理，来对大数次方对m取模的情况下进行计算  a的n次幂，对m取模
使用条件为a和m的gcd = 1

欧拉定理：x为m的欧拉函数，a的x次幂对m取余等于1
所以可以利用欧拉定理来进行大数次幂取模，也就是说直接让n等于n % x
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

int ksm(int x, int y, int z)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % z;
        }
        x = x * x % z;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int x, y, m;
    cin >> x >> y >> m;
    int ans = m;
    int num = m;
    while(num != 1)
    {
        
        ans = ans / pp[num] * (pp[num] - 1);
        int nu = pp[num];
        while((num % nu) == 0) num /= nu;
    }
    y %= ans;
    cout << ksm(x, y, m);
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