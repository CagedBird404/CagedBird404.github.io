---
title: "题"
published: 2026-11-16
category: "题"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## B_XOR_Array

原文件：`题/B_XOR_Array.cpp`

```cpp
//对于异或的构造，通常前缀和非常有用

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;


void solve()
{
    int n;cin >> n;
    vector<int> a;
    vector<int> b;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(x % 2 == 1)
        {
            a.emplace_back(x);
        }
        else b.emplace_back(x);
    }
    sort(all(a));
    sort(b.rbegin(),b.rend());
    if(a.size() == 0)
    {
        for(int i = 0;i < n;i++) cout << 0 << " ";
        return;
    }
    int num = b.size();
    int sum = a[a.size() - 1];
    cout << sum << " ";
    for(int i = 0;i < num;i++)
    {
        sum += b[i];
        cout << sum << " ";
    }
    for(int i = 1;i <= n - num - 1;i++)
    {
        if(i % 2 == 0)
        {
            cout << sum << " ";
        }
        else{
            cout << sum - b[b.size() - 1] << " ";
        }
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(10); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

## 传智杯中间数

原文件：`题/传智杯中间数.cpp`

```cpp
/*
给定一个长度为n的数组，求所有长度大于等于m的子区间其中间值的最大值，
长度为奇数就是中间数，偶数是中间偏左，从小到大排列

离散化 + 二分 + 前缀和
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    int l = 0;
    int r = b.size() - 1;
    int ans = b[0];
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        int x = b[mid];
        vector<int> c(n);
        for(int i = 0;i < n;i++)
        {
            if(a[i] >= x) c[i] = 1;
            else c[i] = -1;
        }
        vector<int> d(n+1);
        for(int i = 1;i <= n;i++)
        {
            d[i] = d[i-1] + c[i-1];
        }
        int ok = 0;
        int mi = LLONG_MAX;
        for(int i = m;i <= n;i++)
        {
            mi = min(mi,d[i-m]);
            if(d[i] - mi >= 0)
            {
                ok = 1;
                break;
            }
        }
        if(ok)
        {
            ans = x;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans;
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

