---
title: "bfs 剪枝（待补）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治","学习实现"]
description: "我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词\r 你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词 你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

我们有n种不同贴纸，每个贴纸上面有一个小写英文字母单词
你想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母，并排列他们
如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的
返回你要拼出 target 的最小数量，如果任务不能完成，则返回 -1

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

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

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-7114cfaaefbe.cpp)
