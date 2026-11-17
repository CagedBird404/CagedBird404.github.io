/*
套路：
1.分析父树得到答案需要子树的哪些信息
2.把子树信息的全集定义成递归返回值
3.通过递归让子树返回全集信息
4。整合子树的全集信息得到父树的全集信息并返回
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
constexpr int N = 2e5 + 10;
vector<int> adj[N];
int dp[N][2]; // dp[u][0] 不选u, dp[u][1] 选u
int a[N];     // 节点权值

void dfs(int u, int p)
{
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (auto v : adj[u])
    {
        if (v == p) continue;
        dfs(v, u);
        // 状态转移方程（以最大权独立集为例：“没有上司的舞会”）
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

void solve()
{
    int n;
    cin >> n;
    
    // 初始化清空
    for(int i = 1; i <= n; i++) 
    {
        adj[i].clear();
        dp[i][0] = dp[i][1] = 0;
    }
    
    // 读入点权
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    // 读入边
    for(int i = 1; i < n; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0); // 从根节点(默认1)开始DFS
    
    cout << max(dp[1][0], dp[1][1]) << endl;
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