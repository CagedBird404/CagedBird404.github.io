---
title: "二进制小问题"
published: 2026-11-16
category: ACM竞赛模板
tags: ["基础算法","已修订"]
description: "从高位到低位读取整数二进制位。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

从高位到低位读取整数二进制位。

## 使用前提与复杂度

不再用有优先级错误的 1 << i <= x；使用无符号类型且 bits∈[0,64]。

**复杂度：** O(bits) 时间，O(bits) 输出空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

string binaryDigits(unsigned long long x, int bits) {
    string result;
    for (int i = bits - 1; i >= 0; --i) result += char('0' + ((x >> i) & 1ULL));
    return result;
}
```

## 相关知识点

[二分查找](/posts/acm-keywords/#binary-search) · [状态压缩](/posts/acm-keywords/#bitmask) · [离散化](/posts/acm-keywords/#discretization)

- [最长上升子序列](/posts/acm-30bcfb439008/)
- [ST表](/posts/acm-227c4f00c3c6/)
- [状压dp](/posts/acm-48022e812913/)
- [二进制暴力组合数组的数](/posts/acm-decba90bda9a/)
- [离散化天际线](/posts/acm-eed522332a27/)

## 整理记录

本次对代码进行了修订或补全：不再用有优先级错误的 1 << i <= x；使用无符号类型且 bits∈[0,64]。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-cff4939f14aa.cpp)
