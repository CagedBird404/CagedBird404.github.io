/*
给定平面上所有的点，凸包就是将最外层的点连接起来的
凸多边形，他能包含点集中所有的点

时间复杂度nlong(n)
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node{
    double x, y;
};

int cc(node a, node b, node c) // 叉积
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dd(node a, node b) // 距离
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void solve()
{
    int n;
    cin >> n;
    vector<node> a(n);
    for(int i = 0;i < n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(all(a), [](node p, node q){
        if(p.x != q.x) return p.x < q.x;
        return p.y < q.y;
    });
    vector<node> p;
    // 下凸包
    for(int i = 0; i < n; i++){
        while(p.size() > 1 && cc(p[p.size()-2], p.back(), a[i]) <= 0) {
            p.pop_back();
        }
        p.push_back(a[i]);
    }
    // 上凸包
    int t = p.size();
    for(int i = n - 2; i >= 0; i--){
        while((int)p.size() > t && cc(p[p.size()-2], p.back(), a[i]) <= 0) {
            p.pop_back();
        }
        p.push_back(a[i]);
    }
    // 去除最后一个重复点
    if(p.size() > 1) p.pop_back();

    double ans = 0;
    for(int i = 1; i < p.size(); i++) {
        ans += dd(p[i-1], p[i]);
    }
    if(p.size() > 1) ans += dd(p.back(), p[0]); // 闭合
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