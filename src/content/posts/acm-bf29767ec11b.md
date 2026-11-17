---
title: "STL set（去重）"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器"]
description: "STL set（去重）的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

STL set（去重）的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include<bits/stdc++.h>//可以用来去重，排序
using namespace std;//set中一个元素在集合中只能出现一次，multiset中可以出现多次，两个都会从小到大排好序
int main(){
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(0);
    st.erase(2);//删除
    st.find(1);//寻找元素
    st.count(2);//查询有几个，set中返回值只有两个1或0
    if(st.count(1))
    {
        cout<<"yes"<<endl;
    };
    cout<<st.size()<<endl;
    //st.clear();//清空
    cout<<st.empty()<<endl;
    for(auto&&i:st)
    {
        cout<<i<<endl;
    };
    //迭代器进行遍历
    for(set<int>::iterator it=st.begin();it!=st.end();++it)
    {
        cout<<*it<<endl;
    };
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [优先队列](/posts/acm-keywords/#heap) · [复杂度](/posts/acm-keywords/#complexity)

- [STL priority（排序优化）](/posts/acm-a4adadab1a7a/)
- [Dijkstra](/posts/acm-38c0561d770b/)
- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)

