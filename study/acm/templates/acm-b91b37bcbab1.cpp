#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 dependencyKnapsack(int capacity, const vector<int>& parent,
                       const vector<int>& cost, const vector<i64>& value) {
    int n = (int)parent.size() - 1;
    vector<vector<int>> children(n + 1);
    for (int i = 1; i <= n; ++i) children[parent[i]].push_back(i);
    const i64 NEG = -(1LL << 60);
    function<vector<i64>(int)> dfs = [&](int u) {
        vector<i64> dp(capacity + 1, NEG);
        int c = u == 0 ? 0 : cost[u];
        if (c > capacity) return dp;
        dp[c] = u == 0 ? 0 : value[u];
        for (int v : children[u]) {
            auto sub = dfs(v);
            auto next = dp;  // 可以不选这个子树。
            for (int a = c; a <= capacity; ++a) if (dp[a] != NEG)
                for (int b = 0; a + b <= capacity; ++b) if (sub[b] != NEG)
                    next[a + b] = max(next[a + b], dp[a] + sub[b]);
            dp.swap(next);
        }
        return dp;
    };
    auto dp = dfs(0);
    return *max_element(dp.begin(), dp.end());
}
