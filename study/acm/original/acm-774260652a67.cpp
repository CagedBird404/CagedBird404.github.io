/*
先使用前缀树。再使用fail指针（用bfs）

作用是找到敏感词在文本中出现几次
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> end(n);

    vector<vector<int>> tree(1, vector<int>(26));
    
    int cnt = 0;

    //建树
    for(int i = 0; i < n;i++)
    {
        string s;
        cin >> s;
        int now = 0;
        for(int j = 0; j < s.size();j++)
        {
            int c = s[j] - 'a';
            if(!tree[now][c]) 
            {
                tree.push_back(vector<int>(26));
                tree[now][c] = ++cnt;
            }
            now = tree[now][c];
        }
        end[i] = now;
    }
    //建立fail指针
    vector<int> fail(cnt + 1);
    queue<int> q;
    vector<int> orz;
    for(int i = 0;i < 26;i++)
    {
        if(tree[0][i]) q.push(tree[0][i]);
    }
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        orz.push_back(now);
        for(int i = 0;i < 26;i++)
        {
            if(!tree[now][i])
            {
                tree[now][i] = tree[fail[now]][i];
            }
            else{
                fail[tree[now][i]] = tree[fail[now]][i];
                q.push(tree[now][i]);
            }
        }
    }
    //记录词频
    string s;
    cin >> s;
    int now = 0;vector<int> times(cnt + 1);
    for(int i = 0;i < s.size();i++)
    {
        times[tree[now][s[i] - 'a']]++;
        now = tree[now][s[i] - 'a'];
    }
    //反向建图
    //累加子点的times次数
    for(int i = orz.size() - 1;i >= 0;i--)
    {
        int u = orz[i];
        times[fail[u]] += times[u];
    }
    //统计答案
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        ans += times[end[i]];
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
        cout << endl;
    }
}