---
title: "最长上升公共子序列"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划","学习实现"]
description: "用于找最长公共上升子序列\r 时间复杂度O(nm)"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

用于找最长公共上升子序列 时间复杂度O(nm)

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

用于找最长公共上升子序列
时间复杂度O(n*m)

> **易错点：** 长度 DP 与序列重建应分开验证。原前驱索引会随后续更新改变，直接回溯可能不对应当时的最优链。空数组还需要特殊处理。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
用于找最长公共上升子序列

时间复杂度O(n*m)
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
    cin >> n ;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i = 0;i < m;i++) cin >> b[i];
    vector<int> dp(m),k(m,-1);   //dp[j]记录的是对于b数组以b[j]为结尾时
    for(int i = 0;i < n;i++)     //他的最大公共上升子区间长度
    {                            //k记录他的前驱元素，便于去回溯寻找整个序列
        int l = 0;//最大长度
        int num = -1;//前驱元素
        for(int j = 0;j < m;j++)
        {
            if(a[i] == b[j])  //关键限制，因为只能是相同的元素，所以只有相等
            {                 //的时候才对他加一
                if(dp[j] < l + 1)   //限制：只对于大于当前最佳长度的进行更新
                {
                    dp[j] = l + 1;
                    k[j] = num; //更新前置元素
                }
            }
            if(b[j] < a[i])  //对于比他小的b元素，如果dp[j]的长度比他大，那么就把最佳长度更新
            {                //并且更新前置
                if(dp[j] > l)
                {
                    l = dp[j];
                    num = j;
                }
            }
        }
    }
    int num = max_element(all(dp)) - dp.begin();
    int ans = dp[num];
    vector<int> pp;
    while(num != -1)
    {
        pp.emplace_back(b[num]);
        num = k[num];
    }
    reverse(all(pp));
    cout << ans << endl; if(ans == 0) return;
    for(auto gg : pp)
    {
        cout << gg << " ";
    }
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

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-2e8a4d2cc700.cpp)
