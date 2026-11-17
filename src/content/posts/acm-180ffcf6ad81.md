---
title: "STL stack"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器"]
description: "栈遵循后进先出，用 top 查看栈顶。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

栈遵循后进先出，用 top 查看栈顶。

## 使用前提与[复杂度](/posts/acm-keywords/#complexity)

pop 不返回元素；需要先 top 再 pop。用 empty() 判断栈是否为空。

**[复杂度](/posts/acm-keywords/#complexity)：** push、pop、top 通常 O(1)。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    stack<double> values;
    values.push(1.0); values.push(1.4);
    while (!values.empty()) {
        cout << values.top() << '\n'; values.pop();
    }
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [优先队列](/posts/acm-keywords/#heap) · [复杂度](/posts/acm-keywords/#complexity)

- [STL priority（排序优化）](/posts/acm-a4adadab1a7a/)
- [Dijkstra](/posts/acm-38c0561d770b/)
- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)

