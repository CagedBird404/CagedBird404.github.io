---
title: "题"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "题的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

题的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

> **易错点：** 这是交互题草稿，缺少题面、查询次数限制和交互器，不能当作通用模板或宣称正确。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
//#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int num;
    cout << "? 1 1" <<endl;
    cin >> num;
    vector<pair<int ,int>> a;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            cout << "? " << i <<" " << j <<endl;
            int nu;
            cin >> nu;
            if(nu == num + 1)
            {
                a.push_back({i, j});
            }
            else{
                 cout << "? " << i <<" " << j <<endl;
                cin >> nu;
            }
        }
    }
    vector<int> b( n + 1);
    for(int i = 1;i <= n;i++) b[i] = i;
    reverse(all(a));
    for(int i = 0;i < a.size();i++)
    {
        swap(b[a[i].second], b[a[i].first]);
    }
    cout <<"! " ;
    for(int i = 1;i <= n;i++) cout << b[i] << " ";
}

signed main()
{
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}
```

## 相关知识点

[复杂度](/posts/acm-keywords/#complexity)

- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-c1719c2b19fd.cpp)
