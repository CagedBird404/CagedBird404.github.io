---
title: "移动窗口"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法"]
description: "移动窗口的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

移动窗口的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
 
constexpr int MOD = 1e9 + 7;
// -9.2e18 ~ 9.2e18
//链接：https://ac.nowcoder.com/acm/contest/92182/K来源：牛客网有

 
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
 
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < n and v[j] - v[i] <= k)
        {
            j++;
        }    //移动窗口，比二分快，
        auto m = j - i;
        ans = max(ans, m);
    }
 
    cout << ans * 1.0 / n;
}
 
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setiosflags(ios::fixed) << setprecision(4);
    int TT = 1;
    // cin >> TT;
    while (TT--)
    {
        solve();
        // cout << endl;
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

