---
title: "多态基本概念"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "多态分两种：\r     1、静态多态：函数重载 和 运算符重载就属于静态多态，复用函数名\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

多态分两种：     1、静态多态：函数重载 和 运算符重载就属于静态多态，复用函数名

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

多态分两种：
1、静态多态：函数重载 和 运算符重载就属于静态多态，复用函数名
2、动态多态：派生类和虚函数实现运行时多态
静态和动态的区别：
1、静态多态的函数地址早绑定 - 编译阶段确定函数地址
2、动态多态的函数地址晚绑定 - 运行阶段确定函数地址

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
多态分两种：
    1、静态多态：函数重载 和 运算符重载就属于静态多态，复用函数名
    2、动态多态：派生类和虚函数实现运行时多态
静态和动态的区别：
    1、静态多态的函数地址早绑定 - 编译阶段确定函数地址
    2、动态多态的函数地址晚绑定 - 运行阶段确定函数地址
*/
#include<bits/stdc++.h>
using namespace std;

class animal
{
public:

    virtual void speak()
    {
        cout << "animal is speak" << endl;
    }

};

class mao : public animal
{
public:

    void speak()
    {
        cout << "mao is speak" << endl;
    }

};

void dod(mao &k,animal &k1)//父子的指针可以共用,所以子类的可以传到父类里
{
    k.speak();
    k.mao::speak();
    k.speak();
    k1.speak();//函数里面变量是父类时什么，只执行父的
                //将父类的同名函数变成虚函数，就可以先让其指向子类的
}

void text01()
{
    mao k;
    mao k1;
    dod(k,k1);
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

