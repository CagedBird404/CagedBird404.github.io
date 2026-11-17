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
