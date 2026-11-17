/*
对于很大的数字，进行取模，应该怎么办呢
比如10^1e5的数据
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < s.size();i++)
    {
        ans = (ans * 10 % MOD + (s[i] - '0')) % MOD;
    }
    cout << ans;
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