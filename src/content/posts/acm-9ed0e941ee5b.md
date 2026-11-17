---
title: "归并排序（逆序对）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "逆序对就是i < j && a[i] > a[j] 有多少对"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

逆序对就是i < j && a[i] > a[j] 有多少对

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

逆序对就是i < j && a[i] > a[j] 有多少对

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
逆序对就是i < j && a[i] > a[j] 有多少对
*/
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<int> a, b;
int ans = 0;

void gb(int l, int r)
{
    if(l == r) return;
    int mid = l + ( r- l) / 2;
    gb(l, mid);
    gb(mid + 1, r);
    int i = l, j = mid + 1, t = l;
    while(i <= mid && j <= r)
    {
        if(a[i] > a[j])
        {
            b[t++] = a[j++];
            ans += mid - i + 1;
        }
        else{
            b[t++] = a[i++];
        }
    }
    while(i <= mid) b[t++] = a[i++], ans += mid - i + 1;
    while(j <= mid) b[t++] = a[j++];
    for(int k = l;k <= r;k++) a[k] = b[k];
}

void solve()
{
    int n;
    cin >> n;
    a.assign(n,0);
    b.assign(n,0);
    for(int i =0 ;i < n;i++) cin >> a[i];
    gb(0,n-1);
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
        cout << endl;
    }
}
```

## 相关知识点

[二分查找](/posts/acm-keywords/#binary-search) · [状态压缩](/posts/acm-keywords/#bitmask) · [离散化](/posts/acm-keywords/#discretization)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)
- [离散化天际线](/posts/acm-eed522332a27/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-9ed0e941ee5b.cpp)
