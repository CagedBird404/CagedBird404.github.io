---
title: "bfs 剪枝（待补）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治"]
description: "我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词\r 你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词 你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词
你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们
如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的
返回你要拼出 target 的最小数量，如果任务不能完成，则返回 -1

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

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

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)

