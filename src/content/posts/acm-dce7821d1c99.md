---
title: "Bellman–Ford"
published: 2026-11-16
category: ACM竞赛模板
tags: ["图论·最短路","学习实现"]
description: "与Dijkstra相比，这个算法唯一好处在于可以计算负权边，还能检测负环\r 时间复杂度O(nm);"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

与[Dijkstra](/posts/acm-keywords/#dijkstra)相比，这个算法唯一好处在于可以计算负权边，还能检测负环 时间复杂度O(nm);

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

与[Dijkstra](/posts/acm-keywords/#dijkstra)相比，这个算法唯一好处在于可以计算负权边，还能检测负环
时间复杂度O(nm);

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
与Dijkstra相比，这个算法唯一好处在于可以计算负权边，还能检测负环

时间复杂度O(nm);
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

struct node
{
    int x,y,z;
};
void solve()
{
    int n,m,s;
    cin >> n >> m >> s;
    vector<node> a(m);
    for(int i = 0;i < m;i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    vector<int> v(n+1,1e9);
    v[s] = 0;
    for(int i = 1;i <= n-1;i++)
    {
        for(auto k : a)
        {
            if(v[k.x] < 1e9 && v[k.y] > v[k.x] + k.z)
            {
                v[k.y] = v[k.x] + k.z;
            }
        }
    }

    //检测负环
    bool ok = 0;
    for(auto k : a)
    {
        if(v[k.x] < 1e9 && v[k.y] > v[k.x] + k.z)
        {
            ok = 1;
            break;
        }
    }
    if(ok) cout << "存在负环" << endl;
    else {
        for(int i = 1;i <=n;i++)
        {
            cout << v[i] << " ";
        }
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
```

## 相关知识点

[图论](/posts/acm-keywords/#graph) · [Dijkstra](/posts/acm-keywords/#dijkstra) · [负环](/posts/acm-keywords/#negative-cycle)

- [Tarjan](/posts/acm-18decad757c7/)
- [Johnson](/posts/acm-c0539a530149/)
- [Dijkstra](/posts/acm-38c0561d770b/)
- [差分约束](/posts/acm-67eb16b713f6/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-dce7821d1c99.cpp)
