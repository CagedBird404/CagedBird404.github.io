---
title: "深化-斐波那契"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治"]
description: "深化-斐波那契的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

深化-斐波那契的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include<bits/stdc++.h>   //记忆化搜索
using namespace std;
int n;vector<int> saved(n+1,-1);
//进行优化，他会有很多分支，
int f(int n){           //计算很多重复数据，太慢，
    if(n<=2)            //将其保存，再调用，会快很多
    {                   //最后输出保存的数据就行
        return 1;
    }
    if(saved[n]==-1)
    {
        saved[n]=f(n-1)+f(n-2);
    }
    return saved[n];
}
int main(){
cin>> n;saved = vector<int> (n+1,-1);
cout<<f(n);
}
```

## 相关知识点

[DFS](/posts/acm-keywords/#dfs) · [BFS](/posts/acm-keywords/#bfs) · [二分查找](/posts/acm-keywords/#binary-search)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [Tarjan](/posts/acm-18decad757c7/)
- [树型dp](/posts/acm-cde7944003fd/)
- [bfs 多源找最近最大值](/posts/acm-addc6cc81933/)

