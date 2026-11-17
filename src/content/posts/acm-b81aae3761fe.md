---
title: "2类做友元"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "2类做友元的学习实现与使用笔记。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

2类做友元的学习实现与使用笔记。

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include<bits/stdc++.h>
using namespace std;

class Building; //类的声明

class goodgay
{
    
public:

    goodgay();
    void visit();

    Building *build;
};

class Building
{
    
    friend class goodgay;

public:

    Building();
    string ke;

private: 
    
    string wo;

};
//类外写成员函数
Building::Building()
{
    ke = "keting";
    wo = "woshi";
}

goodgay::goodgay()
{
    build = new Building;//类内的指针都要开辟新空间
}

void goodgay::visit()
{
    cout << "fangwen: " << build -> ke << endl;
    cout << "fangwen: " << build -> wo << endl;
}

void text01()
{
    goodgay p1;
    p1.visit();
}

int main(){
    text01();
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

