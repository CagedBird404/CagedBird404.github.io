#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 
typedef unsigned long long ull;

constexpr int MOD = 1e9 + 7;


void solve()
{
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1);
    map<int,ull> mp;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 9999);
    for(int i=1;i <= n;i++)
    {
        int x;cin >> x;
        a[i] = x;
        if(!mp.count(a[i])) mp[a[i]] = ((ull)dist(gen) << 32) ^ (ull)dist(gen);
    }
    vector<ull> b(n+1);
    for(int i = 1;i <= n;i++)
    {
        b[i] = b[i-1] ^ (mp[a[i]]);
    }
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        if((r - l + 1) % 2 == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int s = 1;
        if((b[r] ^ b[l-1]) != 0) s = 0;
        if(s) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
        //cout << endl;
    }
}