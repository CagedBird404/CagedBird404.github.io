/*
欧拉路径：每个边比心经过一次，必须经过所有的边，形成的回路
欧拉回路（欧拉图）：起点和终点是同一个点
欧拉路径（半欧拉图）：起点和终点不是一个点

1、所有点入度和出度相同
2、剩余图是强联通的（任意两定可以互相到达）

对于欧拉路径
1、除了起点和终点外，其他需要满足入度等于出度
2、起点出度等于入度+1，终点反之，有且仅有一个起点和终点，这是固定的
3、如果在起点和终点之间再连一条有向边，那么就可以构成欧拉回路

对于无向图，你想构建一个欧拉回路，那么所有点都连接偶数条边
欧拉路径，那就是起点终点是奇数

时间复杂度 n + m
*/

/*
常见题型：
1. 一笔画问题：判断图能否一笔画完所有边，或求具体路径。最直接的模板题。
2. 字符串拼接/接龙：给一堆单词，能否首尾相接串成一条链（单词当边，首字母/尾字母当点）。经典题如 LeetCode 332「重新安排行程」、POJ 2337「Catenyms」。
3. 重建行程表：给一堆 [from, to] 机票，用完全部票重建一条合法行程（必然存在欧拉路径）。这就是 Hierholzer 的标准应用。
4. 多米诺骨牌 / 拼图：每块牌两端是数字，能否首尾接成长链。
5. 魔改的图论题：比如「删除最少的边使图成为欧拉图」「混合图（有向+无向）判欧拉」「求欧拉路径的第 k 条边」等，需要先判度数+连通性。
6. 网络流/DP 前置：某些题需要把图拆成若干欧拉回路（如「邮递员问题」Chinese Postman，找经过所有边的最短闭合路径）。
*/
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
    vector<vector<int>> a(n + 1);
    vector<int> ch(n + 1), ru(n + 1);
    for(int i = 1;i <= m;i++)
    {
        int x, y;
        cin >> x >> y;
        ch[x]++;
        ru[y]++;
        a[x].push_back(y);
    }

    //对于欧拉路径就找起点和终点
    int beg = -1, end = -1;
    for(int i = 1;i <= n;i++)
    {
        int v = ch[i] - ru[i];
        if(abs(v) >= 2)
        {
            cout << "这不是欧拉图" ;
            return;
        }
        if(v == 1)
        {
            if(beg != -1)
            {
                cout << "这不是欧拉图" ;
                return;
            }
            beg = i;
        }
        if(v == -1)
        {
            if(end != -1)
            {
                cout << "这不是欧拉图" ;
                return;
            }
            end = i;
        }
    }
    if(end + beg == -2)
    {
        cout << "这是欧拉回路";
    }
    else if(end != -1 && beg != -1)
    {
        cout << "这是欧拉路径";
    }
    else{
        cout << "这不是欧拉图" ;
        return;
    }
    vector<int> ans;
    auto dfs = [&](auto&& self , int u) -> void
    {
        while(!a[u].empty())
        {
            int v = a[u].back();
            a[u].pop_back();
            self(self, v);
        }
        ans.push_back(u);
    };
    if(beg != -1)
    {
        dfs(dfs, beg);
    }
    else 
    {
        for(int i = 1;i <= n;i++)
        {
            if(ch[i])
            {
                dfs(dfs, i);
                break;
            }
        }
    }
    //也可以在这里直接判断
    if(ans.size() != m + 1)
    {
        cout << "这不是欧拉回路";
        return;
    }
    reverse(all(ans));
    for(auto p : ans)
    {
        cout << p << " ";
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