/*
将数n中的质因数全部存入
数组p
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
vector<int> p;
void disc(int n){
    p.clear();   // 清除里面之前的元素
    for(int i=2;i*i <= n;i++)
    {
        if(n%i == 0)
        {
            p.push_back(i);
            while(n % i == 0) n/=i;
        }
        if(n > 1) p.push_back(n);
    }
}
void solve()
{
    
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