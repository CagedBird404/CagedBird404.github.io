---
title: "1线段树基础加法"
published: 2026-11-16
category: ACM竞赛模板
tags: ["数据结构·区间查询","学习实现"]
description: "线段树维护信息类型：\r 父范围上某个信息，可以用O1的时间，从子范围的信息加工得到\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

[线段树](/posts/acm-keywords/#segment-tree)维护信息类型： 父范围上某个信息，可以用O1的时间，从子范围的信息加工得到

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

[线段树](/posts/acm-keywords/#segment-tree)维护信息类型：
父范围上某个信息，可以用O1的时间，从子范围的信息加工得到
满足的：累加和，最大值，最小值
不满足：某范围出现次数最大的数
[线段树](/posts/acm-keywords/#segment-tree)经典功能（但系调用时间都为log n）
1、范围查询
2、范围修改

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
线段树维护信息类型：
父范围上某个信息，可以用O1的时间，从子范围的信息加工得到
满足的：累加和，最大值，最小值
不满足：某范围出现次数最大的数

线段树经典功能（但系调用时间都为log n）
1、范围查询
2、范围修改

*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int n, m;
vector<int> a, d;//a记录初始数组，d是分出原来的组的加和
vector<int> b; //懒标记数组

//建树
void build(int l ,int r, int p) //范围l，r，标号p
{
    if(l == r)
    {
        d[p] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(l, mid, p * 2);
    build(mid + 1, r, 2 * p + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

void push_down(int p, int l, int r) {
    if (b[p] == 0) return;

    int mid = (l + r) >> 1;

    d[p * 2]     += b[p] * (mid - l + 1);
    d[p * 2 + 1] += b[p] * (r - mid);

    b[p * 2]     += b[p];
    b[p * 2 + 1] += b[p];

    b[p] = 0;
}


//区间修改
void update(int l, int r, int c, int s, int t, int p) //c代表加的值，s和t是当前区间
{
    if(r < s || l > t) return;
    if(l <= s && t <= r)
    {
        d[p] += c * (t - s + 1);
        b[p] += c;
        return;
    }
    int mid = s + (t - s) / 2;
    
    push_down(p, s, t);

    if(l <= mid) update(l, r, c, s, mid, p * 2);
    if(r > mid) update(l, r, c, mid + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}

//求加和
int sum(int l, int r, int s, int t, int p)
{
    if(l > t || r < s) return 0;
    if(l <= s && t <= r)
    {
        return d[p];
    }
    int mid = s + (t - s) / 2;
    push_down(p, s, t);
    int ans = 0;
    if(l <= mid) ans += sum(l, r, s, mid, p * 2);
    if(r > mid) ans += sum(l, r, mid + 1, t, p * 2 + 1);
    return ans;
}

void solve()
{
    cin >> n >> m;
    a.assign(n + 1 ,0);
    d.assign(4 * n + 1, 0);
    b.assign(4 * n + 1, 0);

    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1, n, 1);

    while(m--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << sum(l, r, 1, n, 1) << endl;
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            update(l, r, x, 1, n, 1);
        }
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

[前缀和](/posts/acm-keywords/#prefix) · [差分](/posts/acm-keywords/#difference) · [树状数组](/posts/acm-keywords/#fenwick) · [线段树](/posts/acm-keywords/#segment-tree) · [ST表](/posts/acm-keywords/#sparse-table)

- [前缀，差分](/posts/acm-018da06c2817/)
- [1树状数组（范围查询，单点修改）](/posts/acm-1b60614dae05/)
- [树上差分](/posts/acm-181d67d85ef4/)
- [3树状数组（范围查询，范围修改）](/posts/acm-9a6738cce8bd/)
- [2线段树加法和乘法](/posts/acm-2091698e6dfc/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-d8256bf91c8f.cpp)
