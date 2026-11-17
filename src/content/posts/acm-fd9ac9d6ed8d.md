---
title: "栈"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "维护一个单调的队列，去解决问题\r 例如经典题，求当前位置左面或者右面第一个大于或者小于的数的下标\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

维护一个单调的队列，去解决问题 例如经典题，求当前位置左面或者右面第一个大于或者小于的数的下标

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

维护一个单调的队列，去解决问题
例如经典题，求当前位置左面或者右面第一个大于或者小于的数的下标
下面是求每个数，左面第一个小于他的和右面第一个小于他的,数字里面有重复的，要求严格小于
时间[复杂度](/posts/acm-keywords/#complexity)On

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
维护一个单调的队列，去解决问题
例如经典题，求当前位置左面或者右面第一个大于或者小于的数的下标

下面是求每个数，左面第一个小于他的和右面第一个小于他的,数字里面有重复的，要求严格小于

时间复杂度On
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
    for(int i = 0; i < n;i++) cin >> a[i];
    vector<pair<int,int>> ans(n);
    stack<int> st;
    for(int i = 0;i < n;i++)
    {
        while(!st.empty() && a[st.top()] >= a[i])
        {
            auto k = st.top();
            st.pop();
            if(!st.empty())ans[k].first = st.top();
            else ans[k].first = -1;
            ans[k].second = i;
        }
        st.push(i);
    }
    while(!st.empty())
    {
        auto k = st.top();
        st.pop();
        if(!st.empty())ans[k].first = st.top();
        else ans[k].first = -1;
        ans[k].second = -1; 
    }
    for(int i = n - 2;i >= 0;i--)
    {
        while(ans[i].second != -1 && a[ans[i].second] == a[i])
        {
            ans[i].second = ans[ans[i].second].second;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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

[复杂度](/posts/acm-keywords/#complexity)

- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-fd9ac9d6ed8d.cpp)
