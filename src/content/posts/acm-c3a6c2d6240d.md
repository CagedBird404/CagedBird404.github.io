---
title: "哈希前缀字符串双"
published: 2026-11-16
category: ACM竞赛模板
tags: ["字符串","学习实现"]
description: "这里用于解决两个字符串的公共最长子字符串\r 复杂度O(n+m)log min(n,m)"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

这里用于解决两个字符串的公共最长子字符串 复杂度O(n+m)log min(n,m)

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

这里用于解决两个字符串的公共最长子字符串
复杂度O(n+m)log min(n,m)

> **易错点：** 原实现把两个 64 位哈希压成一个 64 位值，会丢失信息。它是概率比较，不能作为绝对相等证明。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
这里用于解决两个字符串的公共最长子字符串
复杂度O(n+m)log min(n,m)
*/


#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

typedef unsigned long long ull;

constexpr int MOD = 1e9 + 7;
const ull B1 = 131;
const ull B2 = 137;

string s1,s2;
vector<ull> h1,h2,p1,p2;
vector<ull> H1,H2,P1,P2;

pair<ull,ull> get1(int l,int r)
{
    return {h1[r] - h1[l-1] * p1[r-l+1],h2[r] - h2[l-1] * p2[r-l+1]};
}

pair<ull,ull> get2(int l,int r)
{
    return {H1[r] - H1[l-1] * P1[r-l+1],H2[r] - H2[l-1] * P2[r-l+1]};
}

bool check(int sz)
{
    if(sz == 0) return 1;
    unordered_set<ull> st;
    for(int i = 1; i <= s1.size() - sz + 1;i++)
    {
        auto [x,y] = get1(i,i + sz - 1);
        ull v = (x << 32) ^ y;
        st.insert(v);
    }
    for(int i = 1; i <= s2.size() - sz + 1;i++)
    {
        auto [x,y] = get2(i,i + sz - 1);
        ull v = (x << 32) ^ y;
        if(st.count(v)) return 1;
    }
    return 0;
}
void solve()
{
    
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    h1.assign(n+1,0); h2.assign(n+1,0);
    p1.assign(n+1,1); p2.assign(n+1,1);
    H1.assign(m+1,0); H2.assign(m+1,0);
    P1.assign(m+1,1); P2.assign(m+1,1);
    for(int i = 1;i <= n;i++)
    {
        h1[i] = h1[i-1] * B1 + s1[i-1];
        h2[i] = h2[i-1] * B2 + s1[i-1];
        p1[i] = p1[i-1] * B1;
        p2[i] = p2[i-1] * B2;
    }
    for(int i = 1;i <= m;i++)
    {
        H1[i] = H1[i-1] * B1 + s2[i-1];
        H2[i] = H2[i-1] * B2 + s2[i-1];
        P1[i] = P1[i-1] * B1;
        P2[i] = P2[i-1] * B2;
    }
   int l = 0;
   int r = min(n,m);
   int ans = 0;
   while(l <= r)
   {
        int mid = l + (r - l)/2;
        if(check(mid))
        {
            l = mid + 1;
            ans = mid;
        } 
        else r = mid - 1;
   }
   cout << ans;
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
- [后缀自动机](/posts/acm-17cf51dc4e49/)
- [最小表示法](/posts/acm-0bd63d098ff8/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-c3a6c2d6240d.cpp)
