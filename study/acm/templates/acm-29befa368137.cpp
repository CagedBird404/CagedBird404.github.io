/*
与普通莫队相比，多了一个修改操作

node也就多了一个属性 t

块长设置为n的三分之二次方

排序顺序
（1）l所在块从小到大
（2）r所在块从小到大
（3）t从小到大

时间复杂度为n的五分之三次方
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int l,r,id,t;
};

void solve()
{
    int m,n;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    int len = max(1ll,(int)pow(n,2.0 / 3.0));
    int num = (n + len - 1) / len;
    vector<int> b(n + 1);
    for(int i = 1;i <= n;i++)
    {
        b[i] = (i - 1) / len + 1;
    }
    vector<int> bl(num + 1), br(num + 1);
    for(int i = 1;i <= num;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n,i * len);
    }
    int idb = 0;
    int T = 0;
    vector<pair<int,int>> up;
    vector<node> k;
    for(int i = 1;i <= m;i++)
    {
        char op;
        cin >> op;
        if(op == 'Q')
        {
            idb++;
            int x,y;
            cin >> x >> y;
            node p;
            p.l = x, p.r = y, p.id = idb, p.t = T;
            k.push_back(p);
        }
        else{
            T++;
            int x,y;
            cin >> x >> y;
            up.push_back({x,y});
        }
    }
    sort(all(k),[&](node x,node y){
        if(b[x.l] != b[y.l]) return b[x.l] < b[y.l];
        if(b[x.r] != b[y.r]) return b[x.r] < b[y.r];
        return x.t < y.t;
    });
    vector<int> ans(idb + 1);
    vector<int> mp(1e6 + 1);
    int l = 1, r = 0, kind = 0;
    int now = 0;
    for(int i = 0;i < idb; i++)
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
        while(now < k[i].t)
        {
            now++;
            int w = up[now - 1].first;
            if(l <= w && w <= r)
            {
                mp[a[w]]--;
                if(mp[a[w]] == 0) kind--;
            }
            swap(a[w],up[now-1].second);
            if(l <= w && w <= r)
            {
                mp[a[w]]++;
                if(mp[a[w]] == 1) kind++;
            }
        }
        while(now > k[i].t)
        {
            
            int w = up[now - 1].first;
            if(l <= w && w <= r)
            {
                mp[a[w]]--;
                if(mp[a[w]] == 0) kind--;
            }
            swap(a[w],up[now-1].second);
            if(l <= w && w <= r)
            {
                mp[a[w]]++;
                if(mp[a[w]] == 1) kind++;
            }
            now--;
        }
        ans[k[i].id] = kind;
    }
    for(int i = 1;i <= idb;i++)
    {
        cout << ans[i] << endl;
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
        cout << endl;
    }
}