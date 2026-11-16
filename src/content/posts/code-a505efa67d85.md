---
title: "算法 · 倍增st表"
published: 2026-11-16
category: "算法"
tags: [学习笔记, C++]
description: "按主题整理的原始学习代码，保留注释与实现。"
draft: false
---

本文整理自我的本地学习代码，按文件分节，保留原有实现与注释。

> 整理说明：这些是不同阶段的练习、模板和实验代码，未逐一编译或验证，不代表所有实现均正确。使用时需结合题目、输入范围和编译环境。部分代码使用 GCC 的 `bits/stdc++.h`，Windows 小程序可能依赖 `windows.h`、`conio.h`。

## st表求gcd

原文件：`算法/倍增st表/st表求gcd.cpp`

```cpp
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
    vector<vector<int>> a(n,vector<int>(20));
    for(int i=0;i<n;i++) cin >> a[i][0];
    int Max = log2(n) + 1;
    for(int p=1;p<Max;p++)
    {
        for(int i=0;i + (1 << p) - 1< n;i++)
        {
            a[i][p] = gcd(a[i][p-1],a[i + (1 << (p - 1))][p - 1]);
        }
    }
    vector<int> Log(n + 1);
    Log[1] = 0;
    for(int i=2;i <= n;i++)
    {
        Log[i] = Log[i / 2] + 1;
    }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int sz = Log[r - l + 1];
        int ans = gcd(a[l][sz],a[r - (1 << sz) + 1][sz]);
        cout << ans<<endl;
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

## st表求给定区间最大元素差值

原文件：`算法/倍增st表/st表求给定区间最大元素差值.cpp`

```cpp
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
    vector<vector<int>> st(n,vector<int>(20));
    vector<vector<int>> st1(n,vector<int>(20));
    vector<int> Log(n+1);  // 预处理一直到n，所有数的恰好比这个数小或者等于，的2的k次方的k是多大
    Log[1]=0;
    for(int i=2;i<=n;i++)
    {
        Log[i] = Log[i/2] + 1;  // 这样可以更快的寻找
    }
    for(int i=0;i<n;i++)
    {
        cin >> st[i][0];
        st1[i][0]=st[i][0];
    }
    int MAX = Log[n]+1;
    for(int p=1;p<MAX;p++)
    {
        for(int i=0;i+(1<<p)-1 < n;i++)  //终点 = 起点 + 长度 - 1
        {
                st[i][p] = max(st[i][p-1],st[i+(1<<(p-1))][p-1]);
                st1[i][p] = min(st1[i][p-1],st1[i+(1<<(p-1))][p-1]);
        }
    }
    
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        int k=Log[r-l+1];
        //对于这种分半的形式，不能对那种对于区间求和一类的进行计算，因为会有重复元素
        int Max = max (st[l][k] , st[r-(1 << k)+1][k]);
        int Min = min (st1[l][k] , st1[r-(1 << k)+1][k]);    // 不用无限逼近，将其分成两半，后一半的起点恰好是
        cout<<Max - Min<<endl;                               // 一个小于n的l+2^k，终点是r
    }
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve();
    }
}
```

## 倍增st表

原文件：`算法/倍增st表/倍增st表.cpp`

```cpp
/*
线段上有n个点，给定每个点i往右跳一步的最远覆盖的点jump[i]
注：已知从任意点出发都能达到最后的点，并且在 i < j时，必有jump[i] <= jump[j]
(1) 如何构建一个表
可以从任意点出发：跳一步，跳两步，跳四步，跳八步...每回最远能到达的点
也就是可以查询，从任意点i出发，任意跳2的p次方步，最远能到达的点
（
(2) 如何快速计算任意两点间，最少跳几步能到达

构建出的表叫st表
构建方式 st[i][p] = st[[i][p-1]][p-1],p代表：跳2的p次方步，
表大小为 n*logn 
利用st表，从x到y跳跃的过程中，先从最大步长开始，每次步长减少一半去尝试，最终答案复杂度为
          logn
*/

/*
行代表跳几步最远能到达的点，分别为2的0次方，1次方，以此类推，列代表跳哪部，类似于动态规划
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;


void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> st(n,vector<int>(20));
    for(int i=0;i<n;i++)
    {
        cin >> st[i][0];
    }
    int Max = log2(n)+1;
    for(int p=1;p<Max;p++)
    {
        for(int i=0;i<n;i++)
        {
            if(st[i][p-1] < n)
            {
                st[i][p] = st[st[i][p-1]][p-1];
            }
            else{
                st[i][p] = n -1;
            }
        }
    }
    int x,y;
    cin >> x >> y;
    int now = x;
    int ans =0;
    for(int p=Max-1;p>=0;p--)
    {
        if(st[now][p] <= (y >> 1))
        {
            ans += (1<<p);
            now = st[now][p];
        }
        if(now >= y)
        {
            break;
        }
    }
    cout << ans<<endl;
}

signed main()
{
    cin.tie(0)->ios::sync_with_stdio(0);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    //cin >> TT; 
    while (TT--)
    {
        solve(); 
        cout << endl;
    }
}
```

