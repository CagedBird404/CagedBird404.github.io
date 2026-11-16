---
title: "算法 · 二叉树"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 二叉树

原文件：`算法/二叉树/二叉树.cpp`

```cpp
/*
二叉树是一种树形结构
他的子节点最多只能有两个
最开始的节点叫做根节点

满二叉树：每个节点要么有两个节点，要么没有节点
完全二叉树：除了最后一层，其他全为满节点，最后一层节点是从左到右连续的
二叉搜索树：每个左节点小于根节点，右节点大于根节点
平衡二叉树：左右节点的高度差不超过1

对于遍历顺序：
前序遍历：根->左->右
中序遍历：左->根->右
后序遍历：左->右->根
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

