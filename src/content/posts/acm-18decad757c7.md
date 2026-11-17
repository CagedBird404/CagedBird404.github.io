---
title: "Tarjan"
published: 2026-11-16
category: ACM竞赛模板
tags: ["图论·连通性"]
description: "用 DFS 栈求有向图强连通分量。"
pinned: false
---

[返回 ACM竞赛模板目录](/posts/acm-index/) · [知识点速查](/posts/acm-keywords/)

## 用途与思路

用 DFS 栈求有向图[强连通分量](/posts/acm-keywords/#scc)。

## 使用前提与复杂度

图用 0..n−1 编号。low 与 dfn 含义不同；只对仍在栈中的已访问节点更新 dfn。深链可能导致递归栈溢出。

**复杂度：** O(n+m) 时间，O(n+m) 空间。

<!-- ACM_VALIDATION -->

## 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> stronglyConnectedComponents(const vector<vector<int>>& graph) {
    int n = (int)graph.size(), timer = 0, count = 0;
    vector<int> dfn(n), low(n), stack, component(n, -1);
    vector<bool> inStack(n);
    function<void(int)> dfs = [&](int u) {
        dfn[u] = low[u] = ++timer;
        stack.push_back(u); inStack[u] = true;
        for (int v : graph[u]) {
            if (!dfn[v]) { dfs(v); low[u] = min(low[u], low[v]); }
            else if (inStack[v]) low[u] = min(low[u], dfn[v]);
        }
        if (low[u] == dfn[u]) {
            while (true) {
                int v = stack.back(); stack.pop_back();
                inStack[v] = false; component[v] = count;
                if (v == u) break;
            }
            ++count;
        }
    };
    for (int u = 0; u < n; ++u) if (!dfn[u]) dfs(u);
    return component;
}
```

## 相关知识点

[强连通分量](/posts/acm-keywords/#scc) · [拓扑排序](/posts/acm-keywords/#topological) · [DFS](/posts/acm-keywords/#dfs)

- [树型dp](/posts/acm-cde7944003fd/)
- [P_4017_最大食物链(拓扑排序)](/posts/acm-bb016f9e4308/)
- [期望dp](/posts/acm-95f75c628fe0/)
- [2-sat问题](/posts/acm-921f68f2aebd/)

