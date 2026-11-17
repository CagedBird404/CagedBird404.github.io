#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int ksm(int x,int y,int z)
{
    int ans = 1;
    while(y)
    {
        if(y & 1) ans = (ans * x) % z;
        y >= 1;
        x = (x * x) % z;
    }
    return ans;
}

void solve()
{
    int n,p;
    cin >> n >> p;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> c(n+2);
    b[0] = 1;
    c[n+1] = 1;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[i] = (b[i-1] * a[i]) % p;
    }
    for(int i = n;i >= 1;i--)
    {
        c[i] = (c[i+1] * a[i]) % p;
    }
    vector<int> inv(n+1);
    int invs = ksm(b[n],p - 2,p);
    for(int i = 1;i <= n;i++)
    {
        inv[i] = ((invs * b[i-1]) % p ) * c[i + 1] % p; 
    }
    for(int i = 1;i <= n;i++) cout << inv[i] << " ";
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