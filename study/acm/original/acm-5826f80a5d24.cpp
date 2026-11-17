/*
何为天空数，两个数乘积，是一个数的平分 类似于 2 * 8 = 4^2
现在给你一组数，让你找其中天空数的个数，怎么计算呢？
可以发现，将每个数分解成其质数乘积的形式，假如其分解出来的质数，
这种有偶数个，那么这本身就符合平方的定义，如果是奇数个，
那么就需要，找到另一个数，他所拥有的奇数个数的因子，和这个数相同，
那么这两个数就可以凑成一对
那么就可以将每个数都压缩，压缩后的数如果相同，那么就证明他们可以凑成一对
再进行计算
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
    map<int,int> mp;
    for(int i = 0;i < n ;i++) cin >> a[i];
    for(int i = 0;i < n;i++)
    {
        int k = 1;
        int m = a[i];
        for(int j = 2;j <= m / j;j++)
        {
            if(m % j == 0)
            {
                int num = 0;
                while(m % j == 0)
                {
                    num++;
                    m /= j;
                }
                if(num & 1) 
                {
                    k *= j;
                }
            }
        }
        if(m > 1) k *= m;
        mp[k] ++;
    }
    int ans = 0;
    for(auto p : mp)
    {
        int j = p.second;
        if(j > 1)
        {
            ans += (j - 1) * j / 2;
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