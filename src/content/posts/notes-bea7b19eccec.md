---
title: "纪念我的第一个紫题"
published: 2026-11-16
category: "题解"
tags: [学习笔记, C++]
description: "保留原意整理的学习笔记。"
draft: false
---

# P5906 【模板】回滚莫队&不删除莫队

## 题目背景

这是一道模板题。

## 题目描述

给定一个序列，多次询问一段区间 $[l,r]$，求区间中**相同的数的最远间隔距离**。

序列中两个元素的**间隔距离**指的是**两个元素下标差的绝对值**。

## 输入格式

第一行一个整数 $n$，表示序列长度。

第二行 $n$ 个整数，描述这个序列。

第三行一个整数 $m$，表示询问个数。

之后 $m$ 行，每行两个整数 $l,r$ 表示询问区间。

## 输出格式

共 $m$ 行，每行一个整数表示答案。如果区间内不存在两个数相同，则输出 $0$。

## 输入输出样例 #1

### 输入 #1

```
8
1 6 2 2 3 3 1 6
5
1 4
2 5
2 8
5 6
1 7
```

### 输出 #1

```
1
1
6
1
6

```

## 说明/提示

记 $a_i$ 表示序列元素。

对于 $40\%$ 的数据，满足 $1\leq a_i \leq 400$，$1\leq n,m\leq 60000$。

对于 $100\%$ 的数据，满足 $1\leq n,m\leq 2\cdot 10^5$，$1\leq a_i\leq 2\cdot 10^9$。

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

struct node{
    int l,r,id;
};

void solve()
{
    int n,m;
    cin >> n ;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<int> unique_vals = a;
    sort(all(unique_vals));
    unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());

    unordered_map<int, int> compress;

    for (int i = 0; i < unique_vals.size(); i++) {
        compress[unique_vals[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = compress[a[i]];
    }

    int len = sqrt(n);
    int num = (n + len - 1) / len;

    vector<int> b(n+1);
    for(int i = 1;i <= n;i++)
        b[i] = (i - 1) / len + 1;

    vector<int> bl(num + 1),br(num + 1);
    for(int i = 1;i <= num;i++)
    {
        bl[i] = (i - 1) * len + 1;
        br[i] = min(n, i * len);
    }
    cin >> m;
    vector<node> k(m);
    for(int i = 0;i < m;i++)
    {
        cin >> k[i].l >> k[i].r;
        k[i].id = i;
    }
    sort(all(k),[&](node a,node c){
        if(b[a.l] != b[c.l]) return b[a.l] < b[c.l];
        return a.r < c.r;
    });
    vector<int> ans(m);
    for(int nk = 1, qi = 0; nk <= num && qi < m; nk++)
    {
        vector<int> mp(unique_vals.size());
        vector<int> mp1(unique_vals.size(),1e18);
        int now = 0;
        int l = br[nk] + 1, r = br[nk];
        for( ; qi < m && b[k[qi].l] == nk ; qi++)
        {
            if(k[qi].r <= br[nk])
            {
                vector<int> tmp(unique_vals.size());
                int tnow = 0;
                for(int i = k[qi].l; i <= k[qi].r; i++) mp[a[i]] = max(i, mp[a[i]]);
                for(int i = k[qi].l; i <= k[qi].r; i++) tnow = max(tnow,abs(mp[a[i]] - i));
                ans[k[qi].id] = tnow;
            }
            else{
                while(r < k[qi].r)
                {
                    r++;
                    mp[a[r]] = max(r, mp[a[r]]);
                    mp1[a[r]] = min(r, mp1[a[r]]);
                    if(mp[a[r]] != 0 && mp1[a[r]] != 1e18)now = max(now, mp[a[r]] - mp1[a[r]]);
                }
                int temp = now;
                vector<int> tmp = mp;
                vector<int> tmp1 = mp1;
                while(l > k[qi].l)
                {
                    l--;
                    mp[a[l]] = max(l, mp[a[l]]);
                    mp1[a[l]] = min(l, mp1[a[l]]);
                    if(mp[a[l]] != 0 && mp1[a[l]] != 1e18)now = max(now, mp[a[l]] - mp1[a[l]]);
                }
                ans[k[qi].id] = now;
                now = temp;
                mp = tmp;
                mp1 = tmp1;
                l = br[nk] + 1;
            }
        }
    }
    for(int i = 0;i < m; i++)
    {
        cout << ans[i] << endl;;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TT = 1;
    //cin >> TT;
    while (TT--)
        solve();
}

```

![题目记录截图](/images/notes-first-purple.png)

> 这是我的第一个紫题，特此纪念 
> 时间2026年1月18日23:08:17