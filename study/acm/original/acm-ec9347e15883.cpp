/*
莫队算法是解决批量的，可离线的区间查询问题，适用性广泛

按照排序策略
经典排序策略：
（1）左端点所在块号从小到大
（2）右端点数值从小到大

奇偶排序
（1）左端点在块号从小到大
（2）块号为奇，r从小到大，偶，从大到小

建立滑动窗口
左右边界都移动

时间复杂度n * sqrt(n)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node{
    int l,r,id;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    int len = sqrt(n);
    int num = (n + len - 1) / len;
    vector<int> b(n+1);
    for(int i = 1;i <= n;i++)
    {
        b[i] = (i - 1) / len + 1;
    }
    vector<int> bl(num + 1),br(num + 1);
    for(int i = 1;i <= num;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n, i * len);
    }
    vector<node> k(m);
    for(int i = 0;i < m;i++)
    {
        cin >> k[i].l >> k[i].r;
        k[i].id = i;
    }
    sort(all(k),[&](node a,node c){
        if(b[a.l] != b[c.l]) return b[a.l] < b[c.l];
        return a.r < c.r;
    });
    vector<int> ans(m);
    int kind = 0;
    map<int,int> mp;
    int l = 1, r = 0;
    for(int i = 0; i< m; i++)
    {
        
        while(l < k[i].l)
        {
            mp[a[l]]--;
            if(mp[a[l]] == 0) kind--;
            l++;
        }
        
        while(l > k[i].l)
        {
            l--;
            mp[a[l]]++;
            if(mp[a[l]] == 1) kind++;
        }

        while(r < k[i].r)
        {
            r++;
            mp[a[r]]++;
            if(mp[a[r]] == 1) kind++;
        }

        while(r > k[i].r)
        {
            mp[a[r]]--;
            if(mp[a[r]] == 0) kind--;
            r--;
        }
        
        ans[k[i].id] = kind;
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
        cout << endl;
    }
}