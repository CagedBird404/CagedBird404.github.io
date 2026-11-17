#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Edge { int from, to; i64 weight; };
optional<vector<vector<i64>>> johnson(int n, const vector<Edge>& edges) {
    const i64 INF = (1LL << 60);
    vector<i64> h(n, 0);  // 等价于超级源点向所有节点连 0 边。
    for (int round = 0; round < n; ++round) {
        bool changed = false;
        for (const auto& e : edges) if (h[e.to] > h[e.from] + e.weight) {
            h[e.to] = h[e.from] + e.weight; changed = true;
        }
        if (!changed) break;
        if (round == n - 1) return nullopt;
    }
    vector<vector<pair<int, i64>>> g(n);
    for (const auto& e : edges) g[e.from].push_back({e.to, e.weight + h[e.from] - h[e.to]});
    vector<vector<i64>> result(n, vector<i64>(n, INF));
    for (int source = 0; source < n; ++source) {
        auto& d = result[source]; d[source] = 0;
        priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> q;
        q.push({0, source});
        while (!q.empty()) {
            auto [distance, u] = q.top(); q.pop();
            if (distance != d[u]) continue;
            for (auto [v, w] : g[u]) if (d[v] > d[u] + w) {
                d[v] = d[u] + w; q.push({d[v], v});
            }
        }
        for (int v = 0; v < n; ++v) if (d[v] != INF) d[v] += h[v] - h[source];
    }
    return result;
}
