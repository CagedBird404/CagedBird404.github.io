/*
高精度削弱版本，利用数组实现进位
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
    string a;
    cin >> n >> a;
    int k = a.find(".");//整数
    int l = 0;
    if (k != -1) {
        l = a.size() - 1 - k;//小数
        a.erase(k, 1);
    }
    vector<int> nu(2050);
    reverse(all(a));
    int len = a.size();
    for(int i = 0;i < len;i++)
    {
        nu[i] = a[i] - '0';
    }
    for(int i = 0;i < n;i++)
    {
        int la = 0;
        for(int j = 0;j < len;j++)
        {
            nu[j] = nu[j] * 2 + la;
            la = nu[j] / 10;
            nu[j] %= 10;
        }
        if(la) nu[len++] = la;
    }
    if(l > 0 && nu[l - 1] >= 5)
    {
        int la = 1;
        for(int i = l;i < len;i++)
        {
            nu[i] = nu[i] + la;
            la = nu[i] / 10;
            nu[i] %= 10;
            if(!la) break;
        }
        if(la) nu[len++] = la;
    }
    for(int i = len - 1;i >= l;i--) cout << nu[i];
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