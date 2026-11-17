---
title: "STL priority（排序优化）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器"]
description: "优先队列始终提供当前优先级最高的元素。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

[优先队列](/posts/acm-keywords/#heap)始终提供当前优先级最高的元素。

## 使用前提与[复杂度](/posts/acm-keywords/#complexity)

堆不是完全排好序的数组，默认大顶堆；greater 对应小顶堆。

**[复杂度](/posts/acm-keywords/#complexity)：** top O(1)，push/pop O(log n)。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pque;//默认大顶堆：只能保证堆顶最大，并非所有位置有序
    pque.push(1);
    pque.push(3);
    pque.push(6);
    pque.push(2);
    pque.emplace(8);
    //如果里面是两个，优先排第一个
    cout<<pque.top()<<endl;//输出最大值（最后的）
    pque.pop();//删去最大元素
    priority_queue<int,vector<int>,greater<int>> pque2;//变为小顶堆，所有都与普通的相反，堆顶为最小值
    //其中元素不可修改，只可以操作堆顶
    //储存int类型元素，底层用vector作为容器
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [优先队列](/posts/acm-keywords/#heap) · [复杂度](/posts/acm-keywords/#complexity)

- [Dijkstra](/posts/acm-38c0561d770b/)
- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

