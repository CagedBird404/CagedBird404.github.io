#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
int r = 0;

int cc(int x)
{
    if(x <= 1) return 0;
    set<int> S;
    for(int i = 1;i < x;i++)
    {
        int l = min(r - i,i);
        if(l >= 1 && i + l >= x)
        {
            S.insert(cc(i));
        }
    }
    int k = 0;
    while(S.count(k)) k++;
    return k;
}
void solve()
{
    
    int t;cin >> t;
    while(t--)
    {
        string s;
        int n;
        cin >> s >> n;
        if(s == "change") r = n;
        else{
            int l,r;
            int ans = 0;
            while(n--)
            {
                cin >> l >> r;
                for(int i = l;i <= r;i++) ans ^= cc(i);
            }
            cout << (ans ? 1 : 0);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}