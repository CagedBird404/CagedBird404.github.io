---
title: "1普通莫队概率类"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数据结构·离线算法","学习实现"]
description: "在l到r的范围内，选两个数字，相同的概率是多少，要化简到最小"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

在l到r的范围内，选两个数字，相同的概率是多少，要化简到最小

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

在l到r的范围内，选两个数字，相同的概率是多少，要化简到最小

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
在l到r的范围内，选两个数字，相同的概率是多少，要化简到最小
*/
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
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];

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

    vector<pair<int,int>> ans(m);

    vector<int> mp(n + 1, 0); 
    int l = 1, r = 0;         
    int now = 0;

    for(int i = 0; i < m; i++)
    {
        while(l < k[i].l)
        {
            now -= mp[a[l]] * (mp[a[l]] - 1) / 2;
            mp[a[l]]--;
            now += mp[a[l]] * (mp[a[l]] - 1) / 2;
            l++;
        }

        while(l > k[i].l)
        {
            l--;
            now -= mp[a[l]] * (mp[a[l]] - 1) / 2;
            mp[a[l]]++;
            now += mp[a[l]] * (mp[a[l]] - 1) / 2;
        }

        while(r < k[i].r)
        {
            r++;
            now -= mp[a[r]] * (mp[a[r]] - 1) / 2;
            mp[a[r]]++;
            now += mp[a[r]] * (mp[a[r]] - 1) / 2;
        }

        while(r > k[i].r)
        {
            now -= mp[a[r]] * (mp[a[r]] - 1) / 2;
            mp[a[r]]--;
            now += mp[a[r]] * (mp[a[r]] - 1) / 2;
            r--;
        }

        int len = k[i].r - k[i].l + 1;
        int base = len * (len - 1) / 2;

        ans[k[i].id] = {now, base};
    }

    for(int i = 0;i < m; i++)
    {
        if(ans[i].first == 0)
        {
            cout << "0/1" << endl;
            continue;
        }
        int g = gcd(ans[i].first, ans[i].second);
        cout << ans[i].first / g << "/" << ans[i].second / g << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TT = 1;
    cin >> TT;
    while (TT--)
        solve();
}
```

## 相关知识点

[莫队](/posts/acm-keywords/#mo) · [离散化](/posts/acm-keywords/#discretization)

- [1普通莫队](/posts/acm-ec9347e15883/)
- [3只增回滚莫队](/posts/acm-cd676791c6e8/)
- [离散化天际线](/posts/acm-eed522332a27/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-8ac8fa4d3177.cpp)
