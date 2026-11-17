---
title: "2继承方式"
published: 2026-11-16
category: ACM竞赛模板
tags: ["C++基础补充"]
description: "三种方式：\r     公共继承\r"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

三种方式：     公共继承

## 使用说明

这里记录我的实现和理解。使用时，我会先确认输入输出、下标和数据范围，再按具体题目调整。

三种方式：
公共继承
保护继承
私有继承
对于父类的private的数据无论哪种方式都不能访问
对于共有继承，会将父类的数据和访问权限不变的继承下来，
保护继承会将父类的public变成protect
私有继承会将其变成private

<!-- ACM_VALIDATION -->

## 代码

```cpp
/*
三种方式：
    公共继承
    保护继承
    私有继承

对于父类的private的数据无论哪种方式都不能访问

对于共有继承，会将父类的数据和访问权限不变的继承下来，
保护继承会将父类的public变成protect
私有继承会将其变成private
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
    
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [复杂度](/posts/acm-keywords/#complexity)

- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)
- [01背包问题](/posts/acm-b56927a13e82/)

