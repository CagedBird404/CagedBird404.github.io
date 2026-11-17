/*
可以存在负权边，但是不能有环，可以检测出负环

时间复杂度：O(nmlog(n))
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int x,y,z;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<node> a(n+1);
    vector<vector<pair<int,int>>> v(n+1);

    for(int i = 0;i < m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a.push({x,y,z});
    }

    int s = 0;
    for(int i = 1;i <= n;i++)
    {
        a.push({s,i,0});
    }

    vector<int> v(n+1);
    v[s] = 0;
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