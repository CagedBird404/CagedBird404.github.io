#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
//#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int num;
    cout << "? 1 1" <<endl;
    cin >> num;
    vector<pair<int ,int>> a;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            cout << "? " << i <<" " << j <<endl;
            int nu;
            cin >> nu;
            if(nu == num + 1)
            {
                a.push_back({i, j});
            }
            else{
                 cout << "? " << i <<" " << j <<endl;
                cin >> nu;
            }
        }
    }
    vector<int> b( n + 1);
    for(int i = 1;i <= n;i++) b[i] = i;
    reverse(all(a));
    for(int i = 0;i < a.size();i++)
    {
        swap(b[a[i].second], b[a[i].first]);
    }
    cout <<"! " ;
    for(int i = 1;i <= n;i++) cout << b[i] << " ";
}

signed main()
{
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}