---
title: "折半搜索"
published: 2026-11-16
category: ACM竞赛模板
tags: [学习笔记, C++]
description: "保留原意整理的学习笔记。"
draft: false
---

[返回分类目录](/posts/acm-index/) · [相关知识点](/posts/acm-keywords/)


# P4799 [CEOI 2015] 世界冰球锦标赛 (Day2)

## 题目描述

**译自 [CEOI2015](https://ceoi2015.fi.muni.cz/tasks.php) Day2 T1「[Ice Hockey World Championship](https://ceoi2015.fi.muni.cz/day2/eng/day2task1-eng.pdf)」**

> 今年的世界冰球锦标赛在捷克举行。Bobek 已经抵达布拉格，他不是任何团队的粉丝，也没有时间观念。他只是单纯的想去看几场比赛。如果他有足够的钱，他会去看所有的比赛。不幸的是，他的财产十分有限，他决定把所有财产都用来买门票。

给出 Bobek 的预算和每场比赛的票价，试求：如果总票价不超过预算，他有多少种观赛方案。如果存在以其中一种方案观看某场比赛而另一种方案不观看，则认为这两种方案不同。

## 输入格式

第一行，两个正整数 $N$ 和 $M(1 \leq N \leq 40,1 \leq M \leq 10^{18})$，表示比赛的个数和 Bobek 那家徒四壁的财产。  

第二行，$N$ 个以空格分隔的正整数，均不超过 $10^{16}$，代表每场比赛门票的价格。

## 输出格式

输出一行，表示方案的个数。由于 $N$ 十分大，注意：答案 $\le 2^{40}$。

## 输入输出样例 #1

### 输入 #1

```
5 1000
100 1500 500 500 1000
```

### 输出 #1

```
8
```

## 说明/提示

#### 样例解释
八种方案分别是：

 - 一场都不看，溜了溜了  
 - 价格 $100$ 的比赛  
 - 第一场价格 $500$ 的比赛  
 - 第二场价格 $500$ 的比赛  
 - 价格 $100$ 的比赛和第一场价格 $500$ 的比赛  
 - 价格 $100$ 的比赛和第二场价格 $500$ 的比赛  
 - 两场价格 $500$ 的比赛  
 - 价格 $1000$ 的比赛

有十组数据，每通过一组数据你可以获得 10 分。各组数据的数据范围如下表所示：

|数据组号|$1-2$|$3-4$|$5-7$|$8-10$|
|-|:-:|:-:|:-:|:-:|
|$N \leq$|$10$|$20$|$40$|$40$|
|$M \leq$|$10^6$|$10^{18}$|$10^6$|$10^{18}$|

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;
int ans = 0;int n,m;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
void dfs(int now,int l,int r,vector<int> &k)
{
    if(now > m) return;
    else
    {
        ans++;
        k.emplace_back(now);
    }
    for(int i = l+1;i < r;i++)
    {
        if(!b[i])
        {
            b[i] = 1;
            dfs(now + a[i],i,r,k);
            b[i] = 0;
        }
    }
}
void solve()
{
    
    cin >> n >> m;

    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        if(x <= m) a.emplace_back(x);
    }
    b.resize(a.size(),0);
    for(int i = 0;i < a.size()/2;i++)
    {
        b[i] = 1;
        dfs(a[i],i,a.size()/2,c);
        b[i] = 0;
    }
    for(int i = a.size()/2;i < a.size();i++)
    {
        b[i] = 1;
        dfs(a[i],i,a.size(),d);
    }
    sort(all(c));
    for(int i = 0;i < d.size();i++)
    {
        ans += upper_bound(all(c),m - d[i]) - c.begin();
    }
    cout << ans + 1;
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
        //cout << endl;
    }
}
```

代码解释：
1. 将n分半，对每一半进行dfs暴搜，这样可以降低复杂度
2. 将所有符合的组合分别存入两个数组里
3. 一个数组进行排序，对另外一个遍历找有多少组合符合情况将其加入
4. 对于遍历可以进行二分优化