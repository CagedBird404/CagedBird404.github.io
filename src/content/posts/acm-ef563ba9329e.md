---
title: "单向链表"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "单向链表的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

单向链表的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

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

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

