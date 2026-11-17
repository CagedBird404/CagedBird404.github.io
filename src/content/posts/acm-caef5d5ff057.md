---
title: "STL map"
published: 2026-11-16
category: ACM竞赛模板
tags: ["STL与常用容器"]
description: "有序键值映射，也可用来统计词频。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

有序键值映射，也可用来统计词频。

## 使用前提与[复杂度](/posts/acm-keywords/#complexity)

operator[] 对不存在的键会插入默认值；C++17 使用 find，contains 需要 C++20。

**[复杂度](/posts/acm-keywords/#complexity)：** 查找、插入、按键删除 O(log n)。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    map<string, int> frequency;
    vector<string> words{"app", "app", "vcr"};
    for (const string& word : words) ++frequency[word];
    if (frequency.find("app") != frequency.end()) cout << frequency.at("app") << '\n';
    for (const auto& [word, count] : frequency) cout << word << ' ' << count << '\n';
}
```

## 相关知识点

[迭代器](/posts/acm-keywords/#iterator) · [优先队列](/posts/acm-keywords/#heap) · [复杂度](/posts/acm-keywords/#complexity)

- [STL priority（排序优化）](/posts/acm-a4adadab1a7a/)
- [Dijkstra](/posts/acm-38c0561d770b/)
- [STL 迭代器](/posts/acm-89b5bc55087e/)
- [STL vector](/posts/acm-e019318b825d/)
- [板子简洁版](/posts/acm-32e5ca0175a7/)

