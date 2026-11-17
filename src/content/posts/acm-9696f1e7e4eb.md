---
title: "最大连续子区间去掉最大值"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划"]
description: "对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值\r 因为对于最大值减去的情况有太多\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值 因为对于最大值减去的情况有太多

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值
因为对于最大值减去的情况有太多
那么就可以将最大值定死

> **使用时我会注意：** 枚举最大值只覆盖 −30..30；必须确认题目中的元素范围，否则会漏解。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
对于一堆数，找到他的连续子区间的 和 减去 最大值 所得到的 最大值
因为对于最大值减去的情况有太多
那么就可以将最大值定死
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
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    int ans = LLONG_MIN;
    for(int k = -30;k <= 30;k++)
    {
        int ok = 0;
        int sum = 0;
        for(int i = 0;i < n;i++)
        {
            if(a[i] > k)
            {
                if(ok) ans = max(ans,sum - k);
                sum = 0;
                ok = 0;
            }
            else{
                if(sum < 0) sum = 0;sum += a[i];
                if(a[i] == k) ok = 1;
                if(ok) ans = max(ans,sum - k);
            }
        }
    }
    cout << max(ans,0ll);
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

[动态规划](/posts/acm-keywords/#dp) · [状态压缩](/posts/acm-keywords/#bitmask) · [二分查找](/posts/acm-keywords/#binary-search)

- [01背包问题](/posts/acm-b56927a13e82/)
- [数位dp](/posts/acm-927f6f82d7ce/)
- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)

