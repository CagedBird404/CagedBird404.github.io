#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define endl '\n'

/*
拓展欧几里得算法是在裴蜀定理的基础上来实现的，裴蜀定理是知道这个成立，那么拓展欧几里得算法就是得到一组特解
对于 ax + by = c 这个公式
这个函数返回的是gcd(a, b),也就是说
返回的是另一个式子at + bh = gcd(a, b);
而且对应x和y的位置，会变成相同比例的t和h
所以得出来的t将其按照比例放大就可以了

拓展欧几里得还有很多算法：
1、求逆元
逆元的本质是什么，对于一个数a，他的逆元是x，那么就相当于x和1/a是等效的，那么也就等同于ax % b = 1
那么你就可以简化成ax - by = 1, 那么也就是ax + by = 1，其中b是模数，拓展欧几里得有点在于，快，而且b不用是质数，只是a和b互质
但是求出来的逆元x有可能是负数，要用(x + MOD) % MOD;
*/

/*
算法的实现其实还是和站专项出发有关，就是用递归去实现辗转相除的同时去得到x和y
*/

int extend_gxd(int a, int b, int &x, int &y)
{
    //对于最终相态肯定是 1 * gcd(a, b) + 0 * 0 = gcd(a, b)
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int d = extend_gxd(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

int ksm(int x, int y, int m)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % m;
        }
        x = x *x % m;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int x, y, m, n;
    cin >> m >> n;

    int g = extend_gxd(m, n, x, y);
    cout << ksm(m, n - 2, n) << endl;
    cout << (x % n + n) % n;
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
}