//对于异或的构造，通常前缀和非常有用

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;


void solve()
{
    int n;cin >> n;
    vector<int> a;
    vector<int> b;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(x % 2 == 1)
        {
            a.emplace_back(x);
        }
        else b.emplace_back(x);
    }
    sort(all(a));
    sort(b.rbegin(),b.rend());
    if(a.size() == 0)
    {
        for(int i = 0;i < n;i++) cout << 0 << " ";
        return;
    }
    int num = b.size();
    int sum = a[a.size() - 1];
    cout << sum << " ";
    for(int i = 0;i < num;i++)
    {
        sum += b[i];
        cout << sum << " ";
    }
    for(int i = 1;i <= n - num - 1;i++)
    {
        if(i % 2 == 0)
        {
            cout << sum << " ";
        }
        else{
            cout << sum - b[b.size() - 1] << " ";
        }
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(10); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}