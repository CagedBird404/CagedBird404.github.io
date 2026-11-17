---
title: "归并排序"
published: 2026-11-16
category: ACM竞赛模板
tags: ["已修订","基础算法","学习实现"]
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
#include <bits/stdc++.h>
using namespace std;
void mergeSort(vector<long long>& a) {
    vector<long long> buffer(a.size());
    function<void(int,int)> sortRange = [&](int l,int r) {
        if (r-l <= 1) return;
        int mid=l+(r-l)/2;
        sortRange(l,mid);sortRange(mid,r);
        int i=l,j=mid,k=l;
        while(i<mid && j<r) buffer[k++]=a[i]<=a[j]?a[i++]:a[j++];
        while(i<mid) buffer[k++]=a[i++];
        while(j<r) buffer[k++]=a[j++];
        copy(buffer.begin()+l,buffer.begin()+r,a.begin()+l);
    };
    sortRange(0,(int)a.size());
}
// O(n log n) 时间，O(n) 额外空间。
```

## 相关知识点

[二分查找](/posts/acm-keywords/#binary-search) · [状态压缩](/posts/acm-keywords/#bitmask) · [离散化](/posts/acm-keywords/#discretization)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)
- [离散化天际线](/posts/acm-eed522332a27/)

## 整理记录

**本次修正：** 补全归并排序，移除不相关草稿；左闭右开区间支持空数组，相等元素先取左边。

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-23db3f18f06d.cpp)
