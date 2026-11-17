---
title: "二进制暴力组合数组的数"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","学习实现"]
description: "二进制掩码枚举法\r 二进制掩码枚举是一种通过二进制数的位状态来表示 “选取 / 不选取” 的暴力枚举方法，\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

二进制掩码枚举法 二进制掩码枚举是一种通过二进制数的位状态来表示 “选取 / 不选取” 的暴力枚举方法，

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

二进制掩码枚举法
二进制掩码枚举是一种通过二进制数的位状态来表示 “选取 / 不选取” 的暴力枚举方法，
核心是用二进制数的每一位对应原始序列中元素的选取状态。
假设原始序列有n个元素（字符串，数组），我们需要枚举所有可能的子序列（包含空序列）
用一个 n 位的二进制数（称为“掩码”，mask）表示选举规则：
* 掩码的第i位为1  就选第i个元素，加入子序列
范围限制
时间复杂度 O(n * 2^n)
空间复杂度O(n)
一般可使用范围为 n <= 20

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
二进制掩码枚举法
二进制掩码枚举是一种通过二进制数的位状态来表示 “选取 / 不选取” 的暴力枚举方法，
核心是用二进制数的每一位对应原始序列中元素的选取状态。

假设原始序列有n个元素（字符串，数组），我们需要枚举所有可能的子序列（包含空序列）
用一个 n 位的二进制数（称为“掩码”，mask）表示选举规则：
* 掩码的第i位为1  就选第i个元素，加入子序列

范围限制
时间复杂度 O(n * 2^n)
空间复杂度O(n)
一般可使用范围为 n <= 20
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
    string s;
    cin >> s;
    int ok=0;
    for(int i=0;i < (1 << n);i++)  // 最大范围是2^n
    {
        string m1,m2;
        vector<int> a;
        for(int j=0;j<n;j++)
        {
            if(i & (1 << j))
            {
                m1 += s[j];
                a.push_back(j+1);
            }
            else{
                m2 += s[j];
            }
        }
        int ok1=1;         // 后面是检测规则
        for(int i=1;i<m1.size();i++)
        {
            if(m1[i] < m1[i-1])
            {
                ok1=0;
                break;
            }
        }
        if(!ok1) continue;
        if(m2 == string(m2.rbegin(),m2.rend()))
        {
            cout<<a.size()<<endl;
            for(int i=0;i<a.size();i++)
            {
                cout<<a[i]<<" ";
            }
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        cout<<"-1";
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
- [离散化天际线](/posts/acm-eed522332a27/)
- [1普通莫队](/posts/acm-ec9347e15883/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-decba90bda9a.cpp)
