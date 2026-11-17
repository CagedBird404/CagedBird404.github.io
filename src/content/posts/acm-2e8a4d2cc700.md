---
title: "最长上升公共子序列"
published: 2026-11-16
category: ACM竞赛模板
tags: ["动态规划"]
description: "用于找最长公共上升子序列\r 时间复杂度O(nm)"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

用于找最长公共上升子序列 时间复杂度O(nm)

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

用于找最长公共上升子序列
时间复杂度O(n*m)

> **使用时我会注意：** 长度 DP 与序列重建应分开验证。这里的前驱索引会随后续更新改变，直接回溯可能不对应当时的最优链。空数组还需要特殊处理。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

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

