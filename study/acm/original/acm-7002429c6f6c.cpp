#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> head(n + 1), next{0}, to{0}, wig{0};
    int op = 1;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        //这里如果是双向的，那么加两边就好了
        /*
        这里其实就很像头插法，就是不断更新这个点最后一条边的头部，然后你记录了这个头部边的
        上一个头部，那么他就可以变成一串记录的头部，根据这个头部你就可以找到你这个点所有的邻居
        */
        to.push_back(v);
        wig.push_back(w);
        next.push_back(head[u]);
        head[u] = cnt++;
    }
    //这里演示怎么便利一个点的邻居
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        for(int i = head[x]; i > 0; i = next[i])
        {
            cout << to[i] << " " << wig[i] << endl;
        }
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