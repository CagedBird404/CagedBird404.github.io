---
title: "3继承中的对象模型"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "对于析构和构造函数\r 顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于析构和构造函数 顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

对于析构和构造函数
顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
对于析构和构造函数
顺序是： 父类构造 -> 子类构造 -> 子类析构 -> 父类析构
*/

#include<bits/stdc++.h>
using namespace std;

//继承中的对象模型
class base
{
public:

    int a;

protected:

    int b;

private:

    int c;
};
//对象中的私有也会继承到子类中，占内存
//父类中所有非静态成员属性都会被继承到子类
//父类中私有成员属性 只是被编译器隐藏了，不能访问但是被继承下去了

class son:public base
{
public:

    int d;
};

void text01()
{
    son k;
    cout << sizeof(k) << endl;
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

