---
title: "算法 · bfs"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## bfs 剪枝（待补）

原文件：`算法/bfs/bfs 剪枝（待补）.cpp`

```cpp
/*
我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词
你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们
如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的
返回你要拼出 target 的最小数量，如果任务不能完成，则返回 -1
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    
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
```

## bfs 多源找最近最大值

原文件：`算法/bfs/bfs 多源找最近最大值.cpp`

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
```

