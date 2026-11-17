---
title: "归并排序"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "时间复杂度nlogn;\r 总的来说就是让左面排好序右面排好序，在归到一起\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

时间复杂度nlogn; 总的来说就是让左面排好序右面排好序，在归到一起

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

时间复杂度nlogn;
总的来说就是让左面排好序右面排好序，在归到一起
先将他归并到最小，再两两合并，其中每个数都不会重复计算
因为你从虽小上来的，所以进行操作的每两个都是有序的、
就可以用双指针进行排序，排序后再覆盖到原数组对应的位置上
也正是因为是将其分成多个区间计算，所以在进行逆序对计算时就不会往后找
而且分的精细，所以也不会缺失

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
时间复杂度nlogn;

总的来说就是让左面排好序右面排好序，在归到一起

先将他归并到最小，再两两合并，其中每个数都不会重复计算
因为你从虽小上来的，所以进行操作的每两个都是有序的、
就可以用双指针进行排序，排序后再覆盖到原数组对应的位置上

也正是因为是将其分成多个区间计算，所以在进行逆序对计算时就不会往后找
而且分的精细，所以也不会缺失
*/

#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

vector<int> a, b;

void gb(int l, int r)
{
    if(l == r) return;
    int mid = l + (r - l) / 2;
    gb(l, mid);
    gb(mid + 1, r);
    int i = l;
    int j = mid + 1;
    int t = l;
    while(i <= mid && j <= r)
    {
        if(a[i] < a[j])
        {
            b[t++] = a[i];
            i++;
        }
        else{
            b[t++] = a[j];
            j++;
        }
    }
    while(i <= mid) b[t++] = a[i++];
    while(j <= r) b[t++] = a[j++];
    for(int k = l; k <= r; k++) a[k] = b[k];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            for(int i = 0;i )
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

[二分查找](/posts/acm-keywords/#binary-search) · [状态压缩](/posts/acm-keywords/#bitmask) · [离散化](/posts/acm-keywords/#discretization)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)
- [离散化天际线](/posts/acm-eed522332a27/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-23db3f18f06d.cpp)
