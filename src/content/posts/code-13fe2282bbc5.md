---
title: "基础 · 链表"
published: 2026-11-16
category: "基础"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## 单向链表

原文件：`基础/链表/单向链表.cpp`

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;


struct node
{
    int a;
    node* next;
};

void solve()
{
    node* f = new node; // 开头
    f -> next = NULL;
    node* e = f; // 结尾
    int x;
    while(cin >> x)
    {
        if(x == 0) break;
        node* k = new node;
        k -> next = NULL;
        k -> a = x;
        e -> next = k;
        e = k;
    }
    node* p = f -> next;
    while(p != NULL)
    {
        cout << p -> a << " ";
        p = p-> next;
    }
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

