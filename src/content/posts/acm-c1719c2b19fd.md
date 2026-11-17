---
title: "题"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法"]
description: "题的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

题的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

> **使用时我会注意：** 这是交互题草稿，缺少题面、查询次数限制和交互器，不能当作通用模板或宣称正确。

> 我在这份代码里用了 `#define int long long`。使用时要留意它对接口和内存的影响；也可以改用 `using i64 = long long`，显式选择需要的整数类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
//#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int num;
    cout << "? 1 1" <<endl;
    cin >> num;
    vector<pair<int ,int>> a;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            cout << "? " << i <<" " << j <<endl;
            int nu;
            cin >> nu;
            if(nu == num + 1)
            {
                a.push_back({i, j});
            }
            else{
                 cout << "? " << i <<" " << j <<endl;
                cin >> nu;
            }
        }
    }
    vector<int> b( n + 1);
    for(int i = 1;i <= n;i++) b[i] = i;
    reverse(all(a));
    for(int i = 0;i < a.size();i++)
    {
        swap(b[a[i].second], b[a[i].first]);
    }
    cout <<"! " ;
    for(int i = 1;i <= n;i++) cout << b[i] << " ";
}

signed main()
{
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);                
    cout << setiosflags(ios::fixed) << setprecision(2); 
    int TT = 1;
    cin >> TT; 
    while (TT--)
    {
        solve(); 
        //cout << endl;
    }
}
```

## 相关知识点

[复杂度](/posts/acm-keywords/#complexity)

- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

