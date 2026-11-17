---
title: "6菱形继承"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "菱形继承，又叫钻石继承"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

菱形继承，又叫钻石继承

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

菱形继承，又叫钻石继承

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
菱形继承，又叫钻石继承
*/
#include<bits/stdc++.h>
using namespace std;

class animal
{
public:

    int a = 10;

};
//利用虚继承 解决菱形继承问题
//加上virtual 后animal被称为虚基类
//底层是将继承两个数据改为两个指针，sheep和tuo对yt传下去的是两个指针，他们对应一个数据
class sheep : virtual public animal
{

};

class tuo : virtual public animal
{};

class yt : public sheep , public tuo
{};

void text01()
{
    yt k;
    //这份数据 只需要一份就可以 但是菱形数据有两份 浪费资源
    
    k.sheep::a = 18;
    k.tuo::a = 28;
    cout << k.sheep::a << endl << k.tuo :: a << endl << k.a << endl;
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

