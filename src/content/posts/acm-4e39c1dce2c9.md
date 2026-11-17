---
title: "分治 静态区间子区间最大和"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治","学习实现"]
description: "分治 静态区间子区间最大和的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

分治 静态区间子区间最大和的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

> 原代码保留了 `#define int long long` 的写法；它会替换所有后续 int，可能改变接口与内存占用。独立复用时更建议用 `using i64 = long long` 并显式选择类型。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h> 
using namespace std;
#define int long long                 
#define endl '\n'                     
#define all(x) (x).begin(), (x).end() 

constexpr int MOD = 1e9 + 7;

int fz(int l,int r,vector<int> &a)
{
    if(l==r)
    {
        return a[l];
    }
    int mid=l + (r - l)/2;
    int lmax=fz(l,mid,a);//不断细分，最后返回左边最大值
    int rmax=fz(mid+1,r,a);//返回右边最大值
    vector<int> L(mid-l+1);
    vector<int> R(r-mid);
    //一共三种情况，在左边，在右边，拼接，如果是拼接那就一定左加右大于单独的左和右，最后输出他仨最大的就行
    for(int i=0;i<mid-l+1;i++) L[i]=a[i+l];
    for(int j=0;j<r-mid;j++) R[j]=a[j+mid+1];
    int Max1=LLONG_MIN,Max2=LLONG_MIN,Max3=LLONG_MIN,Max=LLONG_MIN;
    for(int i=(mid-l);i>=0;i--)//后缀和处理，和前缀和一样，结果不影响，目的是和右半部分的前缀和组合，能拼接
    {
        int f=0;
        f+=L[i];
        Max1=max(Max1,f);//类似dp的寻找最大值
    }
    for(int i=0;i<(r-mid);i++)
    {
        int e=0;
        e+=R[i];
        Max2=max(Max2,e);
    }
    Max3=Max1+Max2;
    Max=max({Max3,lmax,rmax});
    return Max;
}


void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>> l >> r;
        cout<<fz(l,r,a)<<endl;
    }
}
//将每组测试用例的处理逻辑写在里面

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

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-4e39c1dce2c9.cpp)
