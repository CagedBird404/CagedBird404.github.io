#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<double> dagExpectedSteps(const vector<vector<int>>& g) {
    int n = (int)g.size();
    vector<int> indegree(n), order;
    for (const auto& edges : g) for (int v : edges) ++indegree[v];
    queue<int> q;
    for (int u = 0; u < n; ++u) if (!indegree[u]) q.push(u);
    while (!q.empty()) {
        int u = q.front(); q.pop(); order.push_back(u);
        for (int v : g[u]) if (--indegree[v] == 0) q.push(v);
    }
    if ((int)order.size() != n) throw invalid_argument("graph must be a DAG");
    vector<double> expectation(n);
    reverse(order.begin(), order.end());
    for (int u : order) if (!g[u].empty()) {
        for (int v : g[u]) expectation[u] += expectation[v];
        expectation[u] = 1.0 + expectation[u] / g[u].size();
    }
    return expectation;
}
