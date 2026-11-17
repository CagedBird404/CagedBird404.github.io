---
title: "STL pair"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器"]
description: "把两个值组合在一起，支持字典序比较。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

把两个值组合在一起，支持字典序比较。

## 使用前提与[复杂度](/posts/acm-keywords/#complexity)

默认先比较 first，相等再比较 second；从 map 转成 vector 后可按值排序。

**[复杂度](/posts/acm-keywords/#complexity)：** 访问 O(1)，排序 n 个 pair 为 O(n log n)。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    pair<int, int> point{1, 2};
    cout << point.first << ' ' << point.second << '\n';
    map<int, int> mapping{{1, 9}, {2, 3}};
    vector<pair<int, int>> values(mapping.begin(), mapping.end());
    sort(values.begin(), values.end(), [](const auto& a, const auto& b) {
        return tie(a.second, a.first) < tie(b.second, b.first);
    });
    for (auto [key, value] : values) cout << key << ' ' << value << '\n';
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [优先队列](/posts/acm-keywords/#heap) · [复杂度](/posts/acm-keywords/#complexity)

- [STL priority（排序优化）](/posts/acm-a4adadab1a7a/)
- [Dijkstra](/posts/acm-38c0561d770b/)
- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)

