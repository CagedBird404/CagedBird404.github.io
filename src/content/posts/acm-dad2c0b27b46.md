---
title: "深化-斐波那契"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法·搜索与分治","学习实现"]
description: "深化-斐波那契的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

深化-斐波那契的学习实现与使用笔记。

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

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

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-dad2c0b27b46.cpp)
