---
title: "4继承中同名的成员处理方式"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "对于子类和父类同名的成员\r     子类成员直接访问就可以\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

对于子类和父类同名的成员     子类成员直接访问就可以

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

对于子类和父类同名的成员
子类成员直接访问就可以
父类成员要加作用域

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
对于子类和父类同名的成员
    子类成员直接访问就可以
    父类成员要加作用域
*/

/*
对于静态成员也是同理
*/
#include<bits/stdc++.h>
using namespace std;

class base
{
public:

    int a;

    void te()
    {
        cout << 1 << endl;
    }
//子类会隐藏所有父类同名的成员函数，即使你用了重载，都必须加作用域
    void te(int )
    {
        cout << 3;
    }
    base()
    {
        a = 100;
    }

};

class son : public base
{
public:

    int a;

    void te()
    {
        cout << 2 << endl;
    }
    son()
    {
        a = 200;
    }
};

void text01()
{
    son s;
    cout << s.a << endl;
    cout << s.base::a << endl;
    s.te();
    s.base::te();
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

