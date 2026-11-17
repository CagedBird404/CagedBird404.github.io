---
title: "归并排序（逆序对）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法"]
description: "逆序对就是i < j && a[i] > a[j] 有多少对"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

逆序对就是i < j && a[i] > a[j] 有多少对

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

逆序对就是i < j && a[i] > a[j] 有多少对

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

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

