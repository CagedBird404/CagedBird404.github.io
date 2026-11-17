/*
给定一个正整数x
已知用m个二进制位一定能表示x
从高位到低位打印x的每一位状态
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void dy(int x,int m)
{
    int t=x;
    for(int i=m-1;i>=0;i--)
    {
        if(1 << i <= t)
        {
            t -= 1 << i;
            cout<<x<<"的第"<<i<<"位是1"<<endl;
        }
        else{
            cout<<x<<"的第"<<i<<"位是0"<<endl;
        }
    }
    return;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    dy(n,m);
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