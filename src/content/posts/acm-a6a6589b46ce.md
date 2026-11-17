---
title: "移动窗口"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "移动窗口的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

移动窗口的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

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

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-a6a6589b46ce.cpp)
