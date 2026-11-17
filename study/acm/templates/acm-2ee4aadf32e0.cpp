// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

constexpr int MOD = 998244353;
// -9.2e18 ~ 9.2e18
int ans;
double n,k;
void dp(double now,double s,double num)
{
    //cout<<now<<" ";
    if(num==1) 
    {
        ans++;
        return;
    }
    
    double Max=now-(num-1);
    double Min=(now+num-1) / num;
     Max=min(Max,s);
    for(int i=Min;i<=Max;i++)
    {
        dp(now-i,i,num-1);
    }
}

void solve()
{
    ans=0;
    cin>>n>>k;
    dp(n,n,k);
    cout<<ans;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << setiosflags(ios::fixed) << setprecision(2);
    int TT = 1;
     //cin >> TT;
    while (TT--)
    {
        solve();
         cout << endl;
    }
}