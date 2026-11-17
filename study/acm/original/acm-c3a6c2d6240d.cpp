/*
这里用于解决两个字符串的公共最长子字符串
复杂度O(n+m)log min(n,m)
*/


#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

typedef unsigned long long ull;

constexpr int MOD = 1e9 + 7;
const ull B1 = 131;
const ull B2 = 137;

string s1,s2;
vector<ull> h1,h2,p1,p2;
vector<ull> H1,H2,P1,P2;

pair<ull,ull> get1(int l,int r)
{
    return {h1[r] - h1[l-1] * p1[r-l+1],h2[r] - h2[l-1] * p2[r-l+1]};
}

pair<ull,ull> get2(int l,int r)
{
    return {H1[r] - H1[l-1] * P1[r-l+1],H2[r] - H2[l-1] * P2[r-l+1]};
}

bool check(int sz)
{
    if(sz == 0) return 1;
    unordered_set<ull> st;
    for(int i = 1; i <= s1.size() - sz + 1;i++)
    {
        auto [x,y] = get1(i,i + sz - 1);
        ull v = (x << 32) ^ y;
        st.insert(v);
    }
    for(int i = 1; i <= s2.size() - sz + 1;i++)
    {
        auto [x,y] = get2(i,i + sz - 1);
        ull v = (x << 32) ^ y;
        if(st.count(v)) return 1;
    }
    return 0;
}
void solve()
{
    
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    h1.assign(n+1,0); h2.assign(n+1,0);
    p1.assign(n+1,1); p2.assign(n+1,1);
    H1.assign(m+1,0); H2.assign(m+1,0);
    P1.assign(m+1,1); P2.assign(m+1,1);
    for(int i = 1;i <= n;i++)
    {
        h1[i] = h1[i-1] * B1 + s1[i-1];
        h2[i] = h2[i-1] * B2 + s1[i-1];
        p1[i] = p1[i-1] * B1;
        p2[i] = p2[i-1] * B2;
    }
    for(int i = 1;i <= m;i++)
    {
        H1[i] = H1[i-1] * B1 + s2[i-1];
        H2[i] = H2[i-1] * B2 + s2[i-1];
        P1[i] = P1[i-1] * B1;
        P2[i] = P2[i-1] * B2;
    }
   int l = 0;
   int r = min(n,m);
   int ans = 0;
   while(l <= r)
   {
        int mid = l + (r - l)/2;
        if(check(mid))
        {
            l = mid + 1;
            ans = mid;
        } 
        else r = mid - 1;
   }
   cout << ans;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}