#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
constexpr int Max = 1e5+5;

struct node
{
    int v,f,w;
};

vector<node> b(Max);
int fa[Max];

int find(int x)
{
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 0;i < m;i++)
    {
        cin >> b[i].v >> b[i].f >> b[i].w;
    }
    sort(b.begin(),b.begin()+m,[](node a,node b){
        return a.w < b.w;
    });
    int num = 0;
    int ans = 0;
    for(int i = 0;i < m;i++)
    {
        int fx = find(b[i].v);
        int fy = find(b[i].f);
        if(fx != fy)
        {
            num++;
            ans += b[i].w;
            fa[fx] = fy;
        }
        if(num == n-1) break;
    }
    if(num == n-1)cout << ans;
    else cout << "orz";
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