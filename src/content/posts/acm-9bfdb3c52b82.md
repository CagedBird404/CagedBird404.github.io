---
title: "6菱形继承"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充","学习实现"]
description: "菱形继承，又叫钻石继承"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

菱形继承，又叫钻石继承

## 使用说明

这是原有学习代码的整理版。先查看下方代码中的输入输出和变量约定；题目专用实现不自动等同于通用模板。

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

## 整理记录

保留原实现和主要注释，统一输入流初始化及文章排版；语法检查与算法正确性验证分开记录。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-9bfdb3c52b82.cpp)
