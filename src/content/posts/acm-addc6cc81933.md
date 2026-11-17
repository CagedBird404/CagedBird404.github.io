---
title: "bfs 多源找最近最大值"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治"]
description: "bfs特点是逐层扩散，从源头目标点扩散了几层，最短路径就是多少\r bfs使用特征是，任意两个节点之间的 相互距离 相同\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

bfs特点是逐层扩散，从源头目标点扩散了几层，最短路径就是多少 bfs使用特征是，任意两个节点之间的 相互距离 相同

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

bfs特点是逐层扩散，从源头目标点扩散了几层，最短路径就是多少
bfs使用特征是，任意两个节点之间的 相互距离 相同
bfs开始时可以是多个源头，也可以是单个源头
bfs频繁使用队列，可以是单点弹出，也可以是整层弹出
bfs进行时，进入队列的节点需要标记状态，防止一个节点频繁进出队列
bfs进行时可能会包括 剪枝策略 的设计
m*n的矩阵，复杂度为O(m*n)

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
bfs特点是逐层扩散，从源头目标点扩散了几层，最短路径就是多少
bfs使用特征是，任意两个节点之间的 相互距离 相同
bfs开始时可以是多个源头，也可以是单个源头
bfs频繁使用队列，可以是单点弹出，也可以是整层弹出
bfs进行时，进入队列的节点需要标记状态，防止一个节点频繁进出队列
bfs进行时可能会包括 剪枝策略 的设计
m*n的矩阵，复杂度为O(m*n)
*/
/*
地图分析
你现在手里有一份n*m的地图
上面每个格子都用0或者1标记，0代表海洋，1代表陆地
请你找出一个海洋单元格，这个海洋单元格到离他最近的陆地单元格距离是最大的
并返回距离，如果只有海洋或者陆地，请返回-1
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
vector<vector<int>> mp(101,vector<int>(101));
queue<pair<int,int>> q;
int l,r,n,m;
vector<vector<int>> visited(101,vector<int>(101));

/*
(x,y) i来到0位置：x + move[i],y + move[i+1] -> x-1,y
(x,y) i来到1位置：x + move[i],y + move[i+1] -> x,y+1
(x,y) i来到2位置：x + move[i],y + move[i+1] -> x+1,y
(x,y) i来到3位置：x + move[i],y + move[i+1] -> x,y-1
*/
void solve()
{
    l=r=0;
    cin >> n >> m;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]==1)
            {
                q.push({i,j});
                visited[i][j]=1;
                num++;
            }
        }
    }
    int move[5]={-1,0,1,0,-1};
    if(num==0 || num==(n*m))
    {
        cout<<"-1";
        return;
    }
    int level=0;
    while(!q.empty())
    {
        auto [x,y] = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + move[i];
            int ny = y + move[i+1];
            if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && mp[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = visited[x][y]++;
                level = max(level,visited[nx][ny]);
                q.push({nx,ny});
            }
        }
    }
    cout << level <<endl;
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
```

## 相关知识点

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [AC自动机](/posts/acm-774260652a67/)

