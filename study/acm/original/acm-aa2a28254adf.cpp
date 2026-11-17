#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int ksm(int base,int a)
{
    int ans=1;
    while(a)
    {
        if (a & 1)
        {
            ans = ans * base;
        }
        base = base * base;
        a >>=1;
    }
    return ans;
}

struct date{
    int x;
    int y;
};
int cal(date a,date b)
{
    return ksm((a.x - b.x) , 2) + ksm((a.y - b.y) , 2);
}
vector<date> a;
int ans; 
int fz(int l,int r)
{
    if(l>=r)
    {
        return LLONG_MAX;
    }
    if(l+1 == r)
    {
        return cal(a[l],a[r]);
    }
    int mid = l + (r - l) / 2;
    int s=fz(l,mid);
    int h=fz(mid + 1,r);
    ans = min(s,h);
    vector<date> p;
    for (int i = l;i<=r ;i++)
    {
        if((a[i].x - a[mid].x) * (a[i].x - a[mid].x) < ans)
        {
            p.emplace_back(a[i]);
        }
    }
    sort(all(p),[](auto a,auto b){
        return a.y < b.y;
    });
    for (int i=0;i<p.size();i++)
    {
        for(int j=i+1;j<p.size();j++)
        {
            if((p[i].y - p[j].y) * (p[i].y - p[j].y) < ans)
            {
                ans = min(ans,cal(p[i],p[j]));
            }
            else{
                break;
            }
        }
    }
    return ans;
}
void solve()
{
    ans = LLONG_MAX;
    int n;
    cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(all(a),[](date a,date b){
        return a.x<b.x;
    });
    cout<<fz(0,n-1);

}
//将每组测试用例的处理逻辑写在里面

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}