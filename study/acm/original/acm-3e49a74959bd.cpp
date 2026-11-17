/*
对于一个素数x，1 - x中随机选择一个数a，
pow(a, x - 1) % x 都必须等于1，这种判断方式出现错误的概率很小

对于这种方法，会出错误，但是概率很低，但是可以再次优化
进行第二层的平方探测，如果x是一个奇数质数，
对于e >= 1 a ^ 2 mod (x ^ e) = 1 的a只有两个解1和-1
当e等于1时，只有两个解1和x - 1
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int ksm(int x, int y, int k)
{
    int ans = 1;
    while(y)
    {
        if(y & 1)
        {
            ans = ans * x % k;
        }
        x = x * x % k;
        y >>= 1;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    while(n--)
    {
        int x;
        cin >> x;
        if(x == 2)
        {
            ans++;
            continue;
        }
        int ok = 1;
        for(int i = 2;i <= min(x, 100ll);i++)
        {
            int kk = ksm(i, x - 1, x);
            if(kk % x != 1) 
            {
                ok = 0;
                break;
            }
        }
        
        if(ok) ans++;
    }
    cout << ans << endl;
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
        cout << endl;
    }
}