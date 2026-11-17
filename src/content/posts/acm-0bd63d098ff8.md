---
title: "最小表示法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["字符串","学习实现"]
description: "若长度为 n 的字符串 s 中可以选择一个位置 i，使得  \r si ⋯sn s1 ⋯si−1 =t，则称 s 与 t 循环同构。字符串 s 的最小表示为与 s 循环同构的所有字符串中字典序最小的字符串\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

若长度为 n 的字符串 s 中可以选择一个位置 i，使得   si ⋯sn s1 ⋯si−1 =t，则称 s 与 t 循环同构。字符串 s 的最小表示为与 s 循环同构的所有字符串中字典序最小的字符串

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

若长度为 n 的字符串 s 中可以选择一个位置 i，使得
si ⋯sn s1 ⋯si−1 =t，则称 s 与 t 循环同构。字符串 s 的最小表示为与 s 循环同构的所有字符串中字典序最小的字符串
求最小字典序字符串
时间复杂度On

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
若长度为 n 的字符串 s 中可以选择一个位置 i，使得  
si ⋯sn s1 ⋯si−1 =t，则称 s 与 t 循环同构。字符串 s 的最小表示为与 s 循环同构的所有字符串中字典序最小的字符串
求最小字典序字符串
时间复杂度On
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s += s;
    int i = 0,j = 1,k = 0;
    while(i < n && j < n && k < n)
    {
        if(s[i+k] == s[j+k]) k++;
        else{
            if(s[i+k] > s[j+k]) i = i + k + 1;
            else j = j + k + 1;
            if(i == j) j++;
            k = 0;
        }
    }
    int ans = min(i,j);
    cout << s.substr(ans,n);
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
        //cout << endl;
    }
}
```

## 相关知识点

[KMP](/posts/acm-keywords/#kmp) · [Trie](/posts/acm-keywords/#trie) · [字符串哈希](/posts/acm-keywords/#hash) · [后缀自动机](/posts/acm-keywords/#sam)

- [KMp算法字符串](/posts/acm-e8086e7e153a/)
- [AC自动机](/posts/acm-774260652a67/)
- [哈希前缀字符串双](/posts/acm-c3a6c2d6240d/)
- [后缀自动机](/posts/acm-17cf51dc4e49/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-0bd63d098ff8.cpp)
