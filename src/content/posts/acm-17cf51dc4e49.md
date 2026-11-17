---
title: "后缀自动机"
published: 2026-11-16
category: ACM竞赛模板
tags: ["字符串","已修订"]
description: "构造后缀自动机，统计字符串不同非空子串个数。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

构造[后缀自动机](/posts/acm-keywords/#sam)，统计字符串不同非空子串个数。

## 使用前提与复杂度

原文件其实是随机异或哈希，并非[后缀自动机](/posts/acm-keywords/#sam)；原实现保留在源码归档。本补全适用于小写英文字母。

**复杂度：** 固定字母表下 O(n) 时间与空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SuffixAutomaton {
    struct State { array<int, 26> next{}; int link = -1, length = 0; };
    vector<State> states{State{}};
    int last = 0;
    void extend(char ch) {
        int c = ch - 'a';
        int current = (int)states.size(); states.push_back(State{});
        states[current].length = states[last].length + 1;
        int p = last;
        while (p != -1 && !states[p].next[c]) {
            states[p].next[c] = current; p = states[p].link;
        }
        if (p == -1) states[current].link = 0;
        else {
            int q = states[p].next[c];
            if (states[p].length + 1 == states[q].length) states[current].link = q;
            else {
                int clone = (int)states.size(); states.push_back(states[q]);
                states[clone].length = states[p].length + 1;
                while (p != -1 && states[p].next[c] == q) {
                    states[p].next[c] = clone; p = states[p].link;
                }
                states[q].link = states[current].link = clone;
            }
        }
        last = current;
    }
    i64 distinctSubstrings() const {
        i64 answer = 0;
        for (int i = 1; i < (int)states.size(); ++i)
            answer += states[i].length - states[states[i].link].length;
        return answer;
    }
};
```

## 相关知识点

[KMP](/posts/acm-keywords/#kmp) · [Trie](/posts/acm-keywords/#trie) · [字符串哈希](/posts/acm-keywords/#hash) · [后缀自动机](/posts/acm-keywords/#sam)

- [KMp算法字符串](/posts/acm-e8086e7e153a/)
- [AC自动机](/posts/acm-774260652a67/)
- [哈希前缀字符串双](/posts/acm-c3a6c2d6240d/)
- [最小表示法](/posts/acm-0bd63d098ff8/)

## 整理记录

本次对代码进行了修订或补全：原文件其实是随机异或哈希，并非[后缀自动机](/posts/acm-keywords/#sam)；原实现保留在源码归档。本补全适用于小写英文字母。

[查看原始源码](https://github.com/CagedBird404/CagedBird404.github.io/blob/main/study/acm/original/acm-17cf51dc4e49.cpp)
