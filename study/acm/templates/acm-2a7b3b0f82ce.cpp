/*
这个和二分图的区别是，他带了权值
要求权值的最大

初始化，左部顶标 = max(出边边权最大值)，右部顶表 = 0

求最小的边权匹配和，就是将边权值反过来，改成负数
再求最大匹配边权和，注意左部要再次初始化值
最后结果要取反再加
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int n, m;
vector<vector<int>> w;
vector<int> match, lx, ly, slack, pre;
vector<bool> visy;

void bfs(int u) {
    int x, y = 0, yy = 0, delta;
    fill(slack.begin(), slack.end(), 2e18);
    fill(pre.begin(), pre.end(), 0);
    fill(visy.begin(), visy.end(), false);
    
    match[y] = u;
    while (true) {
        x = match[y];
        delta = 2e18;
        visy[y] = true;
        for (int i = 1; i <= n; i++) {
            if (visy[i]) continue;
            if (lx[x] + ly[i] - w[x][i] < slack[i]) {
                slack[i] = lx[x] + ly[i] - w[x][i];
                pre[i] = y;
            }
            if (slack[i] < delta) {
                delta = slack[i];
                yy = i;
            }
        }
        for(int i = 0; i <= n; i++)
        {
            if(visy[i])
            {
                lx[match[i]] -= delta;
                ly[i] += delta;
            } 
            else{
                slack[i] -= delta;
            }
        }
        y = yy;
        if(match[y] == 0) break;
    }
    while(y){
        match[y] = match[pre[y]];
        y = pre[y];
    }
}

void solve()
{
    cin >> n >> m; // n左部点数，m右部点数(如果要求完美匹配要求n <= m)
    // 假设都是n吧，如果不都是，可以把缺的补0
    // 对于不存在的边，权值设为-INF
    
    w.assign(n + 1, vector<int>(n + 1, -2e18)); // 边权矩阵，1-indexed
    
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        w[u][v] = max(w[u][v], weight);
    }

    match.assign(n + 1, 0); // 右部点匹配的左部点
    lx.assign(n + 1, -2e18); // 顶标
    ly.assign(n + 1, 0);
    slack.assign(n + 1, 0);
    pre.assign(n + 1, 0);
    visy.assign(n + 1, false);

    // 初始化lx为左部点出边的最大权值
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
        {
            lx[i] = max(lx[i], w[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) 
    {
        bfs(i);
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        if (w[match[i]][i] != -2e18)
        {
            res += w[match[i]][i];
        }
    }
    
    cout << res << endl;
    for (int i = 1; i <= n; ++i) {
        // 输出右部点i匹配的左部点，没有则为0。注意这里的变量名不要弄混，一般题目如果左边少，可能要特殊处理
        cout << match[i] << " \n"[i == n];
    }
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